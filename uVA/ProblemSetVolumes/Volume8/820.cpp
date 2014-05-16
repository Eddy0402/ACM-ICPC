#include<cstdio>
#include<cstring>
#include<algorithm>
int cap[110][110];
int used[110][110];
int visit[110];
int pass[110];
bool dfs(int start,int end,int N){
	visit[start] = 1;
	if(start == end) return true;
	for(int i = 1;i <= N;++i){
		if(visit[i])continue;
		if(start < i){
			if(cap[start][i] == 0)continue;
			if( /*-cap[start][i] < used[start][i] &&*/ used[start][i] < cap[start][i] ){
				pass[i] = start;
				if(dfs(i,end,N))return true;
			}
		}else{
			if(cap[i][start] == 0)continue;
			if( -cap[i][start] < used[i][start]/* && used[i][start] < cap[i][start]*/){
				pass[i] = start;
				if(dfs(i,end,N))return true;
			}
		}
	}
	return false;
}

int findBandWidth(int start,int end,int N){
	int flow = 9999999;

	for(int i = end; i != start;i = pass[i]){
		int pre = pass[i];
		if(pre < i){
			flow = std::min(flow,cap[pre][i] - used[pre][i]);
		}else{
			flow = std::min(flow,used[i][pre] - (-cap[i][pre]) );
		}
	}
	for(int i = end;i != start;i = pass[i]){
		int pre = pass[i];
		if(pre < i){
			used[pre][i] = used[pre][i] + flow;
		}else{
			used[i][pre] = used[i][pre] - flow;
		}
	}
	return flow;
}

int main(){
	int Test=1,N,start,end,connections;
	while(scanf("%d",&N) && N){
		scanf("%d%d%d",&start,&end,&connections);
		for(int i = 1;i <= N;++i){
			for(int j = 1;j <= N;++j){
				cap[i][j] = 0;
				used[i][j] = 0;
			}
		}
		int A,B,Bandwidth;
		for(int i = 0;i < connections;++i){
			scanf("%d%d%d",&A,&B,&Bandwidth);
			if(A < B)cap[A][B] += Bandwidth;
			else cap[B][A] += Bandwidth;
		}
		int totalBandwidth = 0;
		while(1){
			memset(visit,0,sizeof(visit));
			if(!dfs(start,end,N)) break;
			totalBandwidth += findBandWidth(start,end,N);
		}
		printf("Network %d\n",Test++);
		printf("The bandwidth is %d.\n",totalBandwidth);
		puts("");
	}
	return 0;
}
