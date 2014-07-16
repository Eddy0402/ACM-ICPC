#include<cstdio>
#include<vector>
using namespace std;
int main(){
	int Number,temp;
	while(scanf("%d",&Number) != EOF && Number){
		vector<int> numbers;
		numbers.reserve(Number);
		bool lose = true;
		while(Number--){
			scanf("%d",&temp);
			numbers.push_back(temp);
			if(temp > 0)lose = false;
		}
		int result=0,now=0;
		if(!lose)
			for(int i = 0;i < numbers.size();++i){
				now += numbers[i];
				if(now < 0){
					now = 0;
				}else{
					if(now > result)result = now;
				}
			}
		if(lose) puts("Losing streak.");
		else printf("The maximum winning streak is %d.\n",result);		
	}
	return 0;
}
