#include<stdio.h>
unsigned getMod(unsigned B,unsigned powerByTwo,unsigned M){
	unsigned temp;
	if(powerByTwo == 1)return B;
	else if(powerByTwo == 0)return 1;
	temp = getMod(B, powerByTwo - 1, M);
	return (unsigned)((temp * (unsigned long long)temp) % M);
}
int main(void){
	unsigned B,P,M,mask,result,i;
	while(scanf("%u%u%u",&B,&P,&M) != EOF){
		result = 1;
		mask = 1u << 31;
		i = 32;
		do{
			result = (int)((result * (unsigned long long)getMod(B, (P & mask) ? i : 0, M)) % M);
			i--;
		}while((mask >>= 1));
		printf("%u\n",result);
	}
	return 0;
}
