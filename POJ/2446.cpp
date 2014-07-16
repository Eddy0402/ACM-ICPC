#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
int Rows,Cols,Hole;

int RxLink[33][33];
int RyLink[33][33];
int pass[33][33];
int edge[33][33][33][33];
int table[33][33];
int No = -1; // memset -1

struct Point{
	Point(int X,int Y):x(X),y(Y){}
	int x,y;
};

bool FindRight(int Lx,int Ly){
	static int AA[][2] = {{1,0},{-1,0},{0,1},{0,-1}};
	for(int r = 0;r < 4;++r){
		int Rx = Lx + AA[r][0];
		int Ry = Ly + AA[r][1];
		if(Rx < 0 || Rx >= Cols || Ry < 0 || Ry >= Rows)continue;

		if( edge[Lx][Ly][Rx][Ry] && !pass[Rx][Ry] ){
			pass[Rx][Ry] = 1;
			if(RxLink[Rx][Ry] == No || FindRight(RxLink[Rx][Ry],RyLink[Rx][Ry])){
				RxLink[Rx][Ry] = Lx;
				RyLink[Rx][Ry] = Ly;
				return true;
			}
		}
	}
	return false;
}
int main(){
	while(scanf("%d%d%d",&Rows,&Cols,&Hole) != EOF){
		int x,y;
		memset(table,0,sizeof(table));
		for(int i = 0;i < Hole;++i){
			scanf("%d%d",&x,&y);
			table[x-1][y-1] = 1;
		}
		int Result = true;
		if( (Rows * Cols - Hole) % 2 == 1 )Result = false;
		if(Result){
			vector<Point> Left;
			memset(edge,0,sizeof(edge));
			for(int i = 0;i < Cols;++i){
				for(int j = 0;j < Rows;++j){
					if( (i + j) % 2 == 1 && !table[i][j]){
						Left.push_back(Point(i,j));
					}
					if(!table[i][j]){
						if(i != 0 && !table[i-1][j] )edge[i][j][i-1][j] = 1;
						if(i != 0 && !table[i-1][j] )edge[i-1][j][i][j] = 1;
						if(j != 0 && !table[i][j-1] )edge[i][j][i][j-1] = 1;
						if(j != 0 && !table[i][j-1] )edge[i][j-1][i][j] = 1;
					}
				}
			}
			if(Left.size() * 2 != Rows * Cols - Hole){
				Result = false;
			}else{
				int result = 0;
				memset(RyLink,-1,sizeof(RyLink));
				memset(RxLink,-1,sizeof(RxLink));
				memset(&No,-1,sizeof(No));
				for(int i = 0;i < Left.size();++i){
					memset(pass,0,sizeof(pass));
					if(!FindRight(Left[i].x,Left[i].y)){
						Result = false;
						break;
					}
				}
			}
		}
		if(Result){
			puts("YES");
		}else{
			puts("NO");
		}
	}
	return 0;
}

