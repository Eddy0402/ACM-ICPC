#include<stdio.h>
int main(void){
    int a,b;
    while(2==scanf("%d%d",&a,&b)){
	switch((a*2+b)%3){
	    case 0:puts("普通");break;
	    case 1:puts("吉");break;
	    case 2:puts("大吉");break;
	}
    }
    return 0;
}
