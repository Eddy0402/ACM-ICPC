#include<stdio.h>
struct dish{
    int dish[20][20];
};
struct dish a,b,*current = &a,*next = &b;
void swap_dish(void){
    if(current == &a){ current = &b; next = &a; }
    else {current = &a; next = &b; }
}
void simulatedDay(int DNA[]){
    int i,j,temp;
    for(i = 0;i < 20;i++)
	for(j = 0;j < 20;j++){
	    temp = current -> dish[i][j];
	    if(j != 0)temp += current -> dish[i][j-1];
	    if(j != 19)temp += current -> dish[i][j+1];
	    if(i != 0)temp += current -> dish[i-1][j];
	    if(i != 19)temp += current -> dish[i+1][j];
	    temp = DNA[temp] + current -> dish[i][j];
	    next -> dish[i][j] = temp > 3 ? 3 : (temp < 0 ? 0 : temp);
	}
    swap_dish();
}
int main(void){
    int day,DNA[16];
    int i,j,temp;
    scanf(" %d",&day); 
    for(i = 0;i < 16;i++)scanf("%d",DNA + i);	
    for(i = 0;i < 20;i++)
	for(j = 0;j < 20;j++)
	    scanf(" %d",&current -> dish[i][j]);
    for(i = 0;i < day; i++)simulatedDay(DNA);
    for(i = 0;i < 20;i++){
	for(j = 0;j < 20;j++){
	    temp = current -> dish[i][j];
	    putchar(temp == 0 ? '.' : temp == 1 ? '!' : temp == 2 ? 'X' : '#');
	}
	putchar('\n');
    }
    return 0;
}
