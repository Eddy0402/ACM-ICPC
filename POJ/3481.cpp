#include<cstdio>
#include<map>
using namespace std;
int main(){
	int operation, client, priority;
	map<int,int> toServe;
	while(scanf("%d",&operation)){
		switch(operation){
			case 0:
				return 0;
			case 1:
				scanf("%d%d",&client,&priority);
				toServe[priority] = client;
				break;
			case 2:
				if(toServe.size() == 0){
					printf("0\n");
					break;
				}
				printf("%d\n",(*--toServe.end()).second);
				toServe.erase(--toServe.end());
				break;
			case 3:
				if(toServe.size() == 0){
					printf("0\n");
					break;
				}
				printf("%d\n",(*toServe.begin()).second);
				toServe.erase(toServe.begin());
		}
	}
	return 0;
}
