#include<stdio.h>
#include<vector>
#include<set>
#include<algorithm>
#include<utility>
using namespace std;
bool compareFirst(pair<int,int> a, pair<int,int> b){
    return a.first < b.first;
}
bool compareSecond(pair<int,int> a, pair<int,int> b){
    if(a.first == b.first)return false;
    return a.second < b.second;
}
int main(void){
   int testCases,currentCase = 1, M, N, K;
   long long int crossCount;
   int temp, cityEast, cityWest;
   scanf("%d",&testCases);
   while(testCases--){
      vector<pair<int,int> > highways;
      set<pair<int,int>,bool(*)(pair<int,int>,pair<int,int>)> tree(compareSecond);
      highways.reserve(100000);

      crossCount = 0;
      scanf("%d%d%d",&N,&M,&K);
      temp = K;
      while(temp--){
           scanf("%d%d", &cityEast, &cityWest);
           highways.push_back( make_pair(cityEast , cityWest) );
      }
      sort(highways.begin(), highways.end(), compareFirst);
      for(vector<pair<int,int> >::iterator a = highways.begin(); a != highways.end(); a++){
	  tree.insert(*a);
          crossCount += distance(tree.find(*a),tree.end()) - 1;
      }
      printf("Test case %d: %lld\n",currentCase++,crossCount);
   }
   return 0;
}
