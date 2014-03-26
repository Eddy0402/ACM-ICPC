#include<iostream>
#include<vector>
#include<string>
using namespace std;
const int none = 0,Left=1,Dia=2,Up=3;
int main(){
	ios::sync_with_stdio(false);
	while(1){
	int first = 0;
	int LCS[110][110]={};
	int From[110][110]={};
	vector<string> First,Second;
	First.reserve(110);
	Second.reserve(110);
	string input;
	First.push_back("");
	Second.push_back("");
	while(cin >> input && input != "#") First.push_back(input);
	if(cin.eof())break;
	while(cin >> input && input != "#") Second.push_back(input);
	for(int i = 1;i < First.size();++i){
		for(int j = 1;j < Second.size();++j){
			if(First[i] == Second[j]){
				LCS[i][j] = LCS[i-1][j-1] + 1;
				From[i][j] = Dia;
			}else{
				if(LCS[i-1][j] > LCS [i][j-1]){
					From[i][j] = Left;
					LCS[i][j] = LCS[i-1][j];
				}
				else{
					From[i][j] = Up;
					LCS[i][j] = LCS[i][j-1];
				}
			}
		}
	}
	vector<string> result;
	result.reserve(110);
	for(int i = First.size()-1,j = Second.size()-1;;){
		if(i == 0 || j == 0){ break; }
		else if(From[i][j] == Up){ --j;}
		else if(From[i][j] == Left){ --i; }
		else if(From[i][j] == Dia){
			result.push_back(First[i]);
			--i,--j;
		}
	}
	bool flag = false;
	for(vector<string>::reverse_iterator it = result.rbegin(); it != result.rend();++it){
		if(!flag)flag = true;
		else cout << " ";
		cout << *it;
	}
	cout << endl;
	}
	return 0;
}
