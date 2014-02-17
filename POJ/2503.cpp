#include<cstdio>
#include<map>
#include<string>
using namespace std;
map<string,string> dictionary;
int main(void){
	char ac[20],bc[20],cc[30];
	string a,b,c;
	while(gets(cc)){
		if(sscanf(cc,"%s%s",ac,bc) != 2)break;
		a.assign(ac);
		b.assign(bc);
		dictionary[b] = a;
	}
	while(EOF != scanf("%s",cc)){
		c.assign(cc);
		c = dictionary[c];
		if(*c.c_str()=='\0')puts("eh");
		else puts(c.c_str());
	}
	return 0;
}
