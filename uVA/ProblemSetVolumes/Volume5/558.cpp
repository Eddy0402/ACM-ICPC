#include<cstdio>
#include<vector>
using namespace std;
int dist[1050]={};
struct Edge{
	int x,y,dist;
	Edge(int a,int b,int c) : x(a) , y(b), dist (c) {}
};
bool relax(Edge &target){
	if(dist[target.y] > dist[target.x] + target.dist){
		dist[target.y] = dist[target.x] + target.dist;
		return true;
	}
	return false;
}
int main(){
	int Landmark, Road, temp, temp2, temp3,TestCase;
	scanf("%d",&TestCase);
	while(TestCase--){
		scanf("%d%d",&Landmark,&Road);
		vector<Edge> Edges;
		Edges.reserve(Road);
		while(Road--){
			scanf("%d%d%d",&temp,&temp2,&temp3);
			Edges.push_back( Edge(temp,temp2,temp3) );
		}
		dist[0] = 0;
		for(int i = 1;i < Landmark;++i){
			dist[i] = 9999999;
		}
		for(int j = 1;j < Landmark;++j){
			bool flag = true;
			for(int i = 0; i < Edges.size();++i){
				if(relax(Edges[i]))flag = false;
			}
			if(flag)break;
		}
		bool flag = false;
		for(int i = 0; i < Edges.size();++i){
			if(relax(Edges[i]))flag = true;
		}
		puts(flag ? "possible" : "not possible");
	}
	return 0;
}

