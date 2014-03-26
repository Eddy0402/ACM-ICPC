#include<iostream>
#include<sstream>
#include<strstream>
#include<string>
using namespace std;
char input[5000000];
string map[50];
int main(void){
	ios::sync_with_stdio(false);
	cin.read(input,4999999);
    istrstream sin(input);
#define cin sin
	int TestCase;
	cin >> TestCase;
	bool flag = false;
	while(TestCase--) {
		int row,column,max=0;
		if(flag)cout << endl;
		else flag = true;

		cin >> map[0];
		row = map[0].size();
		column = row;
		for(int i = 1; i < row; i++){
			cin >> map[i];
		}

		for(int rowF = 0; rowF < row; ++rowF) {
			int sum[50] = {};
			for(int rowE = rowF; rowE < row; ++rowE) {
				int vsum = 0,length = 0,width = 0;
				for(int i = 0; i < column; i++) {
					sum[i] += map[rowE][i]-'0';
					if(vsum != length*width){
						vsum = 0;
						length = 0;
					}
					vsum += sum[i];
					++length;
					width = rowE - rowF + 1;
					if(vsum == length * width)
						max = max > vsum ? max : vsum;

				}
			}
		}
		cout << max << endl;
	}
	return 0;
} 

