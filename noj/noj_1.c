#include<stdio.h>

int main(void){

	int a.b;
 	int temp;

	while(scanf("%d%d",&a,&b) != EOF){
		for(;;){
			a = b % a;
			if(a == 0)break;
			temp = a;
			a = b;
			b = temp;
		}
		printf("%d",b);
	}
	return 0;`
}
