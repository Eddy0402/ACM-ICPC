#include<stdio.h>
int main(void){
    int a,b,result=0,temp=0;
    scanf("%d%d",&a,&b);
    while(a>0){
        result += a;
        temp += a;
        a = 0;
        a = temp / b;
        temp = temp - a * b;
    }
    printf("%d\n",result);
    return 0;
}
