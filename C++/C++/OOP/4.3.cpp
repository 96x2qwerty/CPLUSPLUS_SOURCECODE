#include<iostream>
using namespace std;
class TS
{
	public:
		string ten;
		float d1, d2, d3;
		TS(string ten="", float d1=0, float d2=0, float d3=0);
		friend istream &operator>>(istream &is, TS &p)
		{
			cout<<"Nhap ten TS: ";
			cin.ignore();
			getline(is, p.ten);
			cout<<"Diem mon 1: ";
			is>>p.d1;
			cout<<"Diem mon 2: ";
			is>>p.d2;
			cout<<"Diem mon 3: ";
			is>>p.d3;
			return is;
		}
		friend ostream &operator<<(ostream &os, TS &p)
		{
			os<<"\nThong tin thi sinh: "<<endl
				<<"Ten TS: "<<p.ten<<endl
				<<"Diem mon 1: "<<p.d1<<endl
				<<"Diem mon 2: "<<p.d2<<endl
				<<"Diem mon 3: "<<p.d3<<endl
				<<"Tong diem: "<<p.tong()<<endl;
		}
		float tong()
		{
			return d1+d2+d3;
		}
};
TS::TS(string ten1, float dd1, float dd2, float dd3)
{
	ten=ten1;
	d1=dd1;
	d2=dd2;
	d3=dd3;
}
main()
{
	TS a;
	cin>>a;
	cout<<a;
}

