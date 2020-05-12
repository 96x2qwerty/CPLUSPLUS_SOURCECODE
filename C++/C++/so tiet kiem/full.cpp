#include<iostream>
#include<conio.h>
#include<string.h>
#include<time.h>
#include<math.h>
using namespace std;

class khongkihan
{
	protected:
	int cmnd,d,m,y;
	string makh,ten;
	float tiengui,laisuat;
	public:
		khongkihan()
		{
			makh = "0";
			ten = "0";
			cmnd = 0;
			tiengui = 0;
			laisuat = 0;
			d = 0;
			m = 0;
			y = 0;
		}
		
		float lai()
		{
			return(tiengui * laisuat);
		}
		
		int thanggui()
		{
			{
				int ngay,thang,nam ;
				int thanggui;
    			tm *today ;
    			time_t now;
    			time( &now );
    			today = localtime( &now );
    
    			ngay=today->tm_mday;
    			thang=today->tm_mon+1;
    			nam=today->tm_year+1900;
    			thanggui=abs( thang - m )+12*( nam - y);
				if (ngay < d)
					thanggui--;
				return thanggui;
			}
		}
		
		virtual void nhap()
		{
			cout<<"Nhap ma khach hang: ";
			getline(cin,makh);
			cin.ignore(1);
			cout<<"\nNhap ten khach hang: ";
			getline(cin,ten);
			cin.ignore(1);
			cout<<"\nNhap cmnd: ";
			cin>>cmnd;
			cout<<"\nNhap so tien gui (trieu dong): ";
			cin>>tiengui;
			cout<<"\nNhap lai suat (%): ";
			cin>>laisuat;
			cout<<"\nNhap ngay, thang, nam lap so: ";
			cin>>d>>m>>y;
		}
		
		virtual void xuat()
		{
			cout<<"\nMa khach hang: "<<makh
				<<"\nTen khach hang: "<<ten
				<<"\nCmnd: "<<cmnd
				<<"\nTien gui (trieu dong): "<<tiengui
				<<"\nLai suat (%): "<<laisuat
				<<"\nNgay lap so: Ngay "<<d<<" thang "<<m<<" nam "<<y
				<<"\nTien lai: "<<tienlai();
		}
		
		virtual float tienlai()
		{
			int i = thanggui();
			return (i*lai());
		}
};

class cokihan:public khongkihan
{
	int sothang;
	public:
		cokihan():khongkihan()
		{
			sothang=0;
		}
		
		void nhap()
		{
			khongkihan::nhap();
			cout<<"Nhap so thang gui: ";
			cin>>sothang;
		}
		
		void xuat()
		{
			khongkihan::xuat();
			cout<<"Ki han gui: "<<sothang<<" thang";
		}
		
		float tienlai()
		{
			if(khongkihan::thanggui()<sothang)
			return 0;
			else return( (khongkihan::lai()*sothang) + khongkihan::lai()*(khongkihan::thanggui()-sothang) );
		}
}

main()
{
	int n;
	float s=0;
	cout<<"Nhap so khach hang: ";
	cin>>n;
	khongkihan *p[n];
	for(int i=0;i<n;i++)
	{
		int k;
		cout<<"1.Khong ki han   2.Co ki han   Nut bat ki.Thoat";
		cin>>k;
		if(k==1)
		{
			p[i]=new khongkihan();
			p[i]->nhap();
			p[i]->xuat();
		}
		else if(k==2)
		{
			p[i]=new cokihan();
			p[i]->nhap();
			p[i]->xuat();
		}
		else return 0;
	}
	
}
