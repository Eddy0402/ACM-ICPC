#include<stdio.h>

int main(void){
    int testPoints,i;
    long long *a,*b;
    scanf("%d",&testPoints);
    a = malloc(sizeof(long long) * testPoints);
    b = malloc(sizeof(long long) * testPoints);
    int(i=0;i<testPoints;i++){
        scanf("%lld %lld",a+i,b+i);
        
        
    }
    return 0;
}
