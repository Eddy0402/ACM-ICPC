#include<cstdio>
#include<iostream>
#include<strstream>
#include<sstream>
#include<vector>
using namespace std;
char input[100000];
int main(void){
	fread(input,999999,1,stdin);
	istrstream sin(input);
	stringstream sout;
	for(int TestCase = 1; /* */; ++TestCase){
		int Depth, X[10] , NumberVVA;
		string Node, VVA;
		sin >> Depth;
		if(Depth == 0)break;
		for(int i = 0; i < Depth; ++i){
			while(sin.peek() != 'x')sin.get();
			sin.get();
			int temp;
			sin >> temp;
			X[temp - 1] = 1 << (Depth - i - 1);
		}
		sin >> Node >> NumberVVA;
		sout <<"S-Tree #" << TestCase << ":\n";
		while(NumberVVA--){
			unsigned Position = 0;
			sin >> VVA;
			for(int i = 0; i < Depth; ++i)
				Position = Position | ( (VVA[i] - '0') * X[i] );
			sout << Node[Position];
		}
		sout << "\n\n";
	}
	cout << sout.rdbuf();
	return 0;
}
