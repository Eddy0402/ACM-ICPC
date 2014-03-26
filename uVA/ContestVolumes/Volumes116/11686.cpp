#include<map>
#include<queue>
#include<vector>
#include<cstdio>
using namespace std;
int main(void){
	int N,Task;
	while( scanf("%d%d",&N ,&Task)!= EOF){
		if(N == 0 && Task == 0)break;
		vector<int> tasks(N,0),out;
		queue<int> zero;
		multimap<int,int> order;
		int A,B;
		for(int i = 0; i < Task; ++i){
			scanf("%d%d",&A,&B); 
			tasks[B - 1]++;
			order.insert(make_pair(A - 1,B - 1));
		}
		for(int i = 0; i < N; ++i)
			if(tasks[i] == 0)
				zero.push(i);
		while(zero.size()){
			out.push_back(zero.front());
			pair<multimap<int,int>::iterator, multimap<int,int>::iterator> link = order.equal_range(zero.front());
			for(multimap<int,int>::iterator it = link.first;it != link.second;++it){
				tasks[(*it).second]--;
				if(tasks[(*it).second] == 0)
					zero.push((*it).second);
			}
			zero.pop();
		}
		if(out.size() != N)
			puts("IMPOSSIBLE");
		else{
			for(auto a : out)
				printf("%d\n", a + 1);
		}
	}   
	return 0;
}
