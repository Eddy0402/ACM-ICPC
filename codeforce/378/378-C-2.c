#include<stdio.h>
#include<stdlib.h>
char maze[502][502];
char side[502][502];
struct node *list;
struct node *last;

    int n,m,k;
struct node{
    struct node* next;
    int x;
    int y;
};

int add(int x,int y){
    struct node *temp = calloc(sizeof(struct node),1);
    temp -> x = x;
    temp -> y = y;
    if(list == NULL){ list = temp; last = list; }
    else{
        last -> next = temp;
        last = last -> next;
    }
}

int aa(int x,int y){
    if(side[x+1][y] != 1 &&
    side[x-1][y] != 1 &&
    side[x][y+1] != 1 &&
    side[x][y-1] != 1) return 1;
    return 0;
}


void wall(int x,int y){
    maze[x][y] = 'X';
    if(x!=m)if((++side[x+1][y] == 3 && maze[x+1][y] != 'X' && maze[x+1][y] != '#')||aa(x+1,y))add(x+1,y);
    if(x!=1)if((++side[x-1][y] == 3 && maze[x-1][y] != 'X' && maze[x-1][y] != '#')||aa(x-1,y))add(x-1,y);
    if(y!=n)if((++side[x][y+1] == 3 && maze[x][y+1] != 'X' && maze[x][y+1] != '#')||aa(x,y+1))add(x,y+1);
    if(y!=1)if((++side[x][y-1] == 3 && maze[x][y-1] != 'X' && maze[x][y-1] != '#')||aa(x,y-1))add(x,y-1);
}

int main(void){
    int x,y;
    scanf("%d%d%d ",&n,&m,&k);
    for(y=1;y<=n;y++)for(x=1;x<=m;x++)side[x][y]=0;
    for(y = 1;y <= n;y++){
	for(x = 1;x <= m;x++){
	    maze[x][y] = getchar();
	    if(maze[x][y] == '#'){
		if(++side[x+1][y] == 3||aa(x+1,y))add(x+1,y);
		if(++side[x-1][y] == 3||aa(x-1,y))add(x-1,y);
		if(++side[x][y+1] == 3||aa(x,y+1))add(x,y+1);
		if(++side[x][y-1] == 3||aa(x,y-1))add(x,y-1);
	    }
	} 
	if(y != n)getchar();
    }
    for(x = 1;x <= m;x++){ 
        if((++side[x][1] == 3 && maze[x][1] != '#')||aa(x,1))add(x,1);
        if((++side[x][n] == 3 && maze[x][n] != '#')||aa(x,n))add(x,n); 
    }
    for(y = 2;y < n;y++){
        if((++side[1][y]==3 && maze[1][y] != '#')||aa(1,y))add(1,y);
        if((++side[m][y]==3 && maze[m][y] != '#')||aa(m,y))add(m,y);
    }

    while(k-- > 0){
         wall(list->x,list->y);
         list = list -> next;  
    }
    for(y = 1;y <= n;y++){
        for(x = 1; x<=m; x++){
            putchar(maze[x][y]);
        } 
        if(y != n)putchar('\n');
    }
    return 0;
} 
