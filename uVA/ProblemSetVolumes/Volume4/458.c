#include<stdio.h>
int main(void){
    char input[10000];
    int i;
    while(scanf("%s",input) != EOF){
        i=0;
        while(1){
            if(input[i] == '\0')break;
            putchar(input[i]-7);
            i++;
        }
        puts("");
    }
    return 0;
}
