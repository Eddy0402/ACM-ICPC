#include<iostream>
#include<strstream>
#include<sstream>
#include<stdio.h>
using namespace std;
char input [5000000];
void process(stringstream &sout,int Start,int End,int Height){
	if(Start == End){
		sout << " " << Start;
	}else{
		if((1 << (Height - 1)) - 1 >= End - Start){
			sout << " " << Start;
			process(sout,Start + 1,End,Height - 1);
		}else{
			int Middle = End - (1 << (Height - 1)) + 1;
			sout << " " << Middle;
			process(sout,Start,Middle - 1,Height - 1);
			if(Middle != End)
				process(sout,Middle + 1,End,Height - 1);
		}
	}
}
int main(void){
	ios::sync_with_stdio(false);
	cin.read(input,4999999);
	istrstream sin(input);
	stringstream sout;
	int N,H,TestCase = 0;
	while(++TestCase){
		sin >> N >> H;
		if(N == 0 && H == 0)break;
		sout << "Case " << TestCase << ":";
		if( ((1u << H) - 1) < N){
			sout << " Impossible.\n";
			continue;
		}
		process(sout,1,N,H);
		sout << "\n";		
	}
	cout << sout.rdbuf();
	return 0;
}
