#include<algorithm>
#include<cstdio>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
int main(){
	int N,DistanceLeft,Fuel,result = 0,dist,fuel,FuelNeeded;
	scanf("%d",&N);
	vector<pair<int,int> > Stops;
	priority_queue<int> StopAvailable;
	while(N--){
		scanf("%d%d",&dist,&fuel);
		Stops.push_back( make_pair(dist,fuel) );
	}
	Stops.push_back( make_pair(0,0) ); //town
	scanf("%d%d",&DistanceLeft,&Fuel);
	sort(Stops.begin(),Stops.end());
	for(vector<pair<int,int> >::reverse_iterator it = Stops.rbegin(); it != Stops.rend(); ++it){
		FuelNeeded = DistanceLeft - (*it).first;
		while(FuelNeeded > Fuel){
			if(StopAvailable.size() == 0){
				result = -1;
				break;
			}
			Fuel += StopAvailable.top();
			StopAvailable.pop();
			result++;
		}
		Fuel -= FuelNeeded;
		DistanceLeft -= FuelNeeded;
		StopAvailable.push( (*it).second );
		if(result == -1)break;
	}
	printf("%d\n",result);
	return 0;
}
