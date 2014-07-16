#include<cstdio>
#include<vector>
using namespace std;
int result[310][310];
int main(){
	int TestCase;
	scanf("%d",&TestCase);
	while(TestCase--){
		int M,S,temp,temp2;
		scanf("%d%d",&M,&S);
		const int S2 = S * S;
		vector<int> v1,v2;
		for(int i = 0;i < M;++i){
			scanf("%d%d",&temp,&temp2);
			v1.push_back(temp);
			v2.push_back(temp2);
		}
		for(int i = 0;i <= S;++i)
			for(int j = 0;j <= S;++j)
				result[i][j] = 2147483647;
		result[0][0]=0;

		for(int i = 0;i < M;++i){
			for(int s1 = v1[i];s1 <= S;++s1)
				for(int s2 = v2[i];s2 <= S;++s2)
					if(result[ s1-v1[i] ][ s2-v2[i] ] != 2147483647){
						result[s1][s2] = std::min(result[s1][s2],result[s1-v1[i]][s2-v2[i]] + 1);
					}
		}
		int res = 2147483647;
		bool possible = false;
		for(int i = 0;i <= S;++i)
			for(int j = 0;j <= S;++j)
				if(i*i+j*j == S2 && result[i][j] != -1 && res > result[i][j]){
					res = result[i][j];
					possible = true;
				}
		if(possible)
			printf("%d\n",res);
		else
			puts("not possible");
	}
	return 0;
}
