#include<stdio.h>
#include<stdlib.h>
int Di[100005];
int b_search(int target,int left,int right){
	int middle;
	if(Di[right] < target)return -1;
    while(left != right){
       middle = (left + right) / 2;
	   if(Di[middle] == target)return Di[middle];
       if(Di[middle] > target){
			right = middle;
	   }else{
		   	if(Di[middle + 1] > target)return Di[middle + 1];
			left = middle + 1;
	   }
	}
	return Di[left];
}
int cmp(const void *a,const void *b){
    return *(int*)a - *(int *)b;
}
int main(void){
	int testCase,N,i,Q,target,temp;
	scanf("%d",&testCase);
	while(testCase--){
		scanf("%d",&N);
		for(i = 0;i<N;i++)
			scanf("%d",&Di[i]);
		Di[N] = 1u << 31 - 1;
		qsort(Di,N,sizeof(int),cmp);
		scanf("%d",&Q);
		scanf("%d",&target);
        printf("%d",b_search(target,0,N-1));
		for(i = 1;i < Q;i++){
		    scanf("%d",&target);
	        printf(" %d",b_search(target,0,N-1));
		}
		putchar('\n');
	}
	return 0;
}
