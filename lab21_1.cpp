#include<iostream>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect R1,Rect R2){
    Rect a;
    if((R1.x+R2.w) > R2.x){
        a.x = R2.x;
        a.w = (R1.x+R1.w) - R2.x;
        if(R1.x+R1.w>R2.x+R2.w){
            a.w = R2.w;
        }
    }else if((R1.x+R1.w) <= R2.x){
        a.w = 0;
        a.x = 0;
    }

    if(R2.y > R1.y-R1.h){
        a.y = R1.y;
        a.h = R1.y-(R2.y-R2.h);
        if((R1.y-R1.h)<(R2.y-R2.h) && R1.y > R2.y){
            a.y = R2.y;
            a.h = R2.h;
        }
    }else if((R1.x+R1.w) <= R2.x){
        a.y = 0;
        a.h = 0;
    }
    return a.w*a.h;
}

int main(){
	Rect R1 = {1,1,5,5};
	Rect R2 = {7,2,3,3};	
	cout << overlap(R1,R2);		


	return 0;
}