#include<stdio.h>
int main(void){
    int N,i,j,result;
    int data[1004];
    register int temp;

    while( scanf("%d",&N) != EOF ){
        for(i=0;i<N;i++)scanf("%d",data+i);
        result = 0;
        for(i=N-1;i>0;i--){
            for(j=0;j<i;j++){
                if(data[j] > data[j+1]){
                    temp=data[j];   
                    data[j]=data[j+1];
                    data[j+1]=temp;
                    result++;
                }
            }
        }
        printf("Minimum exchange operations : %d\n",result);
    }
    return 0;
}
