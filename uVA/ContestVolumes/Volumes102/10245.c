#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct{
    double x;
    double y;
}Point;
double getClosestPair(Point *data,int start,int end);
double getDist(Point *p1,Point *p2);
int compare(const void *a,const void *b);
int main(void){
    int pointCount,i;
    double result;
    Point *data;
    while(scanf("%d",&pointCount) != EOF){
	if(pointCount == 0)break;
	data = (Point *)malloc(sizeof(Point) * pointCount);
	for(i = 0; i < pointCount; i++)
	    scanf("%lf%lf",&((data+i) -> x),&((data+i) -> y));
	qsort(data,pointCount,sizeof(Point),compare);
	result = getClosestPair(data,0,pointCount - 1);
	result <= 10000.0000 ? printf("%.4f\n",result) : puts("INFINITY");
        free(data);
    }
    return 0;
}
double getClosestPair(Point *data,int start,int end){
    const int middle = start + (end - start) / 2;
    int lastTestPoint = middle + 1, firstTestPoint = middle, i, j;
    double left,right,result,temp;
    if(end == start)return 10001.0f;
    left  = getClosestPair(data, start, middle);
    right = getClosestPair(data, middle + 1, end);
    result = left > right ? right : left ;
    while( (data + middle) -> x - (data + firstTestPoint) -> x < result / 2 && firstTestPoint > start)firstTestPoint--;
    while( (data + (lastTestPoint)) -> x - (data + middle) -> x < result / 2 && lastTestPoint < end)lastTestPoint++;
    for(i = firstTestPoint;i <= middle; i++)
	for(j = middle + 1;j <= lastTestPoint; j++){
	    temp = getDist(data + i, data + j);
	    if(temp < result)result = temp;
	}
    return result;
}
double getDist(Point *p1,Point *p2){
    return sqrt(pow(p1 -> x - p2 -> x,2) + pow(p1 -> y - p2 -> y,2));
}
int compare(const void *a,const void *b){
    double temp = (((Point *)a) -> x - ((Point *)b) -> x) ;
    return temp == 0 ? 0 : temp > 0 ? 1 : -1;
}
