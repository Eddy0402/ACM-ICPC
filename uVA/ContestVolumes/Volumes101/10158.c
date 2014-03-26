#include<stdio.h>
#include<stdlib.h>
#define bool int
#define true 1
#define false 0
int *persons;
int *enemies;
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
	persons = (int *)malloc(sizeof(int) * Count);
	enemies = (int *)malloc(sizeof(int) * Count);
	for(i = 0;i < Count;++i) persons[i] = i;		
	for(i = 0;i < Count;++i) enemies[i] = -1;
}
char input[10000000];
char output[10000000];
char *a = input;
char *b = output;
void get(int *target){
	*target = 0;
	while(*a > '9' || *a < '0')++a;
	while(*a >= '0' && *a <= '9'){
		*target = *target * 10 + *a - '0';
		++a;
	}
	return;	
}
int main(){
	int Person;
	int temp1,temp2,temp3;
	fread(input,9999999,1,stdin);
	get(&Person);
	Set(Person);
	for(;;){
		get(&temp1);
		get(&temp2);
		get(&temp3);
		if (!(temp1 || temp2 || temp3) )break;
		switch(temp1){
			case 1: if(!add(temp2,temp3)) {*b = '-'; *(b + 1) = '1'; *(b + 2) = '\n'; b = b + 3; }
						break;
			case 2:	if(!addEnemies(temp2,temp3)){ *b = '-'; *(b + 1) = '1'; *(b + 2) = '\n'; b = b + 3; }
						break;
			case 3:
					if(root(temp2) == root(temp3)){*b = '1'; *(b + 1) = '\n'; b = b + 2;}
					else {*b = '0'; *(b + 1) = '\n'; b = b + 2;}
					break;
			case 4:
					if(isEnemies(temp2,temp3)) {*b = '1'; *(b + 1) = '\n'; b = b + 2;}
					else {*b = '0'; *(b + 1) = '\n'; b = b + 2;}
					break;
		}
	}
	fwrite(output,b-output,1,stdout);
	return 0;
}
