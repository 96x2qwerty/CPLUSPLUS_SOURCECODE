#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<string>
#include<iostream>
using namespace std;
class khongkyhan{
	int CMND, sotien;
	string hoten;
	int d, y, m;
	float laisuat;
	public:
		khongkyhan(){
			CMND=0;
			hoten=" ";
			d = m = y = 0;
			sotien=0;
			laisuat=0.0;
		}
		int sothanggui();
		float lai(){return (laisuat*sotien);}
		virtual float laicuaso();
		virtual void nhap();
		virtual void xuat();
};

void khongkyhan::nhap()
{
	cout<<"Nhap so CMND: ";
	cin>>CMND;
	cout<<"\nNhap ho ten: ";
	cin.ignore(1);
	getline(cin,hoten);
	cout<<"\nNhap ngay lap so: ";
	cin>>d>>m>>y;
	cout<<"\nNhap so tien gui: ";
	cin>>sotien;
	cout<<"\nNhap lai suat: ";
	cin>>laisuat;
}

void khongkyhan::xuat()
{
	cout<<"\n\nSo CMND: "<<CMND
		<<"\nHo Ten: "<<hoten
		<<"\nNgay lap so: "<<d<<"-"<<m<<"-"<<y
		<<"\nSo tien gui: "<<sotien
		<<"\nLai suat: "<<laisuat
		<<"\nLai cua so: "<<laicuaso();
}

int khongkyhan::sothanggui()
{
	int ngay,thang,nam ;
	int sothanggui;
    tm *today ;
    time_t now;
    time( &now );
    today = localtime( &now );
    
    ngay=today->tm_mday;
    thang=today->tm_mon+1;
    cout<<thang;
    nam=today->tm_year+1900;
    
    sothanggui=( thang - m )+12*( nam - y);
    
	if (ngay < d)
		sothanggui--;
		
	return (sothanggui);
}

float khongkyhan::laicuaso()
{
	int a = sothanggui();
	return (a*lai());
}

class cokyhan:public khongkyhan{
	int kyhan;
	public:
		cokyhan():khongkyhan(){kyhan=0;}
		void nhap();
		void xuat();
		float laicuaso();
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

float cokyhan::laicuaso()
{
	if (khongkyhan::sothanggui()<kyhan)
		return (0);
	else 
		return (khongkyhan::sothanggui()*khongkyhan::lai());
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


}
