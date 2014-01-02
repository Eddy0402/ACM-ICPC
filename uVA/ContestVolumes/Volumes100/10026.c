#include<stdio.h>
#include<stdlib.h>
struct job{
    int index;
    int time;
    int fine;
} data[1002];
int compare(const void *a,const void *b){
    if(((struct job *)a) -> time * ((struct job*)b) -> fine == ((struct job *)b) -> time * ((struct job*)a) -> fine)
        return ((struct job*)a) -> index - ((struct job*)b) -> index;
    else return 
    ((struct job *)a) -> time * ((struct job*)b) -> fine - ((struct job *)b) -> time * ((struct job*)a) -> fine;
}
int main(void){
    int testPoints;
    int cases,i;
    scanf("%d",&testPoints);
    while(testPoints--){
        scanf("%d",&cases);
        for(i = 0;i < cases;i++){
            scanf("%d%d",&data[i].time,&data[i].fine);
            data[i].index = i;
        }
        qsort(data,cases,sizeof(struct job),compare);
        printf("%d",data[0].index + 1);
        for(i = 1;i < cases;i++)printf(" %d",data[i].index + 1);
        putchar('\n');
        if(testPoints)putchar('\n');
    }
    return 0;
}
