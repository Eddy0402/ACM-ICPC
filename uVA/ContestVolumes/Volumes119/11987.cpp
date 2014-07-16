#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
class Set{
	public:
		void add(int a,int b){
			if(root(a) == root(b))return;
			int aa = root(a);
			sum[root(b)] += sum[root(a)];
			count[root(b)] = count[root(b)] + count[root(a)];
			persons[root(a)] =  root(b);
		}
		int root(int a){
			if(newNo[a] != -1)a = newNo[a];
			int temp = a;
			while(persons[a] != a) a = persons[a];
			persons[temp] = a;
			return a;
		}
		void move(int number,int target){
			if(root(number) == root(target))return;
			--count[root(number)];
			sum[root(number)] -= number;
			newNo[number] = persons.size();
			persons.push_back(newNo[number]);
			newNo.push_back(-1);
			count.push_back(1);
			sum.push_back(number);
				
			sum[root(target)] += number;
			++count[root(target)];
			persons[newNo[number]] = root(target);
		}
		int Count(int a){ return count[root(a)]; }
		long long Sum(int a){ return sum[root(a)]; }
		Set(int Count){
			for(int i = 0;i <= Count;++i)
				persons.push_back(i);
			for(long long i = 0;i <= Count;++i)
				sum.push_back(i);
			for(int i = 0;i <= Count;++i)
				newNo.push_back(-1);
			for(int i = 0;i <= Count;++i)
				count.push_back(1);
		}
//	private:
		vector<int> persons;
		vector<long long> sum;
		vector<int> newNo;
		vector<int> count;
};
int main(){
	int Count,Commands;
	while(scanf("%d%d",&Count,&Commands) != EOF){
		Set person(Count);
		int command,arg1,arg2;
		while(Commands--){
			scanf("%d",&command);
			switch(command){
				case 1: //union
					scanf("%d%d",&arg1,&arg2);
					person.add(arg1,arg2);	break;
				case 2: //move
					scanf("%d%d",&arg1,&arg2);
					person.move(arg1,arg2);
					break;
				case 3: //output
					scanf("%d",&arg1);
					printf("%d %lld\n",person.Count(arg1),person.Sum(arg1));	break;
			}
		}
	}
	return 0;
}
