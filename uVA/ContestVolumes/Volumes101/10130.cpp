#include<cstdio>
#include<cstring>
int OPrice[1010];
int OWeight[1010];
int result[50];

int MaxWeight(int p,int Object){
	memset(result,0,(p+1) * sizeof(int));
	for(int o = 0;o < Object;++o){
		for(int i = p ; i >= OWeight[o] ;--i){
			if( result[i] < result[i - OWeight[o]] + OPrice[o] ){
				result[i] = result[i - OWeight[o]] + OPrice[o];
			}
		}
	}
	return result[p];
}

int main(){
	int TestCase;
	scanf("%d",&TestCase);
	OWeight[0] = 0;
	while(TestCase--){
		int Object,result = 0;
		scanf("%d",&Object);
		for(int i = 0;i < Object;++i){
			scanf("%d%d",&OPrice[i],&OWeight[i]);
		}
		int People,p;
		scanf("%d",&People);
		while(People--){
			scanf("%d",&p);
			result += MaxWeight(p,Object);
		}
		printf("%d\n",result);
	}
	return 0;
}
