#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<cmath>
using namespace std;
#define dist(a,b) ( sqrt(pow(a.first - b.first,2) + pow(a.second - b.second,2)) )
struct GetRoot{
	vector<int> &Up;
	GetRoot(vector<int> &up): Up(up){}
	int operator()(int a){
		int temp = a;
		while(Up[a] != a) a = Up[a];
		Up[temp] = a;
return a;};};
int main(){
	int TestCase, flag = false;
	scanf("%d",&TestCase);
	while(TestCase--){
		if(flag)printf("\n");
		else flag = true;
		int Count;
		scanf("%d",&Count);
		double temp,temp2;
		vector<pair<double,double> >Points;
		vector<pair<double,pair<int,int> > > Edge;
		vector<int> up;
		Edge.reserve(Count * (Count - 1) / 2);
		Points.reserve(Count);
		for(int i = 0;i < Count;++i){
			up.push_back(i);
		}
		for(int i = 0;i < Count;++i){
			scanf("%lf%lf",&temp,&temp2);
			Points.push_back(make_pair(temp,temp2));
		}
		for(int i = 0;i < Count;++i){
			for(int j = i + 1;j < Count;++j){
				Edge.push_back( make_pair(dist(Points[i], Points[j]) ,make_pair(i,j)) );
			}
		}
		sort(Edge.begin(),Edge.end());
		double result = 0.0;
		int tryEdge = 0;
		GetRoot root(up);
		while(--Count){
			while( root(Edge[tryEdge].second.first) == root(Edge[tryEdge].second.second) )++tryEdge;
			result += Edge[tryEdge].first;
			up[root(Edge[tryEdge].second.first)] = Edge[tryEdge].second.second;
			++tryEdge;
		}
		printf("%.2f\n",result);
	}
	return 0;
}
