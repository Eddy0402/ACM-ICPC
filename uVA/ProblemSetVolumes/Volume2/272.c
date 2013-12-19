#include<stdio.h>
int main(void){
    char a;
    int sign=1;
    while((a=getchar()) != EOF){
        if(a == '\"')
            if(!sign) { putchar('\'');putchar('\''); sign = 1; }
            else { putchar('`'); putchar('`'); sign = 0; }
        else
            putchar(a);
    }
    return 0;
}
