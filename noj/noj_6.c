#include<stdio.h>
#include<stdlib.h>
int main(void){

    int n,m;
    int testdata,result;

    scanf("%d%d",&n,&m);
    const m2 = m * 2;
    int *data = malloc(sizeof(int) * m2);
    int *a,*b;

    for(testdata=1;testdata<=n;testdata++){
	result = 0;
	a = data;
	while(a-data < m2)scanf("%d",a++);
	
	for( a = data , b = data+m ; a < data+m && b < data+m2 ;){
	    if(*a == *b){
		a++;
		b++;
		result++;
	    }else if(*a > *b){
		b++;
	    }else if(*a < *b){
		a++;
	    }
	}
	printf("%d\n",result);
    }
    return 0;
}
