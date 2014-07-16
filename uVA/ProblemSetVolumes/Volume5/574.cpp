#include<cstdio>
#include<vector>
#include<string>
using namespace std;
bool search(int Target,int lastNumber,int lastChooseNumber,
			vector<int> &numbers,vector<int>::iterator remain,int current,vector<int> &finish){
	if(current == Target){
		bool flag = false;
		for(auto a : finish){
			if(flag)printf("+");
			else flag = true;
			printf("%d",a);
		}
		puts("");
		return true;
	}
	if(current > Target)return false;
	if(remain == numbers.end())return false;
	if(*remain == lastNumber && lastNumber != lastChooseNumber){
		while(*++remain == lastNumber)
			;
		return search(Target,lastNumber,lastChooseNumber,numbers,remain,current,finish);
	}
	bool result = false;
	finish.push_back(*remain);
	if(search(Target,*remain,*remain,numbers,remain + 1,current + *remain,finish))
		result = true;
	finish.pop_back();
	if(search(Target,*remain,0,numbers,remain + 1,current,finish))
		result = true;
	return result;
}
int main(void){
	int Target,NumberCount;
	while(scanf("%d%d",&Target,&NumberCount) != EOF){
		if(!NumberCount)break;
		int temp;
		vector<int> Numbers;
		Numbers.reserve(NumberCount);
		while(NumberCount--){
			scanf("%d",&temp);
			Numbers.push_back(temp);
		}
		printf("Sums of %d:\n",Target);
		vector<int> result;
		if(!search(Target,0,0,Numbers,Numbers.begin(),0,result)){
			puts("NONE");	
		}
	}
	return 0;
}
