#include<iostream>
using namespace std;
class A 
{
private: 
	int x, y; 
public:  
	A(int x1, int y1) 
	{ 
		x = x1; 
		y = y1; 
	}  
	A(const A & a) 
	{ 
		x = a.x; 
		y = a.y; 
	}  
	A & operator--() 
	{ 
		x -= 2; 
		y -= 2; 
		return *this; 
	}  
	void In() 
	{ 
		cout << x << "," << y << endl;
	}
};
int main() 
{ 
	A a1(5, 5); 
	A a2(a1);
	a1.In(); 
	a2.In();
	A x = --a1;
	x.In(); 
}
