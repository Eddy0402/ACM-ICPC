#include<iostream>
#include<strstream>
#include<sstream>
#include<queue>
using namespace std;
char input[500000];
int main(void){
	int count,temp;
	ios::sync_with_stdio(false);
	cin.read(input,499999);
	istrstream sin(input);
	stringstream sout;
	while(sin >> count){
		if(count == 0)break;
		priority_queue<int> data;
	    int cost = 0;
		long long result = 0;
		for(register int i = 0; i < count; i++){
			sin >> temp;
			data.push(temp * (-1));
		}
		while(data.size() != 1){
			cost = data.top();
			data.pop();
			cost += data.top();
			data.pop();
			result += cost;
			data.push(cost);
		}
		sout << -result << "\n";
	}
	cout << sout.rdbuf();
	return 0;
}
