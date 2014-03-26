#include<cstdio>
#include<map>
#include<queue>
#include<vector>
using namespace std;
int main(void){
	int Task,Precedence;
	while(scanf("%d%d",&Task,&Precedence) != EOF){
		if(Task == 0 && Precedence == 0)break;
		vector<int> tasks(Task,0);
		queue<int> zero;
		multimap<int,int> order;
		for(int i = 0; i < Precedence; ++i){
			int front,back;
			scanf("%d%d",&front,&back);
			front--;back--;
			tasks[back]++;
			order.insert(make_pair(front,back));
		}
		for(int i = 0; i < Task; ++i){
			if(tasks[i] == 0){
				zero.push(i);
			}
		}
		bool flag = 1;
		while(zero.size()){
			if(flag) flag = 0;
			else printf(" ");

			printf("%d",1 + zero.front());
			auto link = order.equal_range(zero.front());
			for(auto it = link.first;it != link.second;++it){
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
