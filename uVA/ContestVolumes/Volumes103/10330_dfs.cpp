#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 99999999
int cap[210][210];
int used[210][210];
int visit[210];
int pass[210];
bool dfs(int start,int end,int N){
	visit[start] = 1;
	if(start == end) return true;
	for(int i = 1;i <= N*2+2;++i){
		if(visit[i])continue;
		if( used[start][i] < cap[start][i] || used[i][start]){
			pass[i] = start;
			if(dfs(i,end,N))return true;
		}
	}
	return false;
}

int findBandWidth(int start,int end,int N){
	int flow = INF;
	for(int i = end; i != start;i = pass[i]){
		int pre = pass[i];
		if(cap[pre][i]-used[pre][i] > 0)
			flow = std::min(flow,cap[pre][i] - used[pre][i]);
		else
			flow = std::min(flow,used[i][pre]);
	}
	for(int i = end;i != start;i = pass[i]){
		int pre = pass[i];
			if(cap[pre][i] > used[pre][i])
				used[pre][i] = used[pre][i] + flow;
			else
				used[i][pre] = used[i][pre] - flow;
	}
	return flow;
}

int main(){
	int Test=1,N,start,end,connections;
	while(scanf("%d",&N) != EOF){
		start = N * 2 + 1,end = N * 2 + 2;
		for(int i = 1;i <= N*2+2;++i){
			for(int j = 1;j <= N*2+2;++j){
				cap[i][j] = 0;
				used[i][j] = 0;
			}
		}
		for(int i = 1;i <= N;++i){
			scanf("%d",&cap[i][i+N]);
		}
		int Road;
		scanf("%d",&Road);
		int A,B,Bandwidth;
		for(int i = 0;i < Road;++i){
			scanf("%d%d%d",&A,&B,&Bandwidth);
			cap[A+N][B] = Bandwidth;
		}
		int startCount,endCount;
		scanf("%d%d",&startCount,&endCount);
		for(int i = 0;i < startCount;++i){
			scanf("%d",&A);
			cap[start][A] = INF;
		}
		for(int i = 0;i < endCount;++i){
			scanf("%d",&A);
			cap[A+N][end] = INF;
		}
		int totalBandwidth = 0;
		while(1){
			memset(visit,0,sizeof(visit));
			if(!dfs(start,end,N)) break;
			totalBandwidth += findBandWidth(start,end,N);
		}
		printf("%d\n",totalBandwidth);
	}
	return 0;
}
