#include<queue>
#include<cstdio>
using namespace std;
int main(void){
	int count,length,a,b;
	long long result = 0;
	priority_queue<int> toCut;
	scanf("%d",&count);
	while(count--){
		scanf("%d",&length);
		toCut.push(-length);
	}
	while(toCut.size() > 1){
		a = toCut.top(); toCut.pop();
		b = toCut.top(); toCut.pop();
		toCut.push(a + b);
		result = result - (a + b);
	}
	printf("%lld\n",result);
	return 0;
}
