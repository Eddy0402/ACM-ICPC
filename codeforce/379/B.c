#include<stdio.h>
#include<string.h>
int remains;
int have[302];
int pos[302];

int testPoints,i,j=0,k;
int current = 0;
int total=0;
int temp;
int dest;

void removee(int num){
    have[num]--;
    if(have[num] == 0){
       j--;
       memmove(have+num,have+num+1,j-num-1);
    }
}
int findNext(int num){
    if(num == 0)return 1;
    if(num == j)return j-1;
    else return pos[num] - pos[num-1] > pos[num+1] - pos[num] ? num+1 : num-1;
}
int main(void){
    scanf("%d",&testPoints);
    for(i=0;i<testPoints;i++){
       scanf("%d",&remains);
       if(remains){
           have[j]=remains;
           pos[j]=i;
           total += remains;
           j++;
       }
    }
   printf("j:%d\n",j);
    while(total--){
       removee(current);
       temp = findNext(current);
       printf("\nj: %d temp: %d pos: %d\n",j,temp,pos[temp]);
       dest = pos[temp] - pos[current] > 0 ? pos[temp] - pos[current] : pos[current] - pos[temp];
      // printf("\ndest: %d\n",temp);
       //for(k=0;k<temp;temp++)putchar('R');
       current = temp;
       putchar('P');
    }
    putchar('\n');
    return 0;
}
