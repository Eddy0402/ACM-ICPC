#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
bool dfs(vector<pair<int,int> >::iterator &blank,vector<pair<int,int> >::iterator &end ,vector<vector<int> >&Rows,int size){
	if(blank == end)return true;
	int A = (*blank).first, B = (*blank).second;
	for(int Try = 1;Try <= size * size;++Try){
		bool trySuccess = true;
		for(int i = 0;i < size * size;++i){
			if(Rows[A][i] == Try)
			{ trySuccess = false;break; }
		}
		if(trySuccess)
			for(int i = 0;i < size * size;++i){
				if(Rows[i][B] == Try)
				{ trySuccess = false;break; }
			}
		if(trySuccess)
		for(int i = (A / size) * size; i < (A / size) * size + size;++i){ 
			for(int j = (B / size) * size; j < (B / size) * size + size ;++j){
				if(Rows[i][j] == Try)
					{ trySuccess = false;break; }
			}
		}
		if(trySuccess){
			Rows[A][B] = Try;
			if(dfs(++blank,end,Rows,size)) return true;
			else { --blank; Rows[A][B] = 0;}
		}
	}
	return false;
}
int main(){
	int size,blank_line = 0;
	while(scanf("%d",&size) != EOF){
		if(blank_line)puts("");
		else blank_line = 1;
		vector<pair<int,int> > blank;
		vector<vector<int> > Rows;
		int temp;
		for(int i = 0;i < size * size;++i){
			Rows.push_back(vector<int>());
			for(int j = 0;j < size * size;++j){
				scanf("%d",&temp);
				Rows[i].push_back(temp);
				if(temp == 0)blank.push_back(make_pair(i,j));
			}
		}
		auto begin = blank.begin(),end = blank.end();
		bool canSolve = dfs(begin,end,Rows,size);
		if(canSolve){
			for(int i = 0;i < size * size;++i){
				for(int j = 0;j < size * size ;++j){
					if(j)putchar(' ');
					printf("%d", Rows[i][j]);
				}
				puts("");
			}
		}
		else{
			puts("NO SOLUTION");
		}
	}
	return 0;
}
