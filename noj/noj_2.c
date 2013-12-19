#include<stdio.h>

int main(void){
	long long int a,b;
	while(scanf("%lld %lld",&a,&b) == 2)printf("%lld\n",b-a > 0 ? b-a : a-b);
	return 0;
}
