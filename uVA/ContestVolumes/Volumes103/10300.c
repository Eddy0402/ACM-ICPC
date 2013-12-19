#include<stdio.h>
int main(void){
    int testPoints;
    int count,dataA,dataB,i,j,result,none;
    scanf("%d",&testPoints);
    for( /* empty */ ; 0 < testPoints; testPoints--){
        scanf("%d",&count);
        result = 0;
        for(i=0;i<count;i++){
            scanf("%d %d %d", &dataA, &none , &dataB);
            result = result + dataA * dataB;   
        }  
        printf("%d\n",result);
    }
    return 0;
}
