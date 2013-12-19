#include<stdio.h>

int main(void){

	int a,b,temp;

	while(scanf("%d%d",&a,&b) == 2){
		if( a == 1 || b == 1){ puts("1");continue; }
		for(;;){
			temp = b % a;
			if(temp == 0)break;
			b = a;
			a = temp;
		}
		printf("%d\n",a);
	}
	return 0;
}
