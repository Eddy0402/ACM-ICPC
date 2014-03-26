#include<map>
#include<string>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
class Set{
	public:
		void add(int a,int b){ 
			if(root(a) == root(b))return;
			count[root(b)] += count[root(a)];
			persons[root(a)] =  root(b);
		}
		int root(int a){ 
			int temp = a;
			while(persons[a] != a) a = persons[a];
			persons[temp] = a;
			return a;
		}
		Set(int Count){
			for(int i = 0;i < Count;++i)persons.push_back(i);
			for(int i = 0;i < Count;++i)count.push_back(1);
		}
		vector<int> &getCount(){ return count; }
	private:
		vector<int> persons;
		vector<int> count;
};
int main(){
	int Creature,Relations;
	while(scanf("%d%d",&Creature,&Relations) != EOF && !(Creature == 0 && Relations == 0)){
		int k = 0;
		map<string,int> creature;
		char input[40],input2[40];
		for(int i = 0;i < Creature;++i){
			scanf("%s",input);
			creature[string(input)] = k++;
		}
		Set c(Creature);
		while(Relations--){
			scanf("%s%s",input,input2);
			c.add(creature[string(input)],creature[string(input2)]);
		}
		vector<int>& count = c.getCount();
		int result = 0;
		for(int i = 0;i < count.size();++i)	if(count[i] > result)result = count[i];
		printf("%d\n",result);

	}
	return 0;
}
