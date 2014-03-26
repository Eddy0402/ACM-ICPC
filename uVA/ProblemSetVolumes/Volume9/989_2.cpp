#include<iostream>
#include<strstream>
#include<sstream>
#include<vector>
#include<queue>
using namespace std;
struct PAIR{
	int first,second;
	PAIR(int a,int b) : first(a),second(b){}
};
stringstream sout;
char input[5000000];
bool dfs(vector<PAIR>::iterator &blank,vector<PAIR>::iterator &end ,int (&Rows)[9][9],int size){
	if(blank == end)return true;
	int A = (*blank).first, B = (*blank).second;
	for(int Try = 1;Try <= size * size;++Try){
		bool trySuccess = true;
		for(int i = 0;i < size * size;++i){
			if(Rows[A][i] == Try)
			{ trySuccess = false;break; }
		}
		if(trySuccess)
			for(int i = 0;i < size * size;++i){
				if(Rows[i][B] == Try)
				{ trySuccess = false;break; }
			}
		if(trySuccess)
			for(int i = (A / size) * size; i < (A / size) * size + size;++i){ 
				for(int j = (B / size) * size; j < (B / size) * size + size ;++j){
					if(Rows[i][j] == Try)
					{ trySuccess = false;break; }
				}
			}
		if(trySuccess){
			Rows[A][B] = Try;
			if(dfs(++blank,end,Rows,size)) return true;
			else { --blank; Rows[A][B] = 0;}
		}
	}
	return false;
}
int main(){
	int size,blank_line = 0;
	ios::sync_with_stdio(false);
	cin.read(input,4999999);
	istrstream sin(input);
	while(sin >> size){
		if(blank_line)sout << '\n';
		else blank_line = 1;
		vector<PAIR> blank;
		int Rows[9][9];
		int temp;
		for(int i = 0;i < size * size;++i){
			for(int j = 0;j < size * size;++j){
				sin >> temp;
				Rows[i][j] = temp;
				if(temp == 0)blank.push_back(PAIR(i,j));
			}
		}
		auto begin = blank.begin(),end = blank.end();
		bool canSolve = dfs(begin,end,Rows,size);
		if(canSolve){
			for(int i = 0;i < size * size;++i){
				for(int j = 0;j < size * size ;++j){
					if(j)sout << ' ';
					sout << Rows[i][j];
				}
				sout << '\n';
			}
		}
		else{
			sout << "NO SOLUTION\n";
		}
	}
	sout.flush();
	cout << sout.rdbuf();
	return 0;
}
