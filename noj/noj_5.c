#include<stdio.h>
#include<string.h>
int main(void){

	char a[20];
	int point;
	for(;;){
		gets(a);	
		if(a== NULL || feof(stdin))break;
		if(a[0] == '\n')break;
		for(point = strlen(a) - 1;point >= 0;point--)if(a[point]!='0')break;
		if(point <0)putc('0',stdout);
		else for(;point >= 0;point--){
			putc(a[point] , stdout);
		}
		putc('\n',stdout);
	}
	return 0;
}
