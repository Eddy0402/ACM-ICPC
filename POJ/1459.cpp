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
		for(int i = 0;i <= N;++i){
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
	int Test=1,N,start,end;
	while(scanf("%d",&N) != EOF){
		int Power,Consumer,Link;
		scanf("%d%d%d",&Power,&Consumer,&Link);
		start = N ,end = N + 1;

		memset(cap,0,sizeof(cap));
		memset(used,0,sizeof(used));

		int A,B,Cap;
		for(int i = 0;i < Link; ++i){
			scanf(" (%d,%d)%d",&A,&B,&Cap);
			if(A != B)
				cap[A][B] += Cap;
		}
		for(int i = 0;i < Power;++i){
			scanf(" (%d)%d",&A,&Cap);
			cap[start][A] += Cap;
		}
		for(int i = 0;i < Consumer;++i){
			scanf(" (%d)%d",&A,&Cap);
			cap[A][end] += Cap;
		}

		int totalBandwidth,oneBandWidth;
		for(totalBandwidth = 0; oneBandWidth = bfs(start,end,N+1); totalBandwidth += oneBandWidth){
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
