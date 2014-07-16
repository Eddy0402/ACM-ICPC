#include<cstdio>
int tra[355][355];
int main(){
	int Height;
	while(scanf("%d",&Height)!=EOF){
		for(int i = 1;i <= Height;++i){
			for(int j = 1;j <= i;++j){
				scanf("%d",&tra[i][j]);
			}
		}
		for(int i = Height-1;i >= 1 ;--i){
			for(int j = 1;j <= i;++j){
					int a = tra[i][j] + tra[i+1][j+1];
					int b = tra[i][j] + tra[i+1][j];
					tra[i][j] = a > b ? a : b;
			}
		}
		printf("%d\n",tra[1][1]);
	}
	return 0;
}
