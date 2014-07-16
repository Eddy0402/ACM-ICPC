#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

int Low[2002],DFN[2002],index;
vector<int> Stack;

void Tarjan(int u){
	DFN[u] = Low[u] = ++index;
	Stack.push_back(u);
	for(int n = 0;n < Adj[u].size();++n){
		int next = Adj[u][n];
		if(Low[v]){
			Tarjan(u);
			Low[u] = min(Low[u],Low[v]);
		}else if(inStack(v)){
			Low[u] = min(Low[u],DFN[v]);
		}
	}




}


int main(){
	int N,Street;
	while(scanf("%d%d",&N,&Street) != EOF){
		if( N == 0 && Street == 0)break;
		vector<int> Adj[2002];
		int A,B,way;
		for(int i = 0;i < Street; ++i){
			scanf("%d%d%d",&A,&B,&way);
			Adj[A].push_back(B);
			if(way == 2)B.push_back(A);
		}
		


	}
	return 0;
}
