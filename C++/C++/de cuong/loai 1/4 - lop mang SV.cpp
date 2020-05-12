#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;

class DSSV;
class SV
{
	string hoten,masv;
	float d1,d2,d3;
	public:
		SV(string ht="",string masv1="",float d11=0,float d22=0,float d33=0)
		{
			hoten = ht;
			masv = masv1;
			d1=d11;d2=d22;d3=d33;
		}
		
		void nhap();
		void xuat();
		float dtb();
	friend class DSSV;
};

void SV::nhap()
{
	cout<<"Nhap ten SV: ";
	cin.ignore(1);
	getline(cin,hoten);
	cout<<"Nhap ma SV: ";
	getline(cin,masv);
	cout<<"Nhap d1,d2,d3: ";
	cin>>d1>>d2>>d3;
}

void SV::xuat()
{
	cout<<"\nSV vua nhap la: "<<hoten
		<<"\nMa SV: "<<masv
		<<"\nd1, d2, d3: "<<d1<<", "<<d2<<", "<<d3
		<<"\nDiem trung binh: "<<dtb()<<endl;
}

float SV::dtb()
{
	return((d1+d2+d3)/3);
}


class DSSV:public SV
{
	SV *a;
	int n;
	public:
		DSSV(int n1=0,SV *b=NULL)
		{
			n=n1;
			a=b;
		}
		
		~DSSV()
		{
			if(n!=0)
			delete[] a;
		}
		
		void nhapds()
		{
			cout<<"Nhap so SV:\n";
			cin>>n;
			a=new SV[n];
			for(int i=0;i<n;i++)
			{
				cout<<"Nhap SV thu "<<i+1<<endl;
				SV:nhap();
			}
		}
		
		void xuatds()
		{
			cout<<"\nDS vua nhap la: ";
			for(int i=0;i<n;i++)
			{
				cout<<"\nSV thu "<<i+1<<":";
				SV:xuat();
			}
		}
};

main()
{
	DSSV a;
	a.nhapds();
	a.xuatds();
	getch();
}
