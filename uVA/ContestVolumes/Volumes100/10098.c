#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int inputLen;
void print(char procceed[],char toPrint[],int procceedCharCount,int toPrintCount){
    int charToPut;
    char *nextToPrint;
    if(toPrintCount == 0){
        *(procceed + procceedCharCount) = '\0';
        printf("%s\n",procceed);
        return;
    }
    *(procceed + procceedCharCount) = toPrint[0];
    print(procceed, toPrint + 1, procceedCharCount + 1, toPrintCount - 1);
    for(charToPut = 1;charToPut < toPrintCount ;charToPut++){
        if(toPrint[charToPut] == toPrint[charToPut-1])continue;
        nextToPrint = malloc(sizeof(char)*toPrintCount);
        *(procceed + procceedCharCount) = toPrint[charToPut];
        strncpy(nextToPrint, toPrint, charToPut);
        strncpy(nextToPrint + charToPut,toPrint + charToPut + 1,toPrintCount - charToPut - 1);
        print(procceed, nextToPrint, procceedCharCount + 1, toPrintCount - 1);
    }
}
int compare(const void *a,const void *b){
    return *(char *)a - *(char *)b;
}
int main(void){
    int testPoints;
    char input[12];
    char *a;
    scanf("%d ",&testPoints);
    while(testPoints--){
        scanf("%s",input);
        inputLen = strlen(input);
        qsort(input,inputLen,sizeof(char),compare);
        a = malloc(sizeof(char)*inputLen);
        print(a,input,0,inputLen);
        puts("");
    }
    return 0;
}
