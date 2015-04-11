#include <cstdio>

using namespace std;

int main(){
    int N;
    scanf("%d",&N);
    for(int Case = 1;Case <= N;++Case){
        int SMax;
        scanf("%d",&SMax);
        int non_shy_needed = 0;
        int skip = 0;
        for(int i = 0;i < SMax + 1;++i){
            int in;
            scanf("%1d",&in);
            if(in == 0){ // shy level empty
                if(skip > 0){
                    skip--;
                }else{
                    non_shy_needed++;
                }
            }else{
                skip += in - 1;
            }
        }
        printf("Case #%d: %d\n", Case, non_shy_needed);
    }
}
