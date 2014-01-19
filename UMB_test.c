#include<stdio.h>
#include <math.h>
/*calculate UMB corrections for wheelbase and wheel diameters*/

#define iters	5
float cw_x[]={-0.04,-0.98,0.165,0.0,-0.84};
float cw_y[]={-1.12,0.12,-0.375,-0.63,-0.37};

float ccw_x[]={0.90,0.35,2.12,1.32,-1.67};
float ccw_y[]={1.05,0.78,1.11,0.93,0.18};

float L=4.0;
float wheelBase=0.2425;
float wheelDiameter=0.12;
float Eb=0.0;
float Ed=0.0;

void main(int argc,char **argv){

	float sum_cwx = 0.0;
	float sum_cwy = 0.0;
	float sum_ccwx = 0.0;
	float sum_ccwy = 0.0;


	float avg_cwx = 0.0;
	float avg_cwy = 0.0;
	float avg_ccwx = 0.0;
	float avg_ccwy = 0.0;
	
	int i;

	for(i=0;i<iters;i++){
		sum_cwx += cw_x[i];
		sum_cwy += cw_y[i];
		sum_ccwx += ccw_x[i];
		sum_ccwy += ccw_y[i];
	}

	avg_cwx = sum_cwx/iters;
	avg_cwy = sum_cwy/iters;
	avg_ccwx = sum_ccwx/iters;
	avg_ccwy = sum_ccwy/iters;

	printf("Average : cw_x [%f] cw_y [%f] | ccw_x [%f] ccw_y [%f]\n",avg_cwx,avg_cwy,avg_ccwx,avg_ccwy);

	float beta_x = (avg_cwx - avg_ccwx)*180.0 / (-4*L*M_PI);
	float beta_y = (avg_cwy + avg_ccwy)*180.0 / (-4*L*M_PI);
	float beta = beta_x + beta_y / 2.0;

	float alpha_x = (avg_cwx + avg_ccwx)*180.0 / (-4*L*M_PI);
	float alpha_y = (avg_cwy - avg_ccwy)*180.0 / (-4*L*M_PI);
	float alpha = alpha_x + alpha_y / 2.0;

	printf("Beta x[%f] y[%f] avg[%f] | alpha x[%f] y[%f] avg[%f]\n",beta_x,beta_y,beta,alpha_x,alpha_y,alpha);

	float R = (L/2)/sin((beta/2)* M_PI/180);
	float Dr = R + (wheelBase/2);
	float Dl = R - (wheelBase/2);

	Ed = Dr/Dl;
	Eb = 90.0/(90.0 - alpha);
		
	float wheelBase_actual = Eb * wheelBase;
	float cLeft = 2.0 / (Ed + 1);
	float cRight = 2.0 / ((1/Ed) + 1);
		
	printf("\n********************************\n");
	printf("wheelBase Eb = [%f] |  nominal [%f] ----> actual [%f]\n\n",Eb,wheelBase,wheelBase_actual);

	printf("WheelDiameter Ed = [%f] | correctionLeft [%f] correctionRight [%f]\n",Ed,cLeft,cRight);
	printf("**********************************\n");

}

