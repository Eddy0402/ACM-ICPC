#include<iostream>
using namespace std;
int main(void){
	ios_base::sync_with_stdio(false);
	int input,testcase = 1;
	while(cin >> input){
		if(input-- < 0)break;
		int result = 1;
		if(input == 0)result = 0;
		while(input /= 2)result++;
		cout << "Case " << testcase++ << ": " << result << endl;
	}
	return 0;
}
