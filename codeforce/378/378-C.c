#include<stdio.h>
char maze[502][502];
int remain;
int dfs(int x,int y){
    if(remain == 0)return;
    if(maze[x][y] == 'X'){
        maze[x][y] = '.';
	remain--;
        dfs(x+1,y);
        dfs(x-1,y);
        dfs(x,y+1);
        dfs(x,y-1);
    }
}
int main(void){
    int n,m,k,spaceCount,x,y,a=0;
    scanf("%d%d%d ",&n,&m,&k);
    spaceCount = 0;
    for(y = 0;y <= n + 1;y++)
        for(x = 0;x <= m + 1;x++)
            if(x == 0|| y==0||x==m+1||y==n+1)
                maze[x][y] = ' ';
    for(y = 1;y <= n;y++){
        for(x = 1;x <= m;x++){
            maze[x][y] = getchar();
            if(maze[x][y]=='.'){
		maze[x][y] = 'X';
                spaceCount++;
            }
        } 
        if(y != n)scanf(" ");;
    }
    for(y = 1;y <= n;y++){
        for(x = 1;x <= m;x++)
            if(maze[x][y] == 'X'){a=1;break;}
        if(a)break;   
    }
    remain = spaceCount - k;
    dfs(x,y);
    for(y = 1;y <= n;y++){
        for(x = 1;x <= m;x++)
	    putchar(maze[x][y]);
        putchar('\n');
    }    
    return 0;
}
