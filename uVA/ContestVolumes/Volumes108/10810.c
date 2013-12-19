#include<stdio.h>
long long result;
int dist;
int ary[500010], buf[500010];
void Combine(int *l,int *r,int *end){
	int *i = l,*j = r;    
	int *buf = l + dist;
	while(i<r && j<=end){
		if(*j <= *i){ 
			result += r - i;
			*buf++ = *j++;
		}
		else {
			*buf++ = *i++;	
		}
	}
	while(i <  r  ) *buf++ = *i++;
	while(j <= end) *buf++ = *j++;
        j--; buf--;
	while( j >= l ) *j-- = *buf--;
}
void MergeSort(int *l,int *r){
	if(r==l)return;
	int * a = l + (r-l)/2;
	MergeSort( l, a );
	MergeSort( a + 1 , r);
	Combine(l, a+1, r);
}
int main(void){
    int i;
    int N, *store;
    while(scanf("%d",&N) != EOF){
        if(N == 0)break;
        N--;
        for(store = ary ; N>=0 ; N--)scanf("%d",store++);        
 	dist = buf - ary;
        result = 0;
        MergeSort(ary,store-1);
        //for(i=0;i<10;i++)printf(" %d",ary[i]);
        //puts("");
        printf("%d\n",result);
    }
    return 0;
}

