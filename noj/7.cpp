#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct Work{
	int a,index;
	double b;	
	Work(int A,int Index,double B):a(A),index(Index),b(B){ }
};
bool operator<(const Work &a,const Work &b){
	if(a.b != b.b) return a.b < b.b;
	return a.index<b.index;
}
int main(){
	int Testcases,flag = 0;
	scanf("%d",&Testcases);
	while(Testcases--){
		if(flag == 0)flag = 1;
		else puts("");
		int lines,temp,temp2;
		vector<Work> work;
		scanf("%d",&lines);
		for(int i = 1;i <= lines;++i){
			scanf("%d%d",&temp,&temp2);
			work.push_back(Work(temp,i,(double)temp/temp2));
		}
		sort(work.begin(),work.end());
		for(int i = 0;i < work.size();++i){
			if(i)putchar(' ');
			printf("%d",work[i].index);
		}
		puts("");
	}
	return 0;
}
