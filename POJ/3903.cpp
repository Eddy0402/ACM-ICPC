#include<cstdio>
#include<vector>
using namespace std;
int main(){
	int Count,temp;
	while(scanf("%d",&Count)!=EOF){
		vector<int> coordinate;
		vector<int> Numbers;
		Numbers.reserve(Count);
		coordinate.reserve(Count);
		for(int i = 0;i < Count;++i){
			scanf("%d",&temp);
			Numbers.push_back(temp);
		}
		coordinate.push_back(Numbers[0]);
		for(int i = 1;i < Count;++i){
			int lis = 0;
			while(lis != coordinate.size() && coordinate[lis] < Numbers[i])
				++lis;
			if(lis == coordinate.size()){
				coordinate.push_back(Numbers[i]);
			}else{
				if(coordinate[lis] > Numbers[i]) coordinate[lis] = Numbers[i];
			}
		}
		printf("%d\n",coordinate.size());
	}
	return 0;
}
