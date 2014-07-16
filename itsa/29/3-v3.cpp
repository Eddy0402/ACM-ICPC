#include<iostream>
#include<string>
#include<cstdio>
#include<cstdlib>
using std::string;
int Lunar(int y)
{
	if( (y%4==0 && y%100!=0)||y%400==0)
		return 1;
	else
		return 0;
}
inline void Error()
{
	printf("invalid date\n");
}
int main()  // 2000 01 01 Sat.
{
	string week[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
	int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int n, y, m, d, lunar, res, i;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d %d %d", &y, &m, &d);
		if( (y<2000) || (m<0 || m>12))
			Error();
		else{
			lunar = Lunar(y);
			if( (1-lunar) && m==2 && d>28)
				Error();
			else{
				if( d<1 ){
					Error();
				}else if(m!=2 && d>days[m-1]){
					Error();
				}else if(m==2 && d>days[m-1]+lunar){
					Error();
				}else{
					res = d%7;
					for(i=0; i+1<m; i++)
					{
						res += days[i];
						if(i==1){
							res += lunar;
						}
					}
					res = (res + (y-1)%7 + ((y-1)/4)%7 - ((y-1)/100)%7 + ((y-1)/400)%7);
					res = (res)%7;
					printf("%s\n", week[res].c_str());
				}
			}
		}
	}
return 0;
}
