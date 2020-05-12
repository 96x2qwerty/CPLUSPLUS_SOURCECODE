#include<iostream>
#include<math.h>
using namespace std;
class ABC{
	int x;
	int *px;
	public:
		ABC();
		ABC(ABC &p);
};
ABC::	ABC(ABC &p)
{
	this-> x=p.x;
	this->px = new int ;
	this->px=p.px;
	}
	ABC a;
	ABC b=a;

