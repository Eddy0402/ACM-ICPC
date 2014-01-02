#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char data[2002][75 + 1];
int compare(const void *a,const void *b){
    return strcmp((char *)a,(char *)b);
}
int main(void){
    int testPoints,i,temp = 1;
    scanf("%d",&testPoints);
    for(i = 0; i < testPoints; i++)
        scanf("%s%*[^\n]",&data[i][0]);
    qsort(data,testPoints,sizeof(char) * 76,compare);
    for(i = 0; i< testPoints; i++){
        if(i != testPoints - 1){
            if(strcmp(&data[i][0],&data[i+1][0]) == 0){
                temp++;
            }else{
                printf("%s %d\n",&data[i][0],temp);
                temp = 1;
            }     
        }else{
            printf("%s %d\n",&data[i][0],temp);
            temp = 1;
        }
    }
    return 0;
}
