#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int a,b,c;
struct Block{
	int a,b,c;
	Block(int A,int B,int C):a(A),b(B),c(C){}
	bool operator<(const Block &T)const{
		if(a == T.a) return b < T.b;
		return a < T.a;
	}
};
int main(){
	int N,Test=1;
	while(scanf("%d",&N) != EOF && N){
		vector<Block> blocks;
		vector<int> lis(1000);
		int result = 0;
		while(N--){
			scanf("%d%d%d",&a,&b,&c);
			blocks.push_back(Block(a,b,c));
			blocks.push_back(Block(a,c,b));
			blocks.push_back(Block(b,c,a));
			blocks.push_back(Block(b,a,c));
			blocks.push_back(Block(c,a,b));
			blocks.push_back(Block(c,b,a));
		}
		sort(blocks.begin(),blocks.end());
		for(int i = 0;i < blocks.size();++i){
			lis[i] = blocks[i].c;
			for(int tr = 0;tr < i;++tr){
				if(blocks[i].a > blocks[tr].a && blocks[i].b > blocks[tr].b 
					&& lis[tr] + blocks[i].c > lis[i]){
					lis[i] = lis[tr] + blocks[i].c;
				}
			}
			if(lis[i] > result)result = lis[i];
		}
		printf("Case %d: maximum height = %d\n",Test++,result);
	}
	return 0;
}
