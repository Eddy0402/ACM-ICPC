#include<cstdio>
#include<cstring>
int R,C,E;

int RLink[1005],LLink[1005],pass[1005];
int RRLink[1005],LLLink[1005];
int edge[1005][1005]; // gophere to hole
int No = -1; // memset -1

bool FindRight(int Left,int *rr,int *ll){
	for(int r = 0;r < C;++r){
		if( edge[Left][r] && !pass[r] ){
			pass[r] = 1;
			if(rr[r] == No || FindRight(rr[r],rr,ll)){
				rr[r] = Left;
				ll[Left] = r;
				return true;
			}
		}
	}
	return false;
}
int main(){
	while(scanf("%d%d%d",&R,&C,&E)!= EOF){
		if(!R && !C && !E)break;
		int a,b;
		memset(edge,0,sizeof(edge));
		int result = 0;
		for(int i = 0;i < E;++i){
			scanf("%d%d",&a,&b);
			edge[a-1][b-1] = 1;
		}
		memset(RLink,-1,sizeof(RLink));
		memset(RRLink,-1,sizeof(RRLink));
		memset(&No,-1,sizeof(No));
		for(int i = 0;i < R;++i){
			memset(pass,0,sizeof(pass));
			if(FindRight(i,RLink,LLink)) ++result;
		}
		printf("%d",result);
		for(int i = 0;i < R;++i){
			if(LLink[i] == No){
				memset(pass,0,sizeof(pass));
				F(i,RRLink,LLLink);
			}
		}
		puts("");
	}
	return 0;
}

