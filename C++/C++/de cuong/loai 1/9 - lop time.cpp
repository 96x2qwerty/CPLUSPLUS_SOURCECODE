#include<iostream>
#include<conio.h>
#include<time.h>
using namespace std;

class Time
{
	long h,m,s;
	public:
		
		Time(long h1 = 0,long m1=0, long s1=0)
		{
			h = h1;
			m = m1;
			s = s1;
		}
		
		bool ktra(Time a);
		friend Time doigio(long x);
		int doigiay();
		Time operator ++(int );
		Time operator -(Time b);
		Time operator +(int b);
		friend istream &operator >>(istream &is,Time &t);
		friend ostream &operator <<(ostream &os,Time &t);
};

bool Time:: ktra(Time a)
{
	if(h>=0||h<24&&m>=0||m<60&&s>=0||s<60)
	return true;
	else return false;
}

//doi tu s -> h/m/s
Time doigio(long x)
{
	Time tam;
	tam.h = x/3600;
	x-=3600*tam.h;
	tam.m = x/60;
	x-=60*tam.m;
	tam.s = x;
	return tam;
}

//doi tu h/m/s -> s
int Time::doigiay()
{
	return(h*3600 + m*60 + s);
}

//cac toan tu
Time Time:: operator ++(int )
{
	long x = this->doigiay()+1;
	return doigio(x);
}

Time Time:: operator +(int b)
{
	long x= this->doigiay()+b;
	return doigio(x);
	
} 

Time Time:: operator -(Time b)
{
	Time t;
	long x=this->doigiay();
	long x1=b.doigiay();
	if(x>x1)
	t=doigio(x-x1);
	else t=doigio(x1-x);
	return t;
}

istream &operator >>(istream &is,Time &t)
{
	cout<<"Nhap gio, phut, giay:";
	do
	{
		is>>t.h>>t.m>>t.s;
	}while(ktra(t));
}

ostream &operator <<(ostream &os,Time &t)
{
	os<<"Thoi gian: "<<t.h<<"h, "<<t.m<<"m, "<<t.s<<"s."<<endl;
}

main()
{
	Time a,b,d;
	int c;
	cin>>a;
	cout<<a;
	a=a++;
	cout<<"Tang len 1s: "<<a;
	cout<<"Tang len ?s: ";
	cin>>c;
	b=a+c;
	cout<<b;
	cout<<"\nTru khoang thoi gian.\nNhap khoang thoi gian muon tru:\n";
	cin>>b;
	d=a-b;
	cout<<d;
}
