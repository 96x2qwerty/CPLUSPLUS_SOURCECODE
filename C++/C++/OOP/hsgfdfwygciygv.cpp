#include<iostream>
using namespace std;

class A{
private: int x,y;
public:
A(int x1, int y1){x=x1;y=y1;}
A(const A&a){x=a.x;y=a.y;}
A operator+(int a){ x+=a;y+=a; return *this;}
void in(){cout<<x<<","<<y;cout<<endl;}
};	main(){
	A a1(5,5), a2(5,5);
	A x=a1+3;
	A y=a2+4;
	x.in(); 
	a1.in();
	y.in(); 
	a2.in();
}

