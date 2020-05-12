#include<iostream>
using namespace std;
class SV{
	public:
		string ten, ma, gioitinh;
		float diem;
		SV(string tt="", string mm="", string gt="", float d=0)
		{
			ten=tt;
			ma=mm;
			gioitinh=gt;
			diem=d;
		}
		float get_diem(){
			return diem;
		}
		virtual void nhapdl()
		{
			cin.ignore();
			cout<<"\nNhap ten SV: ";
			getline(cin, ten);
			cout<<"\nNhap ma SV: ";
			getline(cin, ma);
			cout<<"\nNhap gt SV: ";
			getline(cin, gioitinh);
			cout<<"\nNhap Diem: ";
			cin>>diem;		}
		virtual void indl()
			{
				cout<<"\nTenSV: "<<ten<<endl
					<<"Ma SV: "<<ma<<endl
					<<"Gioi tinh: "<<gioitinh<<endl
					<<"Diem: "<<diem<<endl;
			}
};

class CBL:public SV
{
	string chucvu;
	public:
		CBL(string tt="", string mm="", string gt="", float d=0, string cv=""):SV(tt, mm, gt, d)
		{
			chucvu=cv;
		}
		void nhapdl()
		{
			SV::nhapdl();
			cin.ignore();			cout<<"\nNhap chuc vu: ";
			getline(cin, chucvu);
		}
		void indl()
		{
			SV::indl();
			cout<<"Chuc vu: "<<chucvu<<endl;
		}
};

main()
{
	int sosv;
	cout<<"Nhap so sv: ";
	cin>>sosv;
	SV *p[sosv];
	int luachon;
	for (int i=0; i<sosv; i++)
	{
		cout<<"\n1. Them 1 SV"<<endl
			<<"2. Them 1 CBL"<<endl
			<<"Nhap lua chon cua ban!";
		cin>>luachon;
		if(luachon==1)
		{
			p[i]=new SV();
			p[i]->nhapdl();
		}else if(luachon==2)
		{
			p[i]=new CBL;
			p[i]->nhapdl();
		}else cout<<"\nNhap lai lua chon!";
		
	}
	for(int i=0; i<sosv; i++)
	{	p[i]->indl();	}
	for(int i=0; i<sosv-1; i++)
	for(int j=i+1; j<sosv; j++)
	if(p[i]->ten > p[j]->ten)
	{
		SV *tam=p[i];
		p[i]=p[j];
		p[j]=tam;
	}
	cout<<"\nDanh sach SV sau khi sap xep la: ";
	for(int i=0; i<sosv; i++)
	{p[i]->indl();	}
}
