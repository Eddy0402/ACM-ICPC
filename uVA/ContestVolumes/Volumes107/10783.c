#include<stdio.h>
int main(void){
    int testCases,i,a,b,result;
    scanf("%d",&testCases);
    for(i=1;i<=testCases;i++){
        scanf("%d%d",&a,&b);
        if(a % 2 == 0)a++;
        if(b % 2 == 0)b--;
        result = (a + b) * (b - a + 2) / 4;
        printf("Case %d: %d\n",i,result);
    }
    return 0;
}
