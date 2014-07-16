#include<cstdio>
#include<vector>
using namespace std;
int main(){
	int TestCase = 1;
	while(1){
		vector<int> Numbers;
		vector<int> coordinate;
		int temp;
		Numbers.reserve(200);
		while(scanf("%d",&temp) != EOF && temp != -1){
			if(temp != -1) Numbers.push_back(temp);	
		}
		if(!Numbers.size())break;
		if(TestCase != 1)puts("");
		coordinate.push_back(Numbers[0]);
		int lis;
		for(int i = 1;i < Numbers.size();++i){
			lis = 0;
			while(lis != coordinate.size() && coordinate[lis] > Numbers[i])
				++lis;
			if(lis == coordinate.size()){
				coordinate.push_back(Numbers[i]);
			}else{
				if(coordinate[lis] < Numbers[i]) coordinate[lis] = Numbers[i];
			}
		}
		printf("Test #%d:\n",TestCase++);
		printf("  maximum possible interceptions: %d\n",coordinate.size());
	}
	return 0;
}
