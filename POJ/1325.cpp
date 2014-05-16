#include<cstdio>
#include<cstring>
int N,M,K;

int RLink[105],pass[105];
int edge[105][105]; // gophere to hole
int No = -1; // memset -1

bool FindRight(int Left){
	for(int r = 0;r < M;++r){
		if( edge[Left][r] && !pass[r] ){
			pass[r] = 1;
			if(RLink[r] == No || FindRight(RLink[r])){
				RLink[r] = Left;
				return true;
			}
		}
	}
	return false;
}
int main(){
	while(scanf("%d",&N) && N){
		scanf("%d%d",&M,&K);
		int a,b;
		memset(edge,0,sizeof(edge));
		for(int i = 0;i < K;++i){
			scanf("%*d%d%d",&a,&b);
			if(a == 0 || b == 0)continue;
			edge[a][b] = 1;
		}
		int result = 0;
		memset(RLink,-1,sizeof(RLink));
		memset(&No,-1,sizeof(No));
		for(int i = 1;i < N;++i){
			memset(pass,0,sizeof(pass));
			if(FindRight(i)) ++result;
		}
		printf("%d\n",result);
	}
	return 0;
}

