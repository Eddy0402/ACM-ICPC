#include<sstream>
#include<iostream>
using namespace std;
int main(){
	int a;string b = "100";
	stringstream ss(b);
	ss >> a;
	cout << a << endl;
}
