#include <cstdio>

using namespace std;

#define RICHARD false
#define GABRIEL true

int main(){
    int N;
    scanf("%d",&N);
    for(int Case = 1;Case <= N;++Case){
        int X, R, C;
        scanf("%d%d%d",&X,&R,&C);
        bool result = RICHARD;
        if( (R * C) % X == 0 && X < 7 ){
            switch(X){
                case 1: result = GABRIEL; break;
                case 2: result = GABRIEL; break;
                case 3:
                        if(R != 1 && C != 1){
                            result = GABRIEL;
                        }
                        break;
                case 4:
                        if(R > 2 && C > 2){
                            result = GABRIEL;
                        }
                        break;
                case 5:
                        if(R > 3 && C > 3){
                            result = GABRIEL;
                        }
                        break;
                case 6:
                        if(R > 3 && C > 3){
                            result = GABRIEL;
                        }
                        break;
            }
        }
        printf("Case #%d: %s\n", Case, result ? "GABRIEL" : "RICHARD");
    }
}
