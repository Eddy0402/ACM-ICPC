#include<stdio.h>

int main(void){
    char input;
    int a,b,sign;
    for(;;){
       sign = 0 , b = 0;
       a = (input=getchar())-'0';
       if(a==0) break; else putchar(input);
       while((input=getchar())!='\n'){
          putchar(input);
          if(0 == sign){
              b += (input-'0');
              sign = 1;
          }
          else{
              a+= (input - '0');
              sign = 0; 
          }  
       }
       if( (a-b) % 11 == 0 ) puts(" is a multiple of 11.");
       else puts(" is not a multiple of 11.");
    }
    return 0;
}
