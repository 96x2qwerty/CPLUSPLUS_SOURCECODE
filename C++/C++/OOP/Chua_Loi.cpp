#include<iostream>
#include<conio.h>
using namespace std;

class ABC {
	public: 
	virtual void In() 
	{ 
		cout<<"ABC"; }
};
class XYZ: public ABC {
	public: 
	void In() { cout << "XYZ"; }
};
class TUV: public XYZ {
	public:
	void In() { cout << "TUV"; }
};
main(){
	ABC *pa, a;
	XYZ *pb, b; 
	TUV *pc, c;	
	pa = &b; 
		pa->In(); 
	pa = &c; 
		pa->In();
	pb = &a; 
		pb->In();
	pb = &c; 
		pb->In();
	pc = &a; 
		pc->In();
	pc = &b; 
		pc->In();
}
