#include<iostream>
#include<vector>
#include<string>
using namespace std;
void print(vector<string> &title,vector<string>::iterator remain,int size,int current,vector<string>& finish){
	if(current == size){
		bool flag = false;
		for(auto a : finish){
			if(flag)cout << ", ";
			else flag = true;
			cout << a;
		}
		cout << "\n";
		return;
	}
	if(remain == title.end())return;
	finish.push_back(*remain);
	print(title,remain+1,size,current + 1,finish);
	finish.pop_back();
	print(title,remain+1,size,current,finish);
}

int main(){
	int TestCase,min,max;
	cin >> TestCase;
	bool flag = false;
	while(TestCase--){
		if(flag)cout << "\n\n";
		else flag = true;
		string temp2;
		while(temp2 == "")
			getline(cin,temp2);
		switch(sscanf(temp2.c_str(),"%d%d",&min,&max)){
			case 1:max = min;break;
			case 0:min = 1;max = -1;
		}
		string temp;
		vector<string> title;
		for(;;){
			getline(cin,temp);
			if(temp != "")title.push_back(temp);
			else break;
		}
		if(max == -1)max = title.size();
		for(int i = min;i <= max;++i){
			if(i != min)cout << "\n";
			cout << "Size " << i << "\n"; 
			vector<string> temp;
			print(title,title.begin(),i,0,temp);
		}
	}
	cout << "\n";
	return 0;
}
