#include<cstdio>
#include<string>
#include<queue>
using namespace std;
void print(string finish, queue<int> &remain,int finishedCount){
	if(finishedCount == 6){
		printf("%s\n",finish.c_str());
		return;
	}else{
		if(remain.size() == 0)return;
		int front = remain.front();
		remain.pop();
		queue<int> temp(remain);
		print(finish + ((finishedCount == 0) ? "" : " ") + to_string(front),temp,finishedCount + 1);
		print(finish,remain,finishedCount);
	}
}
int main(){
	int count,flag = 1,temp;
	while(scanf("%d",&count) != EOF){
		if(count == 0)break;
		if(flag)flag = 0;
		else printf("\n");
		
		queue<int> data;
		while(count --){
			scanf("%d",&temp);
			data.push(temp);
		}
		print("",data,0);
	}

	return 0;
}
