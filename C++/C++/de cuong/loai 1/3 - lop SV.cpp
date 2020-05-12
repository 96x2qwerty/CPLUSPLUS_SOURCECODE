#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;

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
};

void SV::nhap()
{
	cout<<"Nhap ten SV: ";
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
		<<"\nDiem trung binh: "<<dtb();
}

float SV::dtb()
{
	return((d1+d2+d3)/3);
}

main()
{
	SV a("NHH","45437",7,8,9);
	//a.nhap();
	a.xuat();
	getch();
}
