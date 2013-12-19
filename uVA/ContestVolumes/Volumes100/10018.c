#include<stdio.h>
unsigned reverse(unsigned data){
    unsigned result = 0;
    while(data != 0){
        result = result * 10 + (data % 10);
        data /= 10;
    }
    return result;
}
int main(void){
    int testPoints,time;
    unsigned input,temp,result;
    scanf("%d",&testPoints);
    while(testPoints--){
        scanf("%u",&input);
        time = 0;
        for(;;){
            result = reverse(input);
            if(result == input)break;
            input += result;        
            time++; 
        }    
        printf("%d %u\n",time,result);
    }
    return 0;
}
