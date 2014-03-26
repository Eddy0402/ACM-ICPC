#include<cstdio>
#include<vector>
using namespace std;
const int none = 0,Left=1,Dia=2,Up=3;
int main(){
	int Count,temp;
	scanf("%d",&Count);
	vector<int> Order(Count + 1);
	for(int i = 1;i <= Count;++i){
		scanf("%d",&temp);
		Order[temp] = i;
	}
	while(1){
		vector<int> Numbers(Count + 1);
		for(int i = 1;i <= Count;++i){
			if(scanf("%d",&temp) == EOF)return 0;
			Numbers[temp] = i;
		}
		int LCS[30][30]={},From[30][30]={},result = 0;
		for(int i = 1;i < Order.size();++i){
			for(int j = 1;j < Numbers.size();++j){
				if(Order[i] == Numbers[j]){
					LCS[i][j] = LCS[i-1][j-1] + 1;
					From[i][j] = Dia;
					if(LCS[i][j] > result)result = LCS[i][j];
				}else{
					if(LCS[i-1][j] > LCS [i][j-1]){
						From[i][j] = Left;
						LCS[i][j] = LCS[i-1][j];
					}
					else{
						From[i][j] = Up;
						LCS[i][j] = LCS[i][j-1];
					}
				}
			}
		}
		printf("%d\n",result);
	}
	return 0;
}
