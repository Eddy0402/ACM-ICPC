#include<stdio.h>
#include<stdlib.h>

typedef struct Xs{
    int x; 
    int y;
}Xs;
void addX(int x,int y);
void delX();
void dfs_d(int x,int y);
int dfs(int x ,int y);
int compareInt(const void *a,const void *b);

char field[55][55];
char visit[55][55]; 
char check[55][55]; 
Xs  Xdata[10000];
int Xcount;
int dice[10000];
int width,height;

int main(void){
    int row,col,testPoint=1,diceCount;
    int i;
    while(scanf("%d%d",&width,&height) != EOF){
        diceCount = 0;
        Xcount = 0;
        if(width == 0)break;
        scanf(" ");
        for(row = 1;row <= height; row++){
            for(col = 1; col <= width; col++){
                field[col][row] = getchar();
                visit[col][row] = 0;
                check[col][row] = 0;
                if(field[col][row] == 'X') addX(col,row);
            }
           scanf(" "); 
        }
        delX();
        for(i = 0; i < Xcount; i++)
            if(!check[(Xdata+i) -> x][(Xdata+i) -> y])
               dice[diceCount++] = dfs((Xdata+i) -> x,(Xdata+i) -> y);
        qsort(dice,diceCount,sizeof(int),compareInt);
        printf("Throw %d\n",testPoint++);
        for(i = 0; i < diceCount - 1;i++)
             printf("%d ",dice[i]);
        printf("%d\n\n",dice[diceCount-1]);
    }
    return 0;
}

int dfs(int x, int y){
    int temp;
    if(check[x][y] || x == 0 || y == 0 || x > width || y > height || field[x][y] == '.')return 0;
    check[x][y] = 1;
    temp = (field[x][y] == 'X' ? 1 : 0) +
           dfs(x,y+1) +
           dfs(x,y-1) + 
           dfs(x+1,y) + 
           dfs(x-1,y) ;    
    return temp;
}
void addX(int x, int y){
    Xdata[Xcount].x = x;
    Xdata[Xcount].y = y;
    Xcount++;
}
void dfs_d(int x,int y){
    if(field[x][y] != 'X' || visit[x][y])return;
    field[x][y] = '*';
    visit[x][y] = 1;
    dfs_d(x+1,y);
    dfs_d(x-1,y);
    dfs_d(x,y+1);
    dfs_d(x,y-1);
}
void delX(){
    int i;
    int temp = 0;
    for(i = 0; i < Xcount; i++){
        if(field[(Xdata+i)->x][(Xdata+i)->y] == 'X'){
            dfs_d( (Xdata+i)->x, (Xdata+i)->y );
            field[(Xdata+i)->x][(Xdata+i)->y] = 'X';
            Xdata[temp].x = (Xdata+i) -> x;
            Xdata[temp].y = (Xdata+i) -> y;
            temp++;
        }
    }
    Xcount = temp;
} 
int compareInt(const void *a,const void *b){
    return *(int *)a - *(int *)b;
}
