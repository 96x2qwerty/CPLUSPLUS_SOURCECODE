#include<iostream>
using namespace std;
class A{
public:
    virtual void in(){cout<<"A";}
};
class B:public A{
public:
	void in(){cout<<"B";}
};
class C:public B{
public:
         void in(){cout<<"C";}
};	
main(){
A *pa, a;
B *pb, b;
C *pc, c;
pa=&b;pa->in();
pa=&c;pa->in();
pb=&c;pb->in();
}

