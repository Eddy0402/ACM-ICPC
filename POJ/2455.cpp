#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
#define INF 99999999
int cap[210][210];
int used[210][210];
int visit[210];
int pass[210];
int flow[210];

using namespace std;
struct Edge{ 
	int a,b,len;
	Edge(int a_,int b_,int len_):a(a_),b(b_),len(len_){} 
	bool operator<(const Edge &a) const{
		return len < a.len;
	}
};

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
	int N,P,T;
	scanf("%d%d%d",&N,&P,&T); 
	int left = 0,right = 0,middle,start = 1,end = N;
	vector<Edge> edge;
	int A_i,B_i,L_i;
	for(int i = 0;i < P;++i){
		scanf("%d%d%d",&A_i,&B_i,&L_i);
		edge.push_back(Edge(A_i,B_i,L_i));
		right = std::max(L_i,right);
	}
	sort(edge.begin(),edge.end());
	while(left != right){
		middle = (left + right) / 2;
		memset(cap,0,sizeof(cap));
		memset(used,0,sizeof(used));

		for(int i = 0;i < edge.size();++i){
			if(edge[i].len > middle)break;
			cap[edge[i].a][edge[i].b] = ++cap[edge[i].b][edge[i].a] ;
		}

		int totalBandwidth,oneBandWidth;
		for(totalBandwidth = 0; oneBandWidth = bfs(start,end,N+1); totalBandwidth += oneBandWidth){
			for(int i = end;i != start;i = pass[i]){
				int j = pass[i];
				used[j][i] = used[j][i] + oneBandWidth;
				used[i][j] = -used[j][i];
			}
		}
		if (totalBandwidth >= T)right = middle;
		else left = middle + 1;
	}
	printf("%d\n",right);
	return 0;
}
