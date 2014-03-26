#include <cstdio>
using namespace std;
int A[1000];
int B[1000];
long long int func(int n, int m)
{
	for (int i = n,j=0; j < m; --i){
		A[j++] = i;
	}
	for (int i = 1,j=0; i <=m; ++i){
		B[j++] = i;
	}
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < m; ++j) {
			if (B[i] != 1 &&A[i] % B[j] == 0) {
				A[i] /= B[j];
				B[j] = 1;
			}
		}
	}
	long long int ans = 1;
	for (int i=0; i < m; ++i)
		ans *= A[i];
	for (int i=0; i < m; ++i)
		ans /= B[i];
	return ans;
}
int main()
{
	int N;
	int n,m;
	scanf("%d", &N);
	while (N--){
		scanf("%d%d", &n, &m);
		printf("%lld\n", func(n,m));
	}
}