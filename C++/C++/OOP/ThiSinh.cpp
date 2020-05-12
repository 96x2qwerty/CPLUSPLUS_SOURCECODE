#include <iostream>

using namespace std;

class TS
{
	string hten;
	int ma, ns;
	float d1, d2, d3;
	public:
		TS()
		{
			hten="";
			ma = ns = 0;
			d1 = d2 = d3 = 0.0;
		}
		friend istream &operator>>(istream &is, TS &p);
		friend ostream &operator<<(ostream &os, TS &p);
		TS operator ++();
		TS operator ++(int);
		TS operator --();
		TS operator --(int);
		float tong(){return d1+d2+d3;
		}
};

istream &operator>>(istream &is, TS &p)
{
	cout<<"Nhap ho ten: ";
	getline(is, p.hten);
	cout<<"\nNhap ma TS: ";
	cin>>p.ma;
	cout<<"\nNhap nam sinh: ";
	cin>>p.ns;
	cout<<"\nNhap diem mon 1: ";
	cin>>p.d1;
	cout<<"\nNhap diem mon 2: ";
	cin>>p.d2;
	cout<<"\nNhap diem mon 3: ";
	cin>>p.d3;
}

ostream &operator<<(ostream &os, TS &p)
{
	os<<"Ho ten: "<<p.hten<<endl
		<<"Ma: "<<p.ma<<endl
		<<"Nam Sinh: "<<p.ns<<endl
		<<"Diem 1: "<<p.d1<<endl
		<<"Diem 2: "<<p.d2<<endl
		<<"Diem 3: "<<p.d3<<endl
		<<"Tong diem: "<<p.tong()<<endl;
		return os;
}

TS TS::operator ++()
{
	TS p;
	p.hten=this->hten;
	p.ma=this->ma;
	p.ns=++this->ns;
	p.d1=this->d1;
	p.d2=this->d2;
	p.d3=this->d3;
	return p;
}

TS TS::operator ++(int)
{
	TS temp=*this;
	temp.hten=this->hten;
	temp.ma=this->ma;
	temp.ns=this->ns++;
	temp.d1=this->d1;
	temp.d2=this->d2;
	temp.d3=this->d3;
	return temp;
}

TS TS::operator --()
{
	TS p;
	p.hten=this->hten;
	p.ma=this->ma;
	p.ns=--this->ns;
	p.d1=this->d1;
	p.d2=this->d2;
	p.d3=this->d3;
	return p;
}

TS TS::operator --(int)
{
	TS temp=*this;
	temp.hten=this->hten;
	temp.ma=this->ma;
	temp.ns=this->ns--;
	temp.d1=this->d1;
	temp.d2=this->d2;
	temp.d3=this->d3;
	return temp;
}
main()
{
	TS a;
	cin>>a;
	cout<<a<<endl;
	TS b;
	b=++a;
	cout<<b<<endl;
	TS c;
	c=a++;
	cout<<c<<endl;
//	cout<<a<<endl;
	TS d;
	d=--a;
	cout<<d<<endl;
	TS e;
	e=a--;
	cout<<e<<endl;
}







