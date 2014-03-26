#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<cmath>
using namespace std;
#define dist(a,b) ( pow(a.first - b.first,2) + pow(a.second - b.second,2)) 
		int up[755];
	int root(int a){
		int temp = a;
		while(up[a] != a){
			a = up[a];
		}
		up[temp] = a;
		return a;
	}
	void add(int a,int b){
		if(root(a)==root(b))return;
		else up[root(a)]=root(b);
	}
int main(){
		int Count;
		scanf("%d",&Count);
		double temp,temp2;
		vector<pair<double,double> >Points;
		vector<pair<double,pair<int,int> > > Edge;
		Points.reserve(Count);
		for(int i = 0;i < Count;++i){
			 up[i]=i;
		}
		for(int i = 0;i < Count;++i){
			scanf("%lf%lf",&temp,&temp2);
			Points.push_back(make_pair(temp,temp2));
		}
		int built;
		scanf("%d",&built);
		int index,index2;
		while(built--){
			scanf("%d%d",&index,&index2);
			add(index-1,index2-1);
		}
		for(int i = 0;i < Count;++i){
			for(int j = i + 1;j < Count;++j){
				Edge.push_back( make_pair(dist(Points[i], Points[j]) ,make_pair(i,j)) );
			}
		}
		sort(Edge.begin(),Edge.end());
		int tryEdge = -1;
		while(1){
			++tryEdge;
			if(tryEdge == Edge.size())break;
			if(root(Edge[tryEdge].second.first) == root(Edge[tryEdge].second.second))continue;
			printf("%d %d\n", Edge[tryEdge].second.first+1,1+Edge[tryEdge].second.second);
			add(Edge[tryEdge].second.first,Edge[tryEdge].second.second);
			++tryEdge;
		}
	
	return 0;
}
