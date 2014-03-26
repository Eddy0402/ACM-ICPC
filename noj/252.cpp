#include<cstdio>
#include<utility>
#include<vector>
#include<map>
using namespace std;
struct Task{
	int Day,Count,MaxNeed;
	Task(int day,int count,int maxneed) : Day(day) , Count(count) ,MaxNeed(maxneed) {}
};
int dfs(int start,vector<Task> &tasks,multimap<int,int> &dependencies){
	int maxRoute = 0;
	pair<multimap<int,int>::iterator,multimap<int,int>::iterator> next = dependencies.equal_range(start);
	while(next.first != next.second){
		int &nextTotalMax = tasks[(*next.first).second].MaxNeed;
		if(nextTotalMax == -1){
			nextTotalMax = dfs((*next.first).second,tasks,dependencies);
		}
		if(maxRoute < nextTotalMax) maxRoute = nextTotalMax;
		++next.first;
	}
	return maxRoute + tasks[start].Day;
}
int main(){
	int TasksCount,DependenciesCount;
	while(scanf("%d",&TasksCount) != EOF){
		vector<Task> tasks;
		vector<int> start;
		multimap<int,int> dependencies;
		int temp,temp2;
		for(int i = 0;i < TasksCount;++i){
			scanf("%d",&temp);
			tasks.push_back(Task(temp,0,-1));
		}
		scanf("%d",&DependenciesCount);
		for(int i = 0;i < DependenciesCount;++i){
			scanf("%d%d",&temp,&temp2);
			dependencies.insert(make_pair(temp - 1,temp2 - 1));
			tasks[temp2 - 1].Count++;
		}
		for(int i = 0;i < TasksCount;++i)
			if(tasks[i].Count == 0) start.push_back(i);
		int result = 0;
		for(int i = 0;i < start.size();++i){
			int route = dfs(start[i],tasks,dependencies);
			if(route > result)result = route;	
		}
		printf("%d\n",result);
	}
	return 0;
}
