#include <iostream>
using namespace  std;
class A{
public: int x,y;
public:
A(int x1, int y1){x=x1;y=y1;}
A operator-=(int a){x-=a;y-=a;return*this;}
void in(){cout<<x<<","<<y;}
};	main(){
A a1(5,5), a2(10,10);
int u=25;
//a2-=a1;
a1-=u;
a2.in();
a1.in();
}



