#include<cstdio>

struct Node{
	Node *up;
	Node(){up = NULL;}
};

Node nodes[20000];

int main(){

	int TestCase,Case = 1;
	scanf("%d",&TestCase);
	while(TestCase--){
		int Node;
		scanf("%d",&Node);
		for(int i = 0;i < Node - 1;++i){
			int A,B;
			scanf("%d%d",&A,&B);
		}

	



		int result = 0;

		printf("Case #%d:%d\n",Case++,result);
	}
	return 0;
}
