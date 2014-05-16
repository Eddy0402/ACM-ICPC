#include<cstdio>
#include<cstring>
long long result[310][310]={};
int main(){
	char input[50];
	result[0][0]=1;
	for(int i = 1;i <= 300;++i)
		for(int j = i;j <= 300;++j)
			for(int k = 1;k <= 300;++k)
				result[j][k] += result[j-i][k-1];
	while(fgets(input,49,stdin)){
		int A,B=-1,C=-1;
		long long res = 0;
		sscanf(input,"%d%d%d",&A,&B,&C);
		if(B > 300) B = 300;
		if(C > 300) C = 300;
		if(C == -1){
			if(B == -1)B = A;
			for(int i = 0;i <= B;++i)
				res += result[A][i];
		}else{
			for(int i = B;i <=C;++i)
				res += result[A][i];
		}
		printf("%lld\n",res);
	}
	return 0;
}
