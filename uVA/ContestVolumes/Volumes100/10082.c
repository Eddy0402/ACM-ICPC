#include<stdio.h>
#include<string.h>
int main(void){
    char keys[] = "QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./`1234567890-=";
    int a;
    char *temp;
    while(EOF != (a = getchar())){
        if( (temp = strchr(keys,a)) != NULL )putchar(*(temp-1));
        else putchar(a);    
    }
    return 0;
} 
