#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
int VisitTime[1005],Low[1005];
vector<int> Ans,Ans2;
int time;

void DFS(int current,int parent,vector<int> Adj[]){
	int childCount = 0;
	bool noCycle = false;
	int cutCount = 0;
	Low[current] = VisitTime[current] = ++time;
	for(int n = 0; n < Adj[current].size(); ++n){
		int next = Adj[current][n];
		if(!VisitTime[next]){
			++childCount;
			DFS(next,current,Adj);
			Low[current] = min(Low[current],Low[next]);
			if(Low[next] >= VisitTime[current]){
				noCycle = true;
				++cutCount;
			}
		}else if(parent != next){
			Low[current] = min(Low[current],VisitTime[next]);
		}
	}
	if( (childCount >= 2 || parent >= 0) && noCycle ){
		Ans.push_back(current);
		if(parent != -1)
			Ans2.push_back(1 + cutCount);
		else
			Ans2.push_back(cutCount);
	}
}

int main(){
	int Case = 1;
	while(1){
		bool isEnd = true;
		int a,b,max = 0;
		vector<int> conn[1010];
		while(scanf("%d",&a) && a){
			isEnd = false;
			scanf("%d",&b);
			if(a > max)max = a;
			if(b > max)max = b;
			conn[a].push_back(b);
			conn[b].push_back(a);
		}
		if(isEnd)break;
		Ans.clear();
		Ans2.clear();
		memset(VisitTime,0,sizeof(VisitTime));
		memset(Low,0,sizeof(Low));
		for(int i = 1;i <= max;++i){
			if(Low[i] == 0)
				DFS(i,-1,conn);
		}
		printf("Network #%d\n",Case++);
		for(int i = Ans.size()-1;i >= 0;--i){ 
			printf("  SPF node %d leaves %d subnets\n",Ans[i],Ans2[i]);
		}
		if(Ans.empty())puts("  No SPF nodes");
		puts("");
	}
	return 0;
}
