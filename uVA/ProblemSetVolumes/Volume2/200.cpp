#include<iostream>
#include<map>
#include<queue>
#include<vector>
using namespace std;
int main(void){
	multimap<char,char> order;
	map<char,int> task;
	string last,input;
	cin >> last;
	input = last;
	do{
		if(input == "#")break;
		else{
			auto Mismatch = mismatch(last.begin(),last.end(),input.begin());
			if(Mismatch.first != last.end()){
				order.insert(make_pair(*Mismatch.first,*Mismatch.second));
				task[*Mismatch.first];
				task[*Mismatch.second]++;
			}
		}
		task[*input.rbegin()];
		last = input;
	}while(cin >> input);
	queue<int> zero;
	for(auto Atask : task){
		if(Atask.second == 0){ 
			zero.push(Atask.first);
		}
	}
	while(zero.size()){
		printf("%c",zero.front());
		auto link = order.equal_range(zero.front());
		for(auto it = link.first;it != link.second;++it){
			task[(*it).second]--;
			if(task[(*it).second] == 0)
				zero.push((*it).second);
		}
		zero.pop();
	}    
	puts("");    
   
	return 0;
}
