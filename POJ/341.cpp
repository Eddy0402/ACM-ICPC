#include<cstdio>
#include<vector>
using namespace std;
int dist[1050]={};
int pre[1000];
struct Edge{
	int x,y,dist;
	Edge(int a,int b,int c) : x(a) , y(b), dist (c) {}
};      
bool relax(Edge &target){
	if(dist[target.y] > dist[target.x] + target.dist){
		dist[target.y] = dist[target.x] + target.dist;
		pre[target.y] = target.x;
		return true;
	}
	return false;
}
int main(){
	int NodeCount,start,end,Case = 1;
	while(scanf("%d",&NodeCount) != EOF && NodeCount){
		vector<Edge> Edges;
		for(int i = 1;i <= NodeCount;++i){
			int count,dest,time;
			scanf("%d",&count);
			for(int j = 0;j < count;++j){
				scanf("%d %d",&dest,&time);
				Edges.push_back( Edge(dest,i,time) );
			}
		}
		scanf("%d%d",&start,&end);
		for(int i = 1;i <= NodeCount;++i){
			dist[i] = 214748364;
		}
		dist[end] = 0;
		for(int j = 1;j <= NodeCount;++j){
			bool flag = false;
			for(int i = 0; i < Edges.size();++i){
				if(relax(Edges[i])) flag = true;
			}
			if(!flag)break;
		}
		printf("Case %d: Path =",Case++);
		int out = start;
		while(1){
			printf(" %d",out);
			out = pre[out];
			if(out == end){ printf(" %d",end); break; }
		}
		printf("; %d second delay\n",dist[start]);
		
	}
	return 0;
}
