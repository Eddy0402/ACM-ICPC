#include<stdio.h>
int distribution(int M,int N){
    if(M < 0 || N <= 0)return 0;
    if(M == 0)return 1;
    return distribution(M,N-1) + distribution(M-N,N);
}
int main(void){
    int testPoints;
    int M,N;
    scanf("%d",&testPoints);
    while(testPoints--){
	scanf("%d%d",&M,&N);
	printf("%d\n",distribution(M,N));
    }
    return 0;
}
