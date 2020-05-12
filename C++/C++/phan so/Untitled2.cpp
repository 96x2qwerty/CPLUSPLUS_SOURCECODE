#include<iostream>
#include<conio.h>
using namespace std;

class PS
{
	int ts,ms;
	public:
		void nhap();
		void xuat();
		PS()
		{
			ts=ms=1;
		}
		PS(int t,int m)
		{
			ts=t;
			ms=m;
		}
	
		PS operator +(PS b);
		void operator -();
		bool operator >(PS b);
};

PS PS:: operator +(PS b)
{
	PS y;
	y.ts=ts*b.ms+ms*b.ts;
	y.ms=ms*b.ms;
	return y;
}

void PS:: operator -()
{
	ts=-ts;
}

bool PS:: operator >(PS b)
{
	return ((float)ts/ms>(float)b.ts/b.ms)? true:false;
}

void PS:: nhap()
{
	cout<<"Nhap tu so,mau so: ";
	cin>>ts>>ms;
}

void PS:: xuat()
{
	cout<<ts<<"\\"<<ms<<endl;
}

main()
{
	PS a,b,c;
	a.nhap();
	b.nhap();
	a.xuat();
	b.xuat();
	if(a>b)
	cout<<"a>b";
	else cout<<"a<b"<<endl;
	c=a+b;
	c.xuat();
	-a;
	a.xuat();
	getch();
}
