#include<cstdio>
#include<map>
#include<queue>
#include<vector>
using namespace std;
int main(void){
	int N;
	while( scanf("%d",&N) != EOF){
		vector<int> tasks(N,0);
		queue<int> zero;
		multimap<int,int> order;
		for(int i = 0; i < N; ++i){
			int previos = i + 1, next = 0;
			while(scanf("%d",&next) && next != 0){
				tasks[next - 1]++;
				order.insert(make_pair(previos - 1,next - 1));
			}
		}
		for(int i = 0; i < N; ++i)
			if(tasks[i] == 0)
				zero.push(i);
		bool flag = 1;
		while(zero.size()){
			if(flag) flag = 0;
			else printf(" ");
			printf("%d",1 + zero.front());
			pair<multimap<int,int>::iterator, multimap<int,int>::iterator> link = order.equal_range(zero.front());
			for(multimap<int,int>::iterator it = link.first;it != link.second;++it){
				tasks[(*it).second]--;
				if(tasks[(*it).second] == 0)
					zero.push((*it).second);
			}
			zero.pop();
		}
		puts("");
	}
	return 0;
}
