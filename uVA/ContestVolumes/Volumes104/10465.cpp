#include<cstring>
#include<cstdio>
int result[10005];
int exact[10005];
int main(){
	int m,n,t;
	while(scanf("%d%d%d",&m,&n,&t) != EOF){
		memset(result,0,sizeof(int) * (t + 1));
		memset(exact,0,sizeof(int) * (t + 1));
		exact[0] = true;
		for(int o = 0;o < 2;++o){
			int Burger = o ? m : n;
			for(int i = Burger;i <= t;++i){
				if(exact[i - Burger] && result[i] < result[i - Burger] + 1){
					result[i] = result[i - Burger] + 1;
					exact[i] = true;
				}
			}
		}
		for(int i = t;i >=0;--i){
			if(exact[i]){
				if(i == t)
					printf("%d\n",result[i]);
				else 
					printf("%d %d\n",result[i],t-i);
				break;
			}
		}

	}
	return 0;
}
