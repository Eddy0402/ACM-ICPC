#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#define INF 99999999
int cap[210][210];
int used[210][210];
int visit[210];
int pass[210];
int flow[210];

int bfs(int start,int end,int N){
	memset(visit,0,sizeof(visit));
	visit[start] = 1;
	pass[start] = start;
	flow[start] = INF;

	std::queue<int> Q;
	Q.push(start);

	while(Q.size()){
		int v = Q.front();
		Q.pop();
		for(int i = 0;i <= N * 2 + 2;++i){
			if(visit[i] == 0 && cap[v][i] - used[v][i] > 0){
				visit[i] = 1;
				pass[i] = v;
				flow[i] = std::min(flow[v], cap[v][i] - used[v][i]);
				if(i == end)return flow[i];
				Q.push(i);
			}
		}
	}
	return 0;
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
		int totalBandwidth,oneBandWidth;
		for(totalBandwidth = 0; oneBandWidth = bfs(start,end,N); totalBandwidth += oneBandWidth){
			for(int i = end;i != start;i = pass[i]){
				int j = pass[i];
				used[j][i] = used[j][i] + oneBandWidth;
				used[i][j] = -used[j][i];
			}
		}
		printf("%d\n",totalBandwidth);
	}
	return 0;
}
