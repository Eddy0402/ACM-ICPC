#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

int VisitTime[105],Low[105];
vector<int> Ans;
int time;

void DFS(int current,int parent,vector<int> Adj[]){
	int childCount = 0;
	bool noCycle = false;
	Low[current] = VisitTime[current] = ++time;
	for(int n = 0; n < Adj[current].size(); ++n){
		int next = Adj[current][n];
		if(!VisitTime[next]){
			++childCount;
			DFS(next,current,Adj);
			Low[current] = min(Low[current],Low[next]);
			if(Low[next] >= VisitTime[current])
				 noCycle = true;
		}else if(parent != next){
			Low[current] = min(Low[current],VisitTime[next]);
		}
	}
	if( (childCount >= 2 || parent >= 0) && noCycle )
		Ans.push_back(current);
}

int main(){
	int N;
	while(scanf("%d ",&N) && N != 0){
		char pl_input[200];
		vector<int> Adj[105];
		while( fgets(pl_input,200,stdin)){
			static int A,B;
			sscanf(pl_input,"%d%[^\n]",&A,pl_input);
			if(A == 0)break;
			while(int t = sscanf(pl_input,"%d%[^\n]",&B,pl_input) ){
				Adj[A].push_back(B);
				Adj[B].push_back(A);
				if(t == 1)break;
			}
		}
		time = 0;
		Ans.clear();
		memset(VisitTime,0,sizeof(VisitTime));
		memset(Low,0,sizeof(Low));
		DFS(1,-1,Adj);
		printf("%d\n",Ans.size());
	}
	return 0;
}
