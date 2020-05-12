#include<conio.h>
#include<string>
#include<iostream>
using namespace std;
class NV
{
	string tennv;
	int manv;
	float hsl;
	int pc;
	int tu;
	public:
		NV()
		{
			tennv=" ";
			manv=0;
			hsl=0;
			pc=0;
			tu=0;
		}
		void nhap();
		void xuat();
		float luong()
		{
			return hsl*1150+pc-tu;
		}
};
void NV::nhap()
{
	cout<<"nhap ten nhan vien: ";
	cin.ignore(1);
	getline(cin,tennv);
	cout<<"nhap ma nhan vien: ";
	cin>>manv;
	cout<<"nhap he so luong: ";
	cin>>hsl;
	cout<<"nhap phu cap: ";
	cin>>pc;
	cout<<"nhap so tien tam ung: ";
	cin>>tu;
}
void NV::xuat()
{
	cout<<"nhap ten nhan vien: "<<tennv
	<<"nhap ma nhan vien: "<<manv
	<<"nhap he so luong: "<<hsl
	<<"nhap phu cap: "<<pc
	<<"nhap so tien tam ung: "<<tu;
}
class canbo:public NV
{
	string chucvu;
	int pccv;
	public:
		void nhap();
		void xuat();
	float luong()
		{
			return NV::luong()+pccv;	
		}
};
void canbo::nhap()
{
	NV::nhap();
	cout<<"ten chuc vu: ";
	cin.ignore(1);
	getline(cin,chucvu);
	cout<<" nhap phu cap chuc vu: ";
	cin>>pccv;
}
void canbo::xuat()
{
	NV::xuat();
	cout<<"ten chuc vu: "<<chucvu
	<<"nhap phu cap chuc vu: "<<pccv;
}
