#include<stdio.h>
unsigned subset[80];
unsigned numOfSubset(int num){
    if(subset[num] != 0)return subset[num];
    if(num == 1 || num == 2)return num;
    if(num == 3 )return 2;
    subset[num] = numOfSubset(num - 2) + numOfSubset(num - 3);
    return subset[num];
}

int main(void){
   int i,input;
   for(i = 0;i<80;i++)subset[i] = 0;
   while(scanf("%d",&input) != EOF)printf("%u\n",numOfSubset(input));
   return 0;
}
