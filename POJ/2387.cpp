#include<cstdio>
#include<vector>
using namespace std;
int dist[1050]={};
struct Edge{
	int x,y,dist;
	Edge(int a,int b,int c) : x(a) , y(b), dist (c) {}
};
bool relax(Edge &target){
	int distance = dist[target.x] - dist[target.y];
	if(distance < 0)distance = -distance;
	if(distance > target.dist){
		int small = dist[target.x] < dist[target.y] ? target.x : target.y;
		int big = dist[target.x] > dist[target.y] ? target.x : target.y;
		dist[big] = dist[small] + target.dist;
		return true;
	}
	return false;
}
int main(){
	int Landmark, Road,temp,temp2,temp3;
	while(scanf("%d%d",&Road,&Landmark) != EOF){
		if(Road == 0 && Landmark == 0)break;
		vector<Edge> Edges;
		Edges.reserve(Road);
		while(Road--){
			scanf("%d%d%d",&temp,&temp2,&temp3);
			Edges.push_back( Edge(temp,temp2,temp3) );
		}
		for(int i = 2;i <= Landmark;++i){
			dist[i] = 214748364;
		}
		for(int j = 1;j <=Landmark;++j){
			bool flag = false;
			for(int i = 0; i < Edges.size();++i){
				if(relax(Edges[i])) flag = true;
			}
			if(!flag)break;
		}
		printf("%d\n",dist[Landmark]);
	}
	return 0;
}
