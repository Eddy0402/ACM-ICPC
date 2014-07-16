#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
string fibonacci[5003] = {"0","1"};
string itoa(int a){
	char out[10];
	sprintf(out,"%d",a);
	return string(out);
}
void add(string &a,string &b,string &out){
	int add = 0;
	size_t size = a.size() > b.size() ? a.size() : b.size() ;
	out.reserve(size + 2);
    string::iterator i = a.begin(),j = b.begin();
	for(i, j ; i != a.end() && j != b.end(); ++i,++j ){
		out.append ( itoa((*i - '0' + *j - '0' + add) % 10));
		if(*i - '0' + *j - '0' + add >= 10)add = 1; else add = 0;
	}
	if(i == a.end())
		while(j != b.end()){
			out.append(itoa((*j - '0' + add) % 10));
			if(*j - '0' + add >= 10)add = 1; else add = 0;
			++j;
		}
	else
		while(i != a.end()){
			out.append(itoa((*i - '0' + add) % 10));
			if(*i - '0' + add >= 10)add = 1; else add = 0;
			++i;
		}
	if(add) out.append(string("1"));
}
int main(){
	int input,i;
	ios::sync_with_stdio(false);
	for(i = 2;i < 5002; ++i)
		add(fibonacci[i-1],fibonacci[i-2],fibonacci[i]);
	while(cin >> input){
		cout << "The Fibonacci number for " << input << " is ";
		for(string::reverse_iterator a = fibonacci[input].rbegin();
			a != fibonacci[input].rend(); ++a)
			cout << *a;
		cout << endl;
	}
	return 0;
}
