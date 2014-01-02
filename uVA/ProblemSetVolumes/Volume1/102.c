#include<stdio.h>
int main(void){
    char *result;
    int A,B,C,D,E,F,G,H,I,sum;
    while(scanf("%d%d%d%d%d%d%d%d%d",&A,&B,&C,&D,&E,&F,&G,&H,&I) != EOF){
        sum = A+F+H; result = "BCG";
        if(A+E+I > sum){sum = A+E+I; result = "BGC";}
        if(C+D+H > sum){sum = C+D+H; result = "CBG";}
        if(C+E+G > sum){sum = C+E+G; result = "CGB";}
        if(B+D+I > sum){sum = B+D+I; result = "GBC";}
        if(B+F+G > sum){sum = B+F+G; result = "GCB";}
        printf("%s %d\n",result,A+B+C+D+E+F+G+H+I-sum);
    }
    return 0;
}
