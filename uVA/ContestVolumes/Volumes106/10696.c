#include<stdio.h>
int f91(int N){
	return N > 100 ? N - 10 : f91(f91(N+11));
}
int main(void){
    int a;
	while(scanf("%d",&a) != EOF){
		if(a == 0)break;
		printf("f91(%d) = %d\n",a,f91(a));
	}
	return 0;
}
