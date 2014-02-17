#include<stdio.h>
int main(void){
	int width,height,fieldNumber=1;
	int h,w;
	char field[110][110];
	while(scanf("%d%d",&height,&width)!=EOF){
		if( width == 0 && height == 0 )break;
		if(fieldNumber != 1) putchar('\n');
		for(h = 0; h <= height + 1; h++){
			for(w = 0; w <= width + 1; w++){
				if(h > 0 && h < height + 1 && w > 0 && w < width + 1){
					field[h][w] = getchar();
					if(field[h][w] == '.')field[h][w] = '0';
				}
				else field[h][w] = '0';
			}
			if(h != height + 1)getchar();
		}
		printf("Field #%d:\n",fieldNumber++);
		for(h = 1; h <= height; h++){
			for(w = 1; w <= width; w++){
				if(field[h][w] != '*'){
					if(field[h+1][w] == '*')field[h][w]++;
					if(field[h-1][w] == '*')field[h][w]++;
					if(field[h][w+1] == '*')field[h][w]++;
					if(field[h][w-1] == '*')field[h][w]++;
					if(field[h+1][w+1] == '*')field[h][w]++;
					if(field[h+1][w-1] == '*')field[h][w]++;
					if(field[h-1][w+1] == '*')field[h][w]++;
					if(field[h-1][w-1] == '*')field[h][w]++;
				}
				putchar(field[h][w]);
			}
			putchar('\n');
		}
	}
	return 0;
}
