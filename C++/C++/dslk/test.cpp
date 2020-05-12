#include<iostream>
#include<conio.h>
using namespace std;
/*
class A 
{
          int x,y;
     public:
          A() 
		  { x = 1; y=1; }
		  
          A(const A & a) 
		  { x = a.x; y=a.y; }
		  
          const A& operator = (const A & a) 
		  { x = a.x; y=a.y; return *this; }
		  
		  void In()
		  {cout<<x<<":"<<y<<endl;}
};
	   
int main() 
{    A a;  A b=a;a.In(); b.In(); }
*/
/*
class A {
     private:
          int x,y;
     public:
          A(int x1, int y1) 
		  { x = x1; y=y1; }
		  
          void In_X()  
		  { cout<<"x="<<x; }
		  
          void In() 
		  { cout<<x<<", "<<y; }
	};
int main() 
{
     A a(10, 10);
     a.In_X();    
     a.In();   
	 A b(5,5);   
     b.In_X();    
     b.In(); }
*/

class A {
	private:
		int x,y;
	public:
	A(int x1, int y1) 
	{ x = x1; y=y1; }
	
	A(const A & a) 
	{ x = a.x; y=a.y; }
	
	A operator ++(int)
	{ A tmp=*this; 
		x++; 
		y++; 
		return tmp; 
	}
	
	const A& operator ++()
	{	x++; y++; 
		return *this; 
	}
	
	void In()
	{ 
	cout <<x<<","; cout <<y; 
	}
};
int main()
{ 
	A a1(10, 10), a2(15,51); 	
	A x = a1++; 	
	A y = ++a2;	
	x.In(); cout<<" ";
	a1.In(); cout<<" "; 	
	y.In(); cout<<" ";
	a2.In(); cout<<" ";
}

