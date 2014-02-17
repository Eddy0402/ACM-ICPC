#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
vector<int> ugly;
void init(void){
	int a,b,c,tempint;
	double temp;
    for(a = 0;a < 32;a++)
		for(b = 0; b < 21;b++)
			for (c = 0; c < 15; c++){
				temp = pow(2,a) * pow(3,b) * pow (5,c);
				if(temp <= 2147483647){
					tempint = floor(temp + 0.5);
				    ugly.push_back( tempint );	
				}
			}
}
int main(void){
    int i = 0;
	init();
	sort(ugly.begin(),ugly.end());
	printf("%d\n",ugly[1499]);
    return 0;
}
