#include<iostream>
#include<vector>
#include<cstring>
#include<string>
using namespace std;
int N,M,F;

int RLink[505],pass[505];
int edge[505][505]; // gophere to hole
int No = -1; // memset -1

bool FindRight(int Left){
	for(int r = 0;r < F;++r){
		if( edge[Left][r] && !pass[r] ){
			pass[r] = 1;
			if(RLink[r] == No || FindRight(RLink[r])){
				RLink[r] = Left;
				return true;
			}
		}
	}
	return false;
}

struct P{
	int height;
	char gender;
	string music,sport;
	void input(){
		cin >> height >> gender >> music >> sport;
	}
	bool no(const P& lhs){
		int h = height - lhs.height;
		if(h < 0)h = -h;
		return (h > 40) || (music != lhs.music) || (sport == lhs.sport);
	}
};

int main(){
	ios::sync_with_stdio(false);
	int TestCase;
	cin >> TestCase;
	while(TestCase--){
		cin >> N;
		M=0,F=0;
		int a,b;
		memset(edge,0,sizeof(edge));
		memset(RLink,-1,sizeof(RLink));
		memset(&No,-1,sizeof(No));
		vector<P> Male;
		vector<P> Female;
		for(int i = 0;i < N;++i){
			P a;
			a.input();
			if(a.gender == 'M'){
				Male.push_back(a);
				++M;
			}else{
				Female.push_back(a);
				++F;
			}
		}
		for(int i = 0;i < M;++i){
			for(int j = 0;j < F;++j){
				if(Male[i].no(Female[j]))edge[i][j] = 0;
				else edge[i][j] = 1;
			}
		}
		int result = N;
		for(int i = 0;i < M;++i){
			memset(pass,0,sizeof(pass));
			if(FindRight(i)) --result;
		}
		cout << result << endl;
	}
	return 0;
}

