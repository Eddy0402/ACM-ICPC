#include<cstdio>
#include<vector>
using namespace std;
int main(){
	int n[6],Case = 1;
	while(scanf("%d%d%d%d%d%d",n,n+1,n+2,n+3,n+4,n+5)){
		if(!n[1]&&!n[2]&&!n[3]&&!n[4]&&!n[5]&&!n[0])break;
		
		int total=0;
		for(int i = 0;i < 6;++i)
			total += (i+1)*  n[i];
		bool result = !(total % 2);
		if(result){
			vector<int> re(200000);
			vector<int> r;
			for(int size = 0;size < 6;++size){
				for(int i = 0; i < 20;++i){
					if(n[size] == 0)break;
					if(n[size] >= 1u << i){
						r.push_back((1u<<i) * (1+size));
						n[size] -= 1u << i;
					}else{
						r.push_back(n[size] * (1+size));
						n[size] = 0;
					}
				}
			}
			int target = total / 2;
			for(int i = 0;i < r.size();++i)
				for(int j = target;j >= r[i];--j)
					if(re[j-r[i]] + r[i] > re[j])
						re[j] = re[j-r[i]] + r[i];
			if(re[target]!=target) result = false;
		}
		printf("Collection #%d:\n",Case++);
		if(result)puts("Can be divided.");
		else puts("Can't be divided.");
		puts("");
	}
	return 0;
}
