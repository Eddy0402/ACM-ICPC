#include<cstdio>
#include<vector>
using namespace std;
vector<vector<int> > possible;
vector<int> col(88888888,1), right(15,1), left(15,1);
void init(vector<int> &finish){
	if(finish.size() == 8){
		possible.push_back(finish);
		return;
	}
	int size = finish.size();
	for(int toTry = 0;toTry < 8 ; ++toTry){
		if(col[toTry] && right[ size + toTry ] && left[ size - toTry + 7 ] ){
				col[toTry]  = 0;
				right[ size + toTry ]  = 0;
				left[ size - toTry + 7 ] = 0;
				finish.push_back(toTry);
			init(finish);
				finish.pop_back();
				col[toTry]  = 1;
				right[ size + toTry ]  = 1;
				left[ size - toTry + 7 ] = 1;
		}
	}
}
int main(){
	int testCases;
	vector<int> a;
	init(a);
	scanf("%d",&testCases);
	while(testCases--){
		int board[8][8];
		for(int row = 0;row < 8; ++row)
			for(int col = 0;col < 8;++col)
				scanf("%d",&board[row][col]);
		int result = 0;
		for(auto one : possible){
			int total = 0;
			for(int row = 0; row < 8; ++row){
				total += board[ row ][ one[row] ];
			}
			if(total > result)result = total;
		}
		printf("%5d\n",result);
	}
	return 0;
}
