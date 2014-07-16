#include<cstdio>
#include<iostream>
#include<strstream>
#include<sstream>
#include<stack>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
char input [2000000];
int main(void){
	ios::sync_with_stdio(false);
	cin.read(input,1999999);
	istrstream sin(input);
	stringstream sout;
	int testCount, operation, data;
	while(sin >> testCount){
		bool isStack = true, isQueue = true, isPriorityQueue = true;
		stack<int> stackData;
		queue<int> queueData;
		priority_queue<int> priorityQueueData;
		while(testCount--){
			sin >> operation >> data;
			if(operation == 1){
				stackData.push(data);
				queueData.push(data);
				priorityQueueData.push(data);
			}else{
				if(isStack){
					if(stackData.size() != 0 && data == stackData.top())
						stackData.pop();
					else
						isStack = false;	
				}
				if(isQueue){
					if(queueData.size() != 0 && data == queueData.front())
						queueData.pop();
					else 
						isQueue = false;
				}
				if(isPriorityQueue){
					if(priorityQueueData.size() != 0 && data == priorityQueueData.top())
						priorityQueueData.pop();
					else
						isPriorityQueue = false;
				}
			}
		}
		if( !(isPriorityQueue || isStack || isQueue) )
			sout << "impossible\n";
		else if(isPriorityQueue && !(isStack || isQueue))
			sout << "priority queue\n";
		else if(isStack && !(isQueue || isPriorityQueue))
			sout << "stack\n";
		else if(isQueue && !(isStack || isPriorityQueue))
			sout << "queue\n";
		else
			sout << "not sure\n";
	}
	cout << sout.rdbuf();
	return 0;
}
