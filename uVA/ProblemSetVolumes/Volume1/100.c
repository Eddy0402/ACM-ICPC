#include<stdio.h>
int maxCycleLength(int number){
    int result = 1;
    while(number != 1){
	if(number % 2 == 1)number = number * 3 + 1;
	else number /= 2;
	result ++;
    }
    return result;
}

int main(){
    int i,j,k,result,temp;
    while(scanf("%d%d",&i,&j) != EOF){
	result = 0;
	printf("%d %d ",i,j);
	if(i<=j)
	    for(k=i;k<=j;k++){
		temp = maxCycleLength(k);
		if(temp > result)result = temp;
	    }
        else
	    for(k=j;k<=i;k++){
		temp = maxCycleLength(k);
		if(temp > result)result = temp;

	    }
	printf("%d\n",result);
    }
    return 0;
}
