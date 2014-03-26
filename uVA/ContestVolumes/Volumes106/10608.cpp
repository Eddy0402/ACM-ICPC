#include<cstdio>
#include<vector>
using namespace std;
int main(){
	int TestCase;
	scanf("%d",&TestCase);
	while(TestCase--){
		int CitizensCount,Pairs;
		scanf("%d%d",&CitizensCount,&Pairs);
		vector<int> Citizens;
		vector<int> Group(CitizensCount,1);
		for(int i = 0;i < CitizensCount;++i)
			Citizens.push_back(i);
		int temp,temp2;
		while(Pairs--){
			scanf("%d%d",&temp,&temp2);
			--temp;--temp2;
			int t = temp,t2 = temp2;
			while(Citizens[temp] != temp)temp = Citizens[temp];
			while(Citizens[temp2] != temp2)temp2 = Citizens[temp2];
			Citizens[t] = temp;
			Citizens[t2] = temp2;
			if(temp2 != temp){
				Citizens[temp2] = temp;
				Group[temp] += Group[temp2];
			}
		}
		int result = 0;
		for(int a = 0;a < Group.size();++a){
			if(Group[a] > result )result = Group[a];
		}
		printf("%d\n",result);
	}
	return 0;
}
