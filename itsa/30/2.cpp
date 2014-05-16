#include<cstdio>
int Ma[25][25];
int main(){
	int R;
	while(scanf("%d",&R)!=EOF){
		int R1=R,R2=0,R3=10000,R4=10000;
		for(int i = 0;i < R;++i){
			int temp = 0;
			for(int j = 0;j < R;++j){
				scanf("%d",&Ma[i][j]);
				if(Ma[i][j] == 1){
					++R3;
					++temp;
					++R2;
				}
			}
			if(temp < R3)R3 = temp;
		}
		for(int i = 0;i < R;++i)
			for(int j = 0;j < R;++j)
				if(Ma[i][j] == 0) Ma[i][j] = 99999;
		for (int k = 0;k < R;++k)
			for(int i = 0;i < R;++i)
				for(int j = 0;j < R;++j)
					if(Ma[i][k] + Ma[k][j] < Ma[i][j])
						Ma[i][j] = Ma[i][k] + Ma[k][j];
		for(int i = 0;i < R;++i)
			for(int j = 0;j < R;++j)
				if(R4 > Ma[i][j])R4 = Ma[i][j];
		R2/=2;
		printf("%d %d %d %d\n",R1,R2,R3,R4);
		
	}
	return 0;
}
