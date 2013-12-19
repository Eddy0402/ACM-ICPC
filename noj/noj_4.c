#include<stdio.h>

int main(void){
	int i;
	long long a;

	while(scanf("%d",&i) != EOF){
		for(a=1;i>0;i--)a*=i;
		 printf("%lld\n",a);
	}
	return 0;
}
