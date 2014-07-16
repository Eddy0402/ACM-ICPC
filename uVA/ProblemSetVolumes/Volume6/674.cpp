#include<cstdio>
int result[7500]={};
void init(){
	int C[]={1,5,10,25,50};
	result[0] = 1;
	for(int c = 0;c < 5;++c){
		for(int i = C[c];i < 7500;++i){
			result[i] += result[i-C[c]];
		}
	}
}
int main(){
	int in;
	init();
	while(scanf("%d",&in) != EOF){
		printf("%d\n",result[in]);
	}
	return 0;
}
