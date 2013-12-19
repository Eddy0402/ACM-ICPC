#include<stdio.h>
int main(void){
    long long a,b,carry;
    int result;
    while(scanf("%lld%lld",&a,&b) != EOF){
	if( a==b && a==0LL )break;
        result = 0;
        carry = 0LL;
        while(1){
           if( (a % 10LL) + (b % 10LL) + carry >= 10LL ){
               result++;
               a/=10LL;
               b/=10LL;
               carry = 1LL;
           }else{
               a/=10LL;
               b/=10LL;
               carry = 0LL;
           }
           if( a==0LL && b==0LL )break;
        }
        if(result == 0) puts("No carry operation.");
        else if(result == 1) puts("1 carry operation.");
        else printf("%d carry operations.\n",result);
    }
    return 0;
}
