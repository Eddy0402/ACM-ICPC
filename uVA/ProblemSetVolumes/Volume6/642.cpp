#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
unordered_map<string,vector<string>> dictionary;
bool compare(const string &a,const string &b){
	return a.compare(b) < 0;
}
int main(void){
    string input;
	ios::sync_with_stdio(false);
	while(cin >> input){
		if(!input.compare("XXXXXX"))break;
		string temp(input);
		sort(temp.begin(),temp.end());
		dictionary[temp].push_back(input);
	}
	for(auto &list : dictionary)
		sort(list.second.begin(),list.second.end(),compare);
	while(cin >> input){
		if(!input.compare("XXXXXX"))break;
		sort(input.begin(),input.end());
		if(dictionary[input].size() == 0){
			cout <<	"NOT A VALID WORD\n";	
		}else{
			for(auto &match : dictionary[input]){
				cout << match << "\n";
			}
		}
		cout << "******\n";
	}
	return 0;
}

