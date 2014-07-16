#include<stdio.h>
#include<stdlib.h>
#define bool int
#define true 1
#define false 0
int *persons = NULL;
int *enemies = NULL;
bool isEnemies(int a,int b);
bool add(int a,int b){
	int temp; 
	if(isEnemies(a,b))return false;
	if(a != b && enemies[root(a)] != -1 && enemies[root(b)] != -1){
		persons[root(enemies[root(a)])] = root( enemies[root(b)]);
		enemies[root(enemies[root(b)])] = root(a);
	}
	temp = root(b);
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
void Set(int Count){
	int i;
	if(persons != NULL)free (persons);
	if(enemies != NULL)free (enemies);
	persons = (int *)malloc(sizeof(int) * Count);
	enemies = (int *)malloc(sizeof(int) * Count);
	for(i = 0;i < Count;++i) persons[i] = i;		
	for(i = 0;i < Count;++i) enemies[i] = -1;
}
int main(){
	int TestCases,Person,Message;
	char temp1;
	int temp2,temp3;
	scanf("%d",&TestCases);
	while(TestCases--){
		scanf("%d%d",&Person,&Message);
		Set(Person);
		while(Message--){
			scanf(" %c%d%d",&temp1,&temp2,&temp3);
			--temp2;--temp3;
			switch(temp1){
				case 'D':	addEnemies(temp2,temp3); break;
				case 'A':
						if(isEnemies(temp2,temp3)) puts("In different gangs.");
						else if(root(temp2) == root(temp3) )puts("In the same gang.");
						else puts("Not sure yet.");
						break;
			}
		}
	}
	return 0;
}
