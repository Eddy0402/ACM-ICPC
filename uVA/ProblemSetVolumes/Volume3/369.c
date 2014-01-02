#include<stdio.h>
int gcd(int a,int b){
    if(b == 0)return a;
    return gcd(b, a % b);
}
int main(void){
    int M,N,MM;
    int i,j,num;
    unsigned result[100],temp,cd;
    unsigned long long result_sum;
    while(scanf("%d%d",&N,&MM) != EOF){
	if(N == 0 || MM == 0)break;
        if(MM > N / 2) M = N - MM;
        else M = MM;
	for(i = 0;i < 100; i++)
	    result[i] = 1U;
        num = 0;
	for(i = N - M + 1;i <= N; i++){
	    if((result[num] * i )/ i == result[num])
		result[num] = result[num] * i;
	    else{
		num++;
		i--;
	    }
	}
	for(i = 2;i <= M ; i++){
            temp = i;
	    for(j = 0;temp != 1;j++){
                cd = gcd(temp,result[j]);
		result[j] /= cd;
                temp /= cd;
 	    }	
        }
        result_sum = 1;
	for(i = 0;i <= num;i++)
	    result_sum *= result[i];
	printf("%d things taken %d at a time is %llu exactly.\n",N,MM,result_sum);
    }
    return 0;
}
