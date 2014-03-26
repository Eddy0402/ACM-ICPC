#include<cstdio>
#include<set>
#include<vector>
using namespace std;
set<int> prime{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59};
void print(vector<int> &finish,int input,vector<bool> used){
	if(input == finish.size()){
		if(prime.find(finish[0] + finish[finish.size() - 1]) != prime.end()){
			bool flag = false;
			for(auto a : finish){
				if(flag)printf(" ");
				else flag = true;
				printf("%d",a);	
			}
			puts("");
		}
		return;
	}
	for(int i = 1;i <= input;++i){
		if(!used[i]){
			used[i] = true;
			if(prime.find(i + *finish.rbegin()) != prime.end()){
				finish.push_back(i);
				print(finish,input,used);
				finish.pop_back();
			}
			used[i] = false;
		}
	}
}
int main(void){
	int input,Test = 1;
	while(scanf("%d",&input)!= EOF){
		if(Test != 1)puts("");
		printf("Case %d:\n",Test++);
		if(input == 1){
			puts("1");
		}else{
			vector<int> ring{1};
			vector<bool> used(input + 1,false);
			used[1] = true;
			print(ring,input,used);
		}
	}
	return 0;
}
