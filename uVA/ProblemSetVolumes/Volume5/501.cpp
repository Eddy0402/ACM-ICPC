#include<iostream>
#include<strstream>
#include<sstream>
#include<vector>
#include<set>
#include<utility>
char input[5000000];
using namespace std;
int main(void){
	ios::sync_with_stdio(false);
	cin.read(input, 4999999);
	istrstream sin(input);
	stringstream sout;
	int TestCase;
	sin >> TestCase;
	for(int i = 0; i < TestCase; ++i){
		int M,N,temp;
		vector<int> Add,Get;
		set<pair<int,int> > BlackBox;

		if(i != 0) sout << "\n";

		sin >> M >> N;
		Add.reserve(M);
		Get.reserve(N);
		while(M--){
			sin >> temp;
			Add.push_back(temp);
		}
		while(N--){
			sin >> temp;
			Get.push_back(temp);
		}
		vector<int>::iterator ToGet = Get.begin();
		set<pair<int,int> >::iterator Point = BlackBox.begin();
		
		for(int i = 0; i < Add.size(); ++i){
			BlackBox.insert(make_pair(Add[i],-i));
			if(make_pair(Add[i], -i) <= *Point ){
				--Point;
			}
			if(Point == BlackBox.end())
				--Point;
			while(ToGet != Get.end() && *ToGet == i + 1){
				++ToGet;
				sout << (*Point++).first << "\n";
			}
		}
	}

	cout << sout.rdbuf();
	return 0;
}
