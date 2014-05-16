#include<cstdio>
int main(){
	int TestCase,Case = 1;
	scanf("%d",&TestCase);
	while(TestCase--){
		int N;
		scanf("%d ",&N);
		char First[150],input,mustHave[150];
		int mustHaveCount[150] = {};
		int mustHaveCountOther[150] = {};
		int mustHaveCountOtherThis[150] = {};
		int index = 0,K = 0;
		while((input = getchar()) != '\n'){
			if(index == 0){
				mustHave[0] = input;
				mustHaveCount[0] = 1;
			}else{
				if(First[index-1] == input){
					++mustHaveCount[K];
				}else{
					++K;
					++mustHaveCount[K];
					mustHave[K] = input;
				}
			}
			First[index] = input;
			++index;
		}

		bool Lose = false;
		while(--N){
			int match = 0;
			while((input = getchar()) != '\n'){
				if(match <= K && input != mustHave[match]){
					if(mustHaveCountOtherThis[match] != 0)
					    ++match;
				}
				if(match > K || input != mustHave[match]){
					Lose = true;
				}
				++mustHaveCountOther[match];
				++mustHaveCountOtherThis[match];
				++index;
			}
			if(match != K)Lose = true;
		}
		printf("Case #%d: ",Case++);
		if(Lose) puts("Fegla Won");
		else{
			int result = 0;
			for(int i = 0;i <= K;++i){
				int a = mustHaveCountOther[i] - mustHaveCount[i];
				if(a < 0)a = -a;
				result += a;
			}
			printf("%d\n",result);
		}
	}
	return 0;
}
