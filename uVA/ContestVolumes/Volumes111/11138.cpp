#include<cstdio>
#include<cstring>
int N,M,K;

int RLink[500],pass[500];
int edge[500][500]; 
int No = -1; // memset -1

bool FindRight(int Left){
	for(int r = 0;r < K;++r){
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
	scanf("%d",&N);
	for(int Case = 1;Case <=N;++Case){
		scanf("%d%d",&M,&K);
		int a;
		memset(edge,0,sizeof(edge));
		for(int i = 0;i < M;++i){
			for(int j = 0;j < K;++j){
				scanf("%d",&edge[i][j]);
			}
		}
		int result = 0;
		memset(RLink,-1,sizeof(RLink));
		memset(&No,-1,sizeof(No));
		for(int i = 0;i < M;++i){
			memset(pass,0,sizeof(pass));
			if(FindRight(i)) ++result;
		}
		printf("Case %d: ",Case);
		printf("a maximum of %d nuts and bolts ",result);
		printf("can be fitted together\n");
	}
	return 0;
}

