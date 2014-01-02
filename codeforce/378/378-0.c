#include<stdio.h>
int main(void){
    int a,b,test;
    int aD=0,bD=0,temp,draw = 0;
    scanf("%d %d",&a,&b);
    for(test=1;test<=6;test++){
        if((temp = (a > test ? a-test: test-a) - (b > test ? b- test:test-b)) > 0)aD++;
        else if(temp == 0)draw++;
        else bD++;
    }
    printf("%d %d %d\n",bD,draw,aD);
    return 0;
}
