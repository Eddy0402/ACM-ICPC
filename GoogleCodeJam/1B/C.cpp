#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

int Flight[55][55];
int visit[55];
string result;

bool Try(vector<int> &Cities){
	vector<int> visited;
	int A = Cities.size();
	visited.push_back(A);
	visit[A] = true;
	bool all_visit = true;
	while(1){
		all_visit = true;
		for(int next:Cities){
			if(visit[next] == 0){
				all_visit = false;
				for(int i = visited.size() - 1;i >= 0;--i){
					if(Flight[visited[i]][next] == 1)
				}

			}
		}
		if(all_visit) break;
	}
	if(all_visit)return true;
	else return false;
}

int main(){
	int TestCase,Case =1;
	scanf("%d",&TestCase);
	while(TestCase--){
		int City,flight,temp2,temp;
		vector<int> Cities;
		scanf("%d%d",&City,&flight);
		for(int i = 0;i < City;++i){
			scanf("%d",&temp);
			Cities.push_back(temp);
		}
		memset(Flight,0,sizeof(Flight));
		for(int i = 0;i < flight;++i){
			scanf("%d%d",&temp,&temp2);
			Flight[temp-1][temp2-1] = 1;
			Flight[temp2-1][temp-1] = 1;
		}
		for(int i = 0;i < City;++i){
			Flight[City][i] = 1;
		}
		sort(Cities.begin(),Cities.end());
		result = "";
		memset(visit,0,sizeof(visit));
		Try(0,Cities);
		printf("Case #%d: %s\n",Case++,result.c_str());
	}
	return 0;
}
