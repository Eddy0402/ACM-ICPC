#include <stdio.h>  
#include <string.h>  
int dp[77],n; 
int main(void){
	register int i;
	dp[0] = dp[1] = 1;
	dp[2] = 2;  
	for (i = 3; i <= 76; i ++)
		dp[i] = dp[i - 3] + dp[i - 2]; 
	while (scanf("%d", &n) != EOF)
		printf("%d\n", dp[n]);  
	return 0;  
}
