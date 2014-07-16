#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
using namespace std;
class Set{
	public:
		void add(int a,int b){
			if(root(a) == root(b))return;
			group[root(b)] += group[root(a)];
	 		persons[root(a)] =  root(b);
		}
		int root(int a){
			if(a == persons.size()){
				persons.push_back(a);
				group.push_back(1);
			}
			while(persons[a] != a){
				 a = persons[a];
			}
			return a;
		}
		Set(){ persons.reserve(1500); group.reserve(1500); }
		int size(int a){
			return group[root(a)];
		}
	private:
		vector<int> persons;
		vector<int> group;
};
int main(){
	int Person, TestCase;
	scanf("%d",&TestCase);
	char a[25],b[25];
	while(TestCase--){
		scanf("%d",&Person);
		Set person;
		map<string,int> names;
		int temp = 0;
		while(Person--){
			scanf("%s%s",&a,&b);
			int front,back;
			if(names.find(string(a)) == names.end()){
				front = (names[string(a)] = temp++);
			}else front = names[string(a)];
			if(names.find(string(b)) == names.end()){
				back = (names[string(b)] = temp++);
			}else back = names[string(b)];
			person.add(front,back);
			printf("%d\n",person.size(front));
		}
	}
	return 0;
}
