#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
class Set{
	public:
		void add(int a,int b){
			persons[root(a)] =  root(b);
		}
		int root(int a){
			while(persons[a] != a){
				 a = persons[a];
			}
			return a;
		}
		Set(int Count){
			for(int i = 0;i < Count;++i){
				persons.push_back(i);
			}		
		}
		int count(){
			for(int i = 0;i < persons.size();++i)
				persons[i] = root(i);
			sort(persons.begin(),persons.end());
			auto a = unique(persons.begin(),persons.end());
			return a - persons.begin();
		}
	private:
		vector<int> persons;
};
int main(){
	int Person,Pair,TestCase = 1;
	while(scanf("%d%d",&Person,&Pair) != EOF && Person && Pair ){
		Set person(Person);
		int temp,temp2;
		while(Pair--){
			scanf("%d%d",&temp,&temp2);
			person.add(temp-1,temp2-1);
		}
		printf("Case %d: %d\n",TestCase++,person.count());
	}
	return 0;
}
