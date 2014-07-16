#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
int VisitTime[10005],Low[10005];
int Ans[10005];
int time,root;
vector<int> conn[10005];

void DFS(int current,int parent,vector<int> Adj[]){
	int childCount = 0;
	int cutCount = 0;
	Low[current] = VisitTime[current] = ++time;
	for(int n = 0; n < Adj[current].size(); ++n){
		int next = Adj[current][n];
		if(!VisitTime[next]){
			++childCount;
			DFS(next,current,Adj);
			Low[current] = min(Low[current],Low[next]);
			if( (root == current && childCount > 1) || (root != current && Low[next] >= VisitTime[current])){
				++Ans[current];
			}
		}else if(parent != next){
			Low[current] = min(Low[current],VisitTime[next]);
		}
	}
}

int main(){
	int Point,Conns;
	while(scanf("%d%d",&Point,&Conns) && !(!Point && !Conns )){
		if(Conns == 0){printf("%d\n",Point-1);continue;}
		int result = 0;
		int a,b;
		for(int i = 0;i <= Point;++i){
			conn[i].clear();
		}
		for(int i = 0;i < Conns;++i){
			scanf("%d%d",&a,&b);
			conn[1+a].push_back(1+b);
			conn[1+b].push_back(1+a);
		}
		memset(VisitTime,0,sizeof(VisitTime));
		memset(Low,0,sizeof(Low));
		memset(Ans,0,sizeof(Ans));
		int temp = 0;
		for(int i = 1;i <= Point;++i){
			if(Low[i] == 0){
				root = i;
				DFS(i,-1,conn);
				++result;
			}
			temp = max(temp,Ans[i]);
		}
		printf("%d\n",result + temp);
	}
	return 0;
}
