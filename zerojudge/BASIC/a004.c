#include<stdio.h>
int main(void){
    int a;
    while(scanf("%d",&a)!=EOF){
	if((a % 4 == 0 && a % 100 != 0) || a % 400 == 0)puts("閏年");
	else puts("平年");
    }
    return 0;
}
