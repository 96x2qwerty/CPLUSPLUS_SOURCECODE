#include<iostream>
using namespace std;
class KH
{
	protected:
	string cmnd, hten;
	int tg, thang;
	double ls;
	public:
		KH(string cmnd="", string hten="", int tg=0, int thang=0, double ls=0);
		~KH(){
		}
		virtual void nhapdl();
		virtual void xuatdl();
		double lsuat(){
			return tg*ls*thang;
		}
};
KH::KH(string cmnd1, string hten1, int tg1, int m, double ls1)
{
	cmnd=cmnd1;
	hten=hten1;
	tg=tg1;
	thang=m;
	ls=ls1;
}
void KH::nhapdl()
		{
			cout<<"Nhap cmnd: ";
			cin.ignore();
			getline(cin, cmnd);
			cout<<"\nNhap ten Khach hang: ";
			getline(cin, hten);
			cout<<"\nNhap tien gui: ";
			cin>>tg;
			cout<<"\nNhap thang: ";
			cin>>thang;
			cout<<"\nNhap lai suat: ";
			cin>>ls;
		}
void KH::xuatdl()
		{
			cout<<"\nThong tin khach hang: "<<endl
				<<"Ho ten khach hang: "<<hten<<endl
				<<"So CMND: "<<cmnd<<endl
				<<"Thang gui: "<<thang<<endl
				<<"Tien gui: "<<tg<<endl
				<<"Lai suat gui: "<<ls<<endl;
		}
		
		
class Kyhan:public KH
{
	int kyhan;
	public:
		Kyhan(string cmnd="", string hten="", int tg=0, int thang=0, double ls=0, int kyhan=0);
		~Kyhan(){}
		void nhapdl()
		{
			KH::nhapdl();
			cout<<"Nhap ky han: ";
			cin>>kyhan;
		}
		
		void xuatdl()
		{
			KH::xuatdl();
			cout<<"Ky han gui: "<<kyhan<<endl;
		}
		double lsuat()
		{
			if(thang>=kyhan)
				return tg*(ls+0.02)*thang;
			return tg*ls*thang;
		}
};
Kyhan::Kyhan(string cmnd1, string hten1, int tg1, int m, double ls1, int kyhan1):KH(cmnd1, hten1, tg1, m, ls1)
{
	kyhan=kyhan1;
}


class KKyhan:public KH
{
	public:
	KKyhan(string cmnd="", string hten="", int tg=0, int thang=0, double ls=0);
	~KKyhan(){
	}
	void nhapdl()
	{
		KH::nhapdl();
	}
	void xuatdl()
	{
		KH::xuatdl();
	}
};
KKyhan::KKyhan(string cmnd1, string hten1, int tg1, int m, double ls1):KH(cmnd1, hten1, tg1, m, ls1)
{
}
main()
{
	int n;
	cout<<"Nhap n: ";
	cin>>n;
	KH *a[n];
	for(int i=0; i<n; i++)
	{
		int chon;
		cout<<"Nhap chon: ";
		cin>>chon;
		if(chon==1)
		{
			a[i]=new Kyhan();
			
		}
		if(chon==2)
		{
			a[i]=new KKyhan();
		}
		a[i]->nhapdl();
	}
	for(int i=0; i<n; i++)
	{
		a[i]->xuatdl();
		cout<<"Tien lai: "<<a[i]->lsuat();
		cout<<endl;
	}
}

