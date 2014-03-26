#include<cstdio>
#include<set>
using namespace std;
int root(int a,char *ch){
	int temp = a;
	if(ch[a] != a)a = ch[a];
	ch[temp] = a;
	return a;
}
int main(){
	int Repeaters;
	while(scanf("%d",&Repeaters) != EOF && Repeaters != 0){
		char Channel[27];
		char input[27];
		for(int i = 0;i < Repeaters;++i){
			Channel[i] = 'A';
		}
		for(int i = 0;i < Repeaters;++i){
			scanf(" %*c:%[^\n]\n",input);
			char *a = input;
			while(*a++){
				Channel[*a - 'A'] = i;
			}
		}
		set<int> result;
		for(int i = 0;i < Repeaters;++i){
			result.insert(root(i,Channel));
		}
		printf("%d channels needed.\n",result.size());
	}
	return 0;
}
