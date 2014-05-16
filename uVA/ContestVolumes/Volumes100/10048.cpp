#include<cstdio>
int sound[110][110];
int main(){
	int C,S,Q,Blank,A,B,D,Case=1;
	while(scanf("%d%d%d",&C,&S,&Q) && !(C == 0 && S == 0 && Q == 0)){
		if(Case != 1)puts("");
		for(int i = 1;i <= C;++i)
			for(int j = 1;j <= C;++j)
				sound[i][j] = 9999999;
		for(int i = 0;i < S;++i){
			scanf("%d%d%d",&A,&B,&D);
			sound[A][B] = D;
			sound[B][A] = D;
		}
		//Floyd
		for(int M = 1;M <= C;++M)
			for(int i = 1;i <= C;++i)
				for(int j = 1;j <= C;++j)
					if(sound[i][j] > sound[M][j] && sound[i][j] > sound [i][M])
						sound[i][j] = sound[M][j] > sound[i][M] ? sound[M][j] : sound[i][M];
		printf("Case #%d\n",Case++);
		while(Q--){
			scanf("%d%d",&A,&B);
			if(sound[A][B] == 9999999)puts("no path");
			else printf("%d\n",sound[A][B]);
		}
	}
	return 0;
}
