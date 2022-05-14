#include<stdio.h>
#include<stdlib.h>
#include"utility.h"

double f(double x){
	
	return sqrt(1-x*x);

}

void main(){
	int seed=354;
	int a=65;
	int m=1021;
	set_seed(seed);

//integration method
	double f_sum=0;
	double N=500;
	for(int i=0;i<N;i++){
		f_sum+=f((1.0*mlcg_rand(a,m))/m);
	}
	
	printf("\n value of pi=%lf \n"f_sum*4/N);

//throwing point method
	double sum=0;
	for(int i=0;i<N;i++){
		double xx=(1.0*mlcg_rand(a,m))/m;
		double yy=(1.0*mlcg_rand(a,m))/m;
		
		//if the point drawn is inside the circle count the event
		if((xx*xx+yy*yy)<=1)
			sum++;
		
	}	
	
	printf("\n value of pi=%lf \n",sum/N);
	

//Q3
	double steinmetz_vol=0;
	double xt,yt,zt;
	for(int i=0;i<N;i++){
		xt=(1.0*mlcg_rand(a,m))/m;
		yt=(1.0*mlcg_rand(a,m))/m;
		zt=(1.0*mlcg_rand(a,m))/m;
		//Two perp. Cylinder one along x axis other along y axis
		if((yt*yt+zt*zt<=1)&&(xt*xt+zt*zt<=1))
			steinmetz_vol++;
		
	}



}
