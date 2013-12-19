#include<stdio.h>
int main(void){
    unsigned long long a,b;
    while(scanf("%llu%llu",&a,&b) != EOF )printf("%llu\n", b>a ?  b-a : a-b);
    return 0;
}
