#include<stdio.h>
#include<string.h>

void f1(int start,int end,int length,char *a){
    if(start == 1){ 
       sprintf(a,"%d",1);
       f1(2,end,length-1,a);
       return; 
    }
    if(length == 0){
        printf("%s\n",a);
        return;
    }

    if(end-start < length-1 || end < start) return;
    
    char b[10000]; 
    sprintf(b,"%s,%d",a,start);
    f1(start+1,end,length-1,b);
    f1(start+1,end,length,a);
}

void f2(int start,int end,int length,char *a,int N){
    if(end == N){
        sprintf(a,"%d",N);
        f2(start,end-1,length-1 ,a,N);
        return;
    } 
    if(length == 0){
        printf("%s\n",a);
        return;
    }
    if(end-start < length-1 || end < start)return;
    
    f2(start,end-1,length,a,N);
    char b[10000];
    sprintf(b,"%d,%s",end,a);
    f2(start,end-1,length-1,b,N);
}

int main(void){
    int N,i,j;
    char a[10000];
    while(scanf("%d",&N) != EOF){
	printf("1\n%d\n",N);
	for(i=2; i<N; i++){
            //printf("[[%d]]\n",i);
	    f1(1,N,i,a);
	    f2(2,N,i,a,N);
	}  
    }
    return 0;
}
