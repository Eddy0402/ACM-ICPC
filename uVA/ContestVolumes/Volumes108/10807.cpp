#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;
typedef vector<pair<int,pair<int,int> > > Edge_t;
int root(int a,vector<int> &Up){
	int temp = a;
	while(Up[a] != a) a = Up[a];
	Up[temp] = a;
	return a;
}
int Search(Edge_t::iterator now,Edge_t::iterator end,vector<int>& up,vector<int>& up2,int remain1,int remain2){
	printf("ss\n");
	if(remain1 == 0 && remain2 == 0)return 0;
	if(now == end)return -1;
	while(root((*now).second.first,up)  == root((*now).second.second,up) &&
		  root((*now).second.first,up2) == root((*now).second.second,up2) && now != end )++now;
	if(now == end)return -1;
	if(root((*now).second.first,up)  == root((*now).second.second,up) ){
		int test = up2[root((*now).second.first,up2)];
		up2[root((*now).second.first,up2)] = root((*now).second.second,up2);
		int temp = Search(now+1,end,up,up2,remain1,remain2-1);
		up2[root((*now).second.first,up2)] = test; 
		if(temp != -1) return temp + (*now).first;
		else return -1;
	}else if(root((*now).second.first,up2)  == root((*now).second.second,up2) ){
		int test = up[root((*now).second.first,up)];
		up[root((*now).second.first,up)] = root((*now).second.second,up);
		int temp = Search(now+1,end,up,up2,remain1-1,remain2);
		up[root((*now).second.first,up)] = test; 
		if(temp != -1) return temp + (*now).first;
		else return -1;
	}else{
		int First = -1,Second = -1;

		int test = up2[root((*now).second.first,up2)];
		up2[root((*now).second.first,up2)] = root((*now).second.second,up2);
		if(remain1) First = Search(now+1,end,up,up2,remain1,remain2-1);
		up2[root((*now).second.first,up2)] = test; 
	
		test = up[root((*now).second.first,up)];
		up[root((*now).second.first,up)] = root((*now).second.second,up);
		if(remain2) Second = Search(now+1,end,up,up2,remain1-1,remain2);
		up[root((*now).second.first,up)] = test; 

		if(First == -1 && Second == -1)return -1;
		else if(First == -1)return Second + (*now).first;
		else if(Second == -1)return First + (*now).first;
		else return (First < Second ? First : Second) + (*now).first;
	}

}
int main(){
	int Cites,Lines;
	while( scanf("%d%d",&Cites,&Lines) != EOF){
		int temp,temp2,temp3;
		Edge_t Edge;
		vector<int> up(Cites);
		vector<int> up2(Cites);
		Edge.reserve(Lines);
		for(int i = 0;i < Cites; ++i) up[i]=i;
		for(int i = 0;i < Cites; ++i) up2[i]=i;
		for(int i = 0;i < Lines; ++i){
			scanf("%d%d%d",&temp,&temp2,&temp3);
			Edge.push_back(make_pair(temp3,make_pair(temp-1,temp2-1)));
		}
		sort(Edge.begin(),Edge.end());
		up[root(Edge[0].second.first,up)] = root(Edge[0].second.second,up);
		int result = Search(Edge.begin() + 1,Edge.end(),up,up2,Cites-2,Cites-1);
		if(result != -1)printf("%d\n",Edge[0].first+result);
		else puts("No way!");
	}
	return 0;
}
