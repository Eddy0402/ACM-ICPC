#include<cstdio>
#include<algorithm>
#include<utility>
using namespace std;
bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.first == b.first)return a.second < b.second;
	else return a.first < b.first;
}
int processOne(int count){
    vector<pair<int,int> > data;
	int tempNum, result = 0,i;
	for(i = 0;i < count; i++){
		scanf("%d",&tempNum);
        pair<int,int> toAdd(tempNum, i);
        data.push_back(toAdd);
	}
	sort(data.begin(), data.end(), cmp);
    for(i = 0; i < data.size(); i++){
		tempNum = data[i].second - i;
		result += tempNum > 0 ? tempNum : -tempNum;
		printf("%d %d : (%d) %d\n",data[i].first,data[i].second,i,result);
	}
	return result;
}
int main(void){
    int count;
	while(scanf("%d",&count) != EOF && count != 0)
		printf("%d\n",processOne(count));
    return 0;
}
