#include<iostream>
using namespace std;
long long int min2(long long int col,long long int &p2){
	if(p2 >= col){ p2 -= col; return 0; }
	else{ p2 = 0; return col - p2; }
}
int main(){
    ios_base::sync_with_stdio(false);   
	long long int p1,p2,p3,p4,p5,p6,result;	
	while(cin >> p1 >> p2 >> p3 >> p4 >> p5 >> p6){
		if(p1 == 0 && p2 == 0 && p3 == 0 && p4 == 0 && p5 == 0 && p6 == 0)break;
 		result = p6 + p5 + p4 + (p3 + 3) / 4;
		switch(p3 % 4){
			case 1: p1 = p1 - min2(5,p2) * 2 - 7;break;
			case 2: p1 = p1 - min2(3,p2) * 2 - 6;break;
			case 3: p1 = p1 - min2(1,p2) * 2 - 5;break;
		}
		p1 = p1 - p5 * 11 - 2 * min2(p4 * 5,p2);
		if(p2 > 0){
			result = result + (p2 + 8) / 9;
			p1 = p1 - (9 - p2 % 9) * 4 ;
		}
		if(p1 > 0)
			result = result + (p1 + 35) / 36;
		cout << result << endl;
	}
    return 0;
}
