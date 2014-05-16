#include<vector>
#include<cstdio>
#include<cstring>
using namespace std;
int N,RLink[105],RRLink[150],pass[105],p[105],edge[105][105]; // gophere to hole
int No = -1; // memset -1
struct Slide{
	Slide(int x1,int x2,int y1,int y2) : X1(x1),X2(x2),Y1(y1),Y2(y2){}
	int X1,X2,Y1,Y2;
	bool inside(int x,int y){
		return X1 < x && x < X2 && Y1 < y && y < Y2;
	}
};
bool FindRight(int Left,int *RLink){
	for(int r = 0;r < N;++r){
		if( edge[Left][r] && !pass[r] ){
			pass[r] = 1;
			if(RLink[r] == No || FindRight(RLink[r],RLink)){
				RLink[r] = Left;
				return true;
			}
		}
	}
	return false;
}
int main(){
	int Case = 1;
	while(scanf("%d",&N) && N){
		int a,b,c,d,x,y;
		memset(edge,0,sizeof(edge));
		vector<Slide> Slides;
		for(int i = 0;i < N;++i){
			scanf("%d%d%d%d",&a,&b,&c,&d);
			Slides.push_back(Slide(a,b,c,d));
		}
		for(int i = 0;i < N;++i){
			scanf("%d%d",&x,&y);
			for(int j = 0;j < N;++j){
				if(Slides[j].inside(x,y))
					edge[i][j] = 1;
			}
		}
		int result = 0;
		memset(RLink,-1,sizeof(RLink));
		memset(p,0,sizeof(p));
		memset(&No,-1,sizeof(No));
		bool sol = true;
		for(int i = 0;i < N;++i){
			memset(pass,0,sizeof(pass));
			if(FindRight(i,RLink)) ++result;
		}
		int res = result;
		if(result == N){
			for(int i = 0;i < N;++i){
				memset(RRLink,-1,sizeof(RRLink));
				int result2=0;
				edge[RLink[i]][i] = 0;
				for(int j = 0;j < N;++j){
					memset(pass,0,sizeof(pass));
					if(FindRight(j,RRLink)) ++result2;
				}
				if(result2 == result){
					--res;
				}else{
					p[i] = 1;
				}
				edge[RLink[i]][i]= 1;
			}
		}
		printf("Heap %d\n",Case++);
		if(res){
			bool flag = true;
			for(int i = 0;i < N;++i){
				if(p[i])
					if(flag){
						printf("(%c,%d)",i+'A',1+RLink[i]);
						flag = false;
					}else
						printf(" (%c,%d)",i+'A',1+RLink[i]);
			}
			puts("");
		}else
			puts("none");
		puts("");
	}
	return 0;
}

