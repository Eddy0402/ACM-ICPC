#include<string>
#include<iostream>
#include<vector>
using namespace std;

bool isAEIOU(char a){
    switch(a){
		case 'A':case 'E':case 'I':	case 'O':case 'U':
		case 'a':case 'e':case 'i':	case 'o':case 'u':
			return true;
	}
	return false;
}
void divide(string a,int limit,string &Front,string &End){
	vector<int> Vpos;
	const char *toDivide = a.c_str();
	const char *start = toDivide;
	while(*toDivide != '\0'){
		if( isAEIOU(*toDivide) && *(toDivide + 1) != '\0'|| (*toDivide == 'y' && *(toDivide + 1) == '\0') ){
			if(toDivide == start)
				Vpos.push_back(0);
			else if(toDivide - 1 == start){
				Vpos.push_back(toDivide - start - 1);
			}else if( !isAEIOU(*(toDivide - 1)) ){
				if( (toDivide - 2) != start && *(toDivide - 1) == 'h' && (
					 *(toDivide - 2) == 'c' || *(toDivide - 2) == 'C' ||
					 *(toDivide - 2) == 's' || *(toDivide - 2) == 'S' || 
					 *(toDivide - 2) == 'p' || *(toDivide - 2) == 'P')) {
					Vpos.push_back(toDivide - 2 - start);
				}else{
					Vpos.push_back(toDivide - 1 - start);
				}
			}
		}
		toDivide++;
	}	
	if(Vpos.size() == 1)Vpos.clear();
	int cur = 0, nxt = 0;
	for (int i = 0; i < Vpos.size(); ++i) {
		nxt = Vpos[i];
		if (nxt + 1 <= limit)
			cur = nxt;
			 /*
			if (cur < limit) {
				Front = a.substr(0,Vpos[i]) + "-";
				End = a.substr(Vpos[i], a.size()-Vpos[i]);
			}else{
				Front = "";
				End = a;
			}	
			break; 
		}*/
	}
	if(cur)Front = a.substr(0,cur) + "-";
	else Front = "";
	End = a.substr(cur,a.size());
}

int main(){
	ios::sync_with_stdio(false);
	int N;
	string str;

	cin >> N;

	int cur = 0;
	int left = N;
	bool first = 1;

	while (cin >> str) {
	//	cout << "||" << str << "||" << endl;
		if (str.size() < left) {
			if (!first) {
				cout << ' ';
				++cur;
			}
			cout << str;
			first = 0;
			cur += str.size();
			left = N - cur;
		}
		else {
			string cur_line;
			string nxt_line;
			divide(str, left-1, cur_line, nxt_line);
			if (!cur_line.empty()) {
				if(!first){cout << ' ';cur++;}
				cout << cur_line;
				cout << string((N - cur - cur_line.size()),' ') << endl;
			}
			else cout << string((N - cur - cur_line.size()),' ') << endl;

			cout << nxt_line;
			first = 0; //假設下一行一定有字串
			cur = nxt_line.size();
			left = N - cur; 
		}
	}
	cout << endl;
	return 0;
}

