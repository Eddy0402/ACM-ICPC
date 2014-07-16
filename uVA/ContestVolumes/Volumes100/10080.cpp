#include<cstdio>
#include<cstring>
#include<cmath>
int Gophere,Hole,Time,V;
struct Point{ double x,y; };
Point gophere[105], hole[105];
int hLink[105],pass[105];
int edge[105][105]; // gophere to hole
int No = -1; // memset -1


bool FindRight(int Left){
	for(int r = 0;r < Hole;++r){
		if( edge[Left][r] && !pass[r] ){
			pass[r] = 1;
			if(hLink[r] == No || FindRight(hLink[r])){
				hLink[r] = Left;
				return true;
			}
		}
	}
	return false;
}
int main(){
	while(scanf("%d",&Gophere)!=EOF){
		scanf("%d%d%d",&Hole,&Time,&V);
		double maxDistance_pow2 = Time * V * Time * V;
		for(int i = 0;i < Gophere;++i){
			scanf("%lf%lf",&gophere[i].x,&gophere[i].y);
		}
		for(int i = 0;i < Hole;++i){
			scanf("%lf%lf",&hole[i].x,&hole[i].y);
		}
		for(int i = 0;i < Gophere;++i){
			for(int j = 0;j < Hole;++j){
				if( pow(hole[j].x - gophere[i].x,2) + pow(hole[j].y - gophere[i].y,2) <= maxDistance_pow2 )
					edge[i][j] = 1;
				else
					edge[i][j] = 0;
			}
		}
		int result = Gophere;
		memset(hLink,-1,sizeof(hLink));
		memset(&No,-1,sizeof(No));
		for(int i = 0;i < Gophere;++i){
			memset(pass,0,sizeof(pass));
			if(FindRight(i)) --result;
		}
		printf("%d\n",result);
	}
	return 0;
}
