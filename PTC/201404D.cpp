#include<cstdio>
using namespace std;

int C(int m,int n){
	if(m == n)return 1;
	if(n == 1)return m;
	return C(m-1,n-1) + C(m-1,n);
}

int main(){
	int TestCase;
	freopen("testdata.in","r",stdin);
	scanf("%d",&TestCase);
	while(TestCase--){
		int N;
		char X[203],A[203];
		scanf("%d",&N);
		scanf("%s%s",A,X);
		int count = 0;
		for(int i = 0;i < N;++i)
			if(X[i] == '1')++count;
		bool result = false;
		for(int i = 1;i <= count;++i){
			if(A[i-1] == '1'){
				bool temp =  C(count,i) % 2;
				if(result ^ temp) result = true;
				else result = false;
			}
		}
		puts(result ? "1" : "0");
	}
	return 0;
}
