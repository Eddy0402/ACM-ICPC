#include<cstdio>
#include<queue>
#include<vector>
#include<list>
using namespace std;
int Distance[501];
int PushCount[501];
int main(){
	int TestCase;
	scanf("%d",&TestCase);
	while(TestCase--){
		int Farm,Path,Wormholes;
		scanf("%d%d%d",&Farm,&Path,&Wormholes);
		vector<list<pair<int,int> > > AdjList(Farm + 1);
		int p1,p2,length;
		for(int i = 0;i < Path;++i){
			scanf("%d%d%d",&p1,&p2,&length);
			AdjList[p1].push_back( make_pair(p2,length) );
			AdjList[p2].push_back( make_pair(p1,length) );
		}
		for(int i = 0;i < Wormholes;++i){
			scanf("%d%d%d",&p1,&p2,&length);
			AdjList[p1].push_back( make_pair(p2,-length) );
		}
		for(int i = 2;i <= Farm;++i)
			Distance[i] = 21474836;
		Distance[1] = 0;
		for(int i = 1;i <= Farm;++i)
			PushCount[i] = 1;
		queue<int> ToRelax;
		ToRelax.push(1);
		++PushCount[1];
		bool result = false;
		while(1){
			while(ToRelax.size()){
				int target = ToRelax.back();
				for(list<pair<int,int> >::iterator it = AdjList[target].begin();
						it != AdjList[target].end();
						++it){
					if(Distance[(*it).first] - Distance[target] > (*it).second){
						Distance[(*it).first] = Distance[target] + (*it).second;
						ToRelax.push((*it).first);
						++PushCount[(*it).first];
						if(PushCount[(*it).first] == Farm){
							result = true;
							break;
						}
					}
				}
				ToRelax.pop();
				if(result == true)break;
			}
			if(result == true)break;
			for(int i = 1;i <= Farm;++i){
				if(PushCount[i] == 0 && Distance[i] == 21474836){
					 ToRelax.push(i);
					 ++PushCount[i];
					 break;
				}
			}
			if(ToRelax.size() == 0)break;
		}
		puts(result ? "YES" : "NO");
	}
	return 0;
}
