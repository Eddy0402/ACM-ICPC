#include<cstdio>
#include<vector>
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
	int Person,Pair,TestCase = 1;
	scanf("%d",&Person);
	Set person(Person);
	
	int temp1,temp2,temp3;
	while(scanf("%d%d%d",&temp1,&temp2,&temp3) != EOF && (temp1 || temp2 || temp3) ){
		switch(temp1){
			case 1: if(!person.add(temp2,temp3)) puts("-1");
				break;
			case 2:	if(!person.addEnemies(temp2,temp3)) puts("-1");
				break;
			case 3:
				if(person.root(temp2) == person.root(temp3))puts("1");
				else puts("0");
				break;
			case 4:
				if(person.isEnemies(temp2,temp3)) puts("1");
				else puts("0");	
				break;
		}
	}
	return 0;
}
