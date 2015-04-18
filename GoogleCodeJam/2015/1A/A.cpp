#include <cstdio>
#include <vector>

using namespace std;

int main(){
    int TestCase;
    scanf("%d",&TestCase);
    for(int Case = 1;Case <= TestCase;++Case){
        int TimePoint, Method1 = 0, Method2 = 0, maxrate = 0;
        scanf("%d",&TimePoint);
        vector<int> Times;
        for(int i = 0;i < TimePoint;++i){
            int tmp;
            scanf("%d",&tmp);
            Times.push_back(tmp);
            if(i > 0){
                int m1ate = Times[i-1] - Times[i];
                if(m1ate > 0) Method1 += m1ate;
                if(m1ate > maxrate) maxrate = m1ate;
            }
        }
        for(int i = 0;i < TimePoint - 1;++i){
            if(Times[i] > maxrate)
                Method2 += maxrate;
            else
                Method2 += Times[i];
        }
        printf("Case #%d: %d %d\n", Case, Method1, Method2);
    }
}
