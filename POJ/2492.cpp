#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
class Set{
	public:
		bool add(int a,int b){  //new root = a
			if(isEnemies(a,b))return false;
			if(a != b && enemies[root(a)] != -1 && enemies[root(b)] != -1){
					persons[root(enemies[root(a)])] = root( enemies[root(b)]);
					enemies[root(enemies[root(b)])] = root(a);
			}
			int temp = root(b);
			persons[root(b)] =  root(a);
			if(enemies[root(a)] == -1)enemies[root(a)] = enemies[temp];
			return true;
		}
		bool addEnemies(int a,int b){
			if(root(a) == root(b)) return false;
			if(enemies[root(b)] != -1)add(root(a),enemies[root(b)]);
			if(enemies[root(a)] != -1)add(root(b),enemies[root(a)]);
			enemies[root(a)] = root(b);
			enemies[root(b)] = root(a);
			return true;
		}
		bool isEnemies(int a,int b){
			 if(enemies[root(a)] != -1 && root(enemies[root(a)]) == root(b)) return true; 
			 else if(enemies[root(b)] != -1 && root(enemies[root(b)]) == root(a)) return true; 
			 else return false;
		}
		int root(int a){
			int temp = a;
			while(persons[a] != a) a = persons[a];
			persons[temp] = a;
			return a;
		}
		Set(int Count){
			persons.reserve(Count);enemies.reserve(Count);
			for(int i = 0;i < Count;++i) persons.push_back(i);		
			for(int i = 0;i < Count;++i) enemies.push_back(-1);
		}
	private:
		vector<int> persons;
		vector<int> enemies;
};
int main(){
	int Bug,Pair,TestCase;
	scanf("%d",&TestCase);
	for(int Test = 1;Test <= TestCase; ++Test){
		scanf("%d%d",&Bug,&Pair); 
		Set person(Bug);
		int temp,temp2;
		bool flag = false;
		while(Pair--){
			scanf("%d%d",&temp,&temp2);
				if(person.root(temp-1)==person.root(temp2-1))flag = true;
				if(flag)continue;
				person.addEnemies(temp-1,temp2-1);
		}
		if(Test != 1)putchar('\n');
		printf("Scenario #%d:\n",Test);
		if(flag) puts("Suspicious bugs found!");
		else puts("No suspicious bugs found!");
	}
	return 0;
}
