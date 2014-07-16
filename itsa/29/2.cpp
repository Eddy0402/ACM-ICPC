#include<cstdio>
#include<algorithm>
using namespace std;
class meal{
	public:
	double w,p,div;
	int num;
	meal(){}
	meal(double ww,double pp,int numm) : w(ww) ,p(pp) ,div(p/w), num(numm) {}
};
bool compare(meal a,meal b){
	return a.div < b.div;
}
int main(void){
	double W,w1,w2,w3,p1,p2,p3;
	while(scanf("%lf%lf%lf%lf%lf%lf%lf",&W,&w1,&w2,&w3,&p1,&p2,&p3) != EOF){
		meal meals[3];
		meals[0] = meal(w1,p1,0);
		meals[1] = meal(w2,p2,1);
		meals[2] = meal(w3,p3,2);
		double PP=0.0,a[3];
		a[0] = 0.0;a[1] = 0.0;a[2] = 0.0;
		std::sort(meals,meals + 3, compare);
		if(w1 == 0 || w2 == 0 || w3 == 0){puts("0"); break;}
		if(meals[2].w > W){
			PP += W * meals[2].div;
			a[meals[2].num] += W;
		}else{
			PP += meals[2].p;
			a[meals[2].num] += meals[2].w;
			W -= meals[2].w;
			if(meals[1].w > W){
			    PP += W * meals[1].div;
			    a[meals[1].num] += W;
			}else{
				PP += meals[1].p;
				a[meals[1].num] += meals[1].w;
			    W -= meals[1].w;
				if(meals[0].w > W - meals[2].w - meals[1].w){
			    	PP += W * meals[0].div;
			    	a[meals[0].num] += W;
				}else{
					PP += meals[1].p;
					a[meals[0].num] += meals[0].w;
				}
			}
		}
		printf("%.3f %.3f %.3f %.3f",a[0],a[1],a[2],PP);
	}
    return 0;


}
