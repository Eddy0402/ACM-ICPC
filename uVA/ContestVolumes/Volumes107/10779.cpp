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
	int TestCase,Case = 1,N,M,start,end;
	scanf("%d",&TestCase);
	while(TestCase--){
		scanf("%d%d",&N,&M);
		start = 1;
		end = N + M + 1;
		memset(cap,0,sizeof(cap));
		memset(used,0,sizeof(used));
		int P,PP;
		for(int i = 1;i <= N;++i){
			scanf("%d",&P);
			for(int j = 1;j <= P;++j){
				scanf("%d",&PP);
				++cap[i][N+PP];
			}
			if(i != 1)
				for(int j = 1;j <= M;++j){
					if(cap[i][N+j] == 0) cap[N+j][i] = 1;
					else --cap[i][N+j];
				}
		}
		for(int i = 1;i <= M;++i)
			cap[N+i][end] = 1;
		int totalBandwidth,oneBandWidth;
		for(totalBandwidth = 0; oneBandWidth = bfs(start,end,N+M+1); totalBandwidth += oneBandWidth){
			for(int i = end;i != start;i = pass[i]){
				int j = pass[i];
				used[j][i] = used[j][i] + oneBandWidth;
				used[i][j] = -used[j][i];
			}
		}
		printf("Case #%d: %d\n",Case++,totalBandwidth);
	}
	return 0;
}
