#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<cmath>
using namespace std;
struct GetRoot{
	vector<int> &Up;
	GetRoot(vector<int> &up): Up(up){}
	int operator()(int a){
		int temp = a;
		while(Up[a] != a) a = Up[a];
		Up[temp] = a;
return a;};};
int main(){
	int Count,M;
	if(scanf("%d%d",&Count,&M)!=EOF){
		vector<pair<int,pair<int,int> > > Edge;
		vector<int> up;
		Edge.reserve(M);
		up.reserve(Count);
		for(int i = 0;i < Count;++i)
			 up.push_back(i);
		int temp,temp2,temp3;
		for(int i = 0;i <M;++i){
			scanf("%d%d%d",&temp,&temp2,&temp3);
			Edge.push_back(make_pair(temp3,make_pair(temp-1,temp2-1)));
		}
		sort(Edge.begin(),Edge.end());
		int result = 0;
		int tryEdge = 0;
		GetRoot root(up);
		while(--Count){
			while( root(Edge[tryEdge].second.first) == root(Edge[tryEdge].second.second) )++tryEdge;
			result = Edge[tryEdge].first;
			up[root(Edge[tryEdge].second.first)] = Edge[tryEdge].second.second;
			++tryEdge;
		}
		printf("%d\n",result);
	}
	return 0;
}
