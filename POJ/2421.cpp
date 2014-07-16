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
	int Count,free;
	while(scanf("%d",&Count) != EOF){
		vector<pair<int,pair<int,int> > > Edge;
		vector<int> up;
		Edge.reserve(Count * (Count - 1) / 2);
		up.reserve(Count);
		GetRoot root(up);
		for(int i = 0;i < Count;++i) up.push_back(i);
		int temp;
		for(int i = 0;i < Count;++i){
			for(int j = 0;j < i + 1;++j){
				scanf("%d",&temp);
			}
			for(int j = i + 1;j < Count;++j){
				scanf("%d",&temp);
				Edge.push_back( make_pair(temp, make_pair(i,j)) );
			}
		}
		int road,temp2;
		scanf("%d",&road);
		while(road--){
			scanf("%d%d",&temp,&temp2);
			up[root(temp-1)] = root(temp2-1);
		}
		sort(Edge.begin(),Edge.end());
		int result = 0, tryEdge = 0;
		for(int a = 0;a < Count;++a)
		while(1){
			while(tryEdge != Edge.size() && root(Edge[tryEdge].second.first) == root(Edge[tryEdge].second.second) )++tryEdge;
			if(tryEdge == Edge.size())break;
			result += Edge[tryEdge].first;
			up[root(Edge[tryEdge].second.first)] = Edge[tryEdge].second.second;
			++tryEdge;
		}
		printf("%d\n",result);
	}
	return 0;
}
