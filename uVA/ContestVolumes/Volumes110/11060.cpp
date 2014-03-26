#include<iostream>
#include<map>
#include<queue>
#include<vector>
#include<string>
#include<functional>
using namespace std;
int main(void){
	ios::sync_with_stdio(false);
	int Task,Precedence;
	int TestCase = 1;
	while(cin >> Task){
		map<string,int> beverges;
		map<int,string> rbeverges;
		vector<int> tasks(Task,0);
		priority_queue<int,vector<int>,greater<int>> zero;
		multimap<int,int> order;
		string temp;
		for(int i = 0;i < Task;++i){
			cin >> temp;
			beverges[temp] = i;
			rbeverges[i] = temp;
		}
		cin >> Precedence;
		for(int i = 0; i < Precedence; ++i){
			string front,back;
			cin >> front >> back;
			tasks[beverges[back]]++;
			order.insert(make_pair(beverges[front],beverges[back]));
		}
		for(int i = 0; i < Task; ++i){
			if(tasks[i] == 0){ 
				zero.push(i);
			}
		}
		cout << "Case #" << TestCase++ << ": Dilbert should drink beverages in this order:";
		while(zero.size()){
			cout << " " << rbeverges[zero.top()];
			auto link = order.equal_range(zero.top());
			zero.pop();
			for(auto it = link.first;it != link.second;++it){
				--tasks[(*it).second];
				if(tasks[(*it).second] == 0)
					zero.push((*it).second);
			}
		}   
		cout << ".\n\n";    
	}   
	return 0;
}
