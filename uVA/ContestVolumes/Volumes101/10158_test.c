#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
	int a = 150;	
	srand(time(NULL));
	printf("10\n");
	while(a--){
		printf("%d ",rand() % 4 + 1);
		printf("%d %d\n",rand() % 10,rand() %10);
	}
	return 0;
}
