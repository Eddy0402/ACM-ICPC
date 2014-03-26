#include<cstdio>
#include<map>
#include<queue>
#include<vector>
#include<set>
using namespace std;
int main(void){
	int N,pr;
	while( scanf("%d%d",&N,&pr) != EOF){
		if(N == 0 && pr == 0)break;
		vector<int> taskss(N,0),out;
		multimap<int,int> order;
		set<int> order1;
		char A,B;
		bool found = false,cantD = false;
		int time = 0,incon=100000000;
		for(int i = 0; i < pr; ++i){
			scanf(" %c<%c",&A,&B);
			taskss[B - 'A']++;
			order1.insert(A - 'A');
			order1.insert(B - 'A');
			if(!found){
				time++;
				vector<int> tasks(taskss);
				order.insert(make_pair(A - 'A',B - 'A'));

				queue<int> zero;
				for(int j = 0; j < N; ++j){
					if(tasks[j] == 0)
						zero.push(j);
				}
				bool flag = true;
				out.clear();
				while(zero.size()){
					if(zero.size() != 1)flag = false;
					out.push_back(zero.front());
					pair<multimap<int,int>::iterator, multimap<int,int>::iterator> link = order.equal_range(zero.front());
					for(multimap<int,int>::iterator it = link.first;it != link.second;++it){
						tasks[(*it).second]--;
						if(tasks[(*it).second] == 0){
							zero.push((*it).second);
						}
					}
					zero.pop();
				}
				if(out.size() == N && flag){
					found = true;
				}else{
					if(out.size() == N && i == pr - 1)cantD = true;
				}
				if(out.size() != N && incon > i){
					incon = i;
				}
			}
		}
		if(found){
			printf("Sorted sequence determined after %d relations: ",time);
			for(int i = 0; i < out.size(); i++ ){
				printf("%c",'A' + out[i]);
			}
			puts(".");
		}else if(cantD){
			puts("Sorted sequence cannot be determined.");
		}else{
			printf("Inconsistency found after %d relations.\n",incon + 1);
		}
	}
	return 0;
}
