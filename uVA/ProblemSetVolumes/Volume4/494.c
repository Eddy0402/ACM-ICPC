#include <stdio.h>
int main(void){
    char input[10000],temp;
    int i, sign, result;
    while(fgets(input,9999,stdin) != NULL){
        result = 0;
        for(i = 0,sign = 0; /* empty */ ;i++){
            if((temp = input[i]) == '\0')break;
            if( (temp >= 'a' && temp <= 'z') || (temp >= 'A' && temp <= 'Z') ){
                if(sign == 0){
                    sign = 1;
                    result ++; 
                }
            }
            else sign = 0;
        }  
        printf("%d\n",result);
    }
    return 0;
}
