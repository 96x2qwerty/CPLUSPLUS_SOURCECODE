#include<iostream>
using namespace std;
class TS
{
	public:
		string ten;
		float d1, d2, d3;
		TS(string ten="", float d1=0, float d2=0, float d3=0);
		virtual void nhap()
		{
			cout<<"Nhap ten TS: ";
			cin.ignore();
			getline(cin, ten);
			cout<<"Diem mon 1, 2, 3: ";
			cin>>d1>>d2>>d3;
		}
		virtual void xuat()
		{
			cout<<"\nThong tin thi sinh: "<<endl
				<<"Ho ten Thi Sinh: "<<ten<<endl
				<<"Diem mon 1, 2, 3: "<<d1<<" "<<d2<<" "<<d3<<endl;
		}
		virtual float tong()
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

class TSUT:public TS
{
	public:
		int dut;
		TSUT(string ten="", float d1=0, float d2=0, float d3=0, int dut=0);
		void nhap()
		{
			TS::nhap();
			cout<<"Nhap diem uu tien: ";
			cin>>dut;
		}
		void xuat()
		{
			TS::xuat();
			cout<<"Diem uu tien: "<<dut;
		}
		float tong()
		{
			return d1+d2+d3+dut;
		}
};
TSUT::TSUT(string ten1, float dd1, float dd2, float dd3, int dut1)
{
	ten=ten;
	d1=dd1;
	d2=dd2;
	d3=dd3;
	dut=dut1;
}
main()
{
	int n;
	cout<<"Nhap n: ";
	cin>>n;
	TS *a[n];
	for(int i=0; i<n; i++)
	{
		int chon;
		cout<<"Nhap chon: ";
		cin>>chon;
		if(chon==1)
			a[i]=new TS();
		if(chon==2)
			a[i]=new TSUT();
		a[i]->nhap();
	}
	cout<<"\nDanh sach thi sinh do: ";
	for(int i=0; i<n; i++)
	{
		if(a[i]->tong()>=13 && a[i]->d1!=0 && a[i]->d2!=0 && a[i]->d3!=0)
		a[i]->xuat();
	}
}

