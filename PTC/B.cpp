#include<cstdio>
#include<map>
using namespace std;
int height[100005];
int main(){
	int TestCase;
	freopen("testdata.in","r");
	scanf("%d",&TestCase);
	while(TestCase--){
		int N,M,Target;
		scanf("%d%d%d",&N,&Stick,&Target);
		map<int,int> connect;
		int A,B;
		for(int i = 0;i < Stick;++i){
			scanf("%d%d",&A,&B);
			connect[A] = B;
			connect[B] = A;
		}
		


	}
	return 0;
}
