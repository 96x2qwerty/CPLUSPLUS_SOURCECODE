#include<stdio.h>
#include<conio.h>
#include<date.h>
#include<time.h>
#include<string>
#include<iostream>
using namespace std;
class khongkyhan{
	int CMND, sotien;
	string hoten;
	Date ngaylapso;
	float laisuat;
	int thang;
	public:
		khongkyhan(){
			CMND=0;
			hoten=" ";
			ngaylapso = Date(0,0,0);
			sotien=0;
			laisuat=0.0;
			thang=0;
		}
		int thanggui(){return (thang);}
		Date ngayhethong();
		void laicuaso();
		virtual void nhap();
		virtual void xuat();
		virtual float lai(){return (sotien*laisuat*thang);}
		
};

void khongkyhan::nhap()
{
	cout<<"Nhap so CMND: ";
	cin>>CMND;
	cout<<"\nNhap ho ten: ";
	cin.ignore(1);
	getline(cin,hoten);
	cout<<"\nNhap ngay lap so: ";
	cin>>ngaylapso;
	cout<<"\nNhap so tien gui: ";
	cin>>sotien;
	cout<<"\nNhap lai suat: ";
	cin>>laisuat;
	cout<<"\nNhap so thang gui: ";
	cin>>thang;
}

void khongkyhan::xuat()
{
	cout<<"\n\nSo CMND: "<<CMND
		<<"\nHo Ten: "<<hoten
		<<"\nNgay lap so: "<<ngaylapso
		<<"\nSo tien gui: "<<sotien
		<<"\nLai suat: "<<laisuat
		<<"\nSo thang gui: "<<thang
		<<"\nLai: "<<lai();
}

Date khongkyhan::ngayhethong()
{
	int ngay,thang,nam ;
    tm *today ;
    time_t now;
    time( &now );
    today = localtime( &now );
    ngay=today->tm_mday;
    thang=today->tm_mon+1;
    nam=today->tm_year+1900;
    cout<<"Hom nay la ngay "<<ngay<<" thang "<<thang<<" nam "<<nam;
    return (ngay, thang, nam);
}


void khongkyhan::laicuaso()
{
	Date a = ngayhethong();
	int sothangdagui;float n;
	sothangdagui=(a.getmonth()-ngaylapso.getmonth())+12*(a.getyear()-ngaylapso.getyear());
	if (a.getday()<ngaylapso.getday())
		sothangdagui-=1;
	n= sothangdagui/thang;
	cout<<"Lai cua so: "<<n*lai();
}

class cokyhan:public khongkyhan{
	int kyhan;
	public:
		cokyhan():khongkyhan(){kyhan=0;}
		void nhap();
		void xuat();
		float lai();
};

void cokyhan::nhap()
{
	khongkyhan::nhap();
	cout<<"\nNhap ky han: ";
	cin>>kyhan;
}

void cokyhan::xuat()
{
	khongkyhan::xuat();
	cout<<"\nKy han: "<<kyhan;
}

float cokyhan::lai()
{
	if (khongkyhan::thanggui()==kyhan) return (khongkyhan::lai());
	else return (0);
}

int main()
{
	khongkyhan *a[100];
	int m;
	cout<<"Nhap so luong: ";
	cin>>m;
	for (int i=0; i<m; i++)
	{
		int ch;
		cout<<"Chon hinh thuc gui? 1.Khong ky han     2.Co ky han  :  ";
		cin>>ch;
		if (ch==1) a[i]=new khongkyhan();
		else a[i]=new cokyhan();
		a[i]->nhap();
	}
	for (int i=0; i<m; i++)
	{
		a[i]->xuat();
	}
	getch();
}
