#include<cstdio>
#include<cstring>
int N,K;

int RLink[505],pass[505];
int edge[505][505]; // gophere to hole
int No = -1; // memset -1

bool FindRight(int Left){
	for(int r = 0;r < N;++r){
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
	while(scanf("%d",&N)!= EOF){
		scanf("%d",&K);
		int a,b;
		memset(edge,0,sizeof(edge));
		int result = 0;
		for(int i = 0;i < K;++i){
			scanf("%d%d",&a,&b);
			edge[a-1][b-1] = 1;
		}
		memset(RLink,-1,sizeof(RLink));
		memset(&No,-1,sizeof(No));
		for(int i = 0;i < N;++i){
			memset(pass,0,sizeof(pass));
			if(FindRight(i)) ++result;
		}
		printf("%d\n",result);
	}
	return 0;
}

