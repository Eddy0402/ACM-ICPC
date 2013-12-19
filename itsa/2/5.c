#include<stdio.h>
#include<string.h>
int main(void){

   int element[100];
   char ch[1000];
   int current, result, tail,i;
   int sign=0,a;
    
   for(;;){
       i=0;
       if(gets(ch)==NULL)break;
       if(feof(stdin))break;
       for(;;){
           if((a=sscanf(ch,"%d %[1234567890 -]",&element[i++],ch))==1)break;
           if(a==0){ break; sign=1;}
       } 
       if(sign)continue;
       result = 0;
       current = 0;
       tail = i-1;
       for(i = i-1; i >= 0; i--){
           current += element[i];
           if(current < 0){
               current=0;
               tail = i-1;
               continue;
           }
           if(current > result)result = current;
       }  
       printf("%d\n",result);
   }

   return 0;
}
