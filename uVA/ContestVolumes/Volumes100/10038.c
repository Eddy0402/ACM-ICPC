#include<stdio.h>
int main(void){
    int count,input[3001],diff[3001],difference,i,result;
    while(scanf("%d",&count) != EOF){
	if(count == 1){
	    puts("Jolly");
            scanf("%d",&count);
	    continue;
	}
        for(i=0;i<count;i++){
            scanf("%d",&input[i]);
            diff[i] = 0;
        }
	result = 1;
	for(i=1;i<count;i++){
            difference =(input[i] > input [i-1] ? input[i] - input[i-1] : input[i-1] - input[i]); 
	    if( difference >= count || difference == 0){
		result = 0;
		break;
	    }else{
                if(diff[difference] == 0)
                    diff[difference] = 1;
                else{
                    result = 0;
                    break;
                }
            }
	}
	if(result)puts("Jolly");
	else puts("Not jolly");
    }
    return 0;
}
