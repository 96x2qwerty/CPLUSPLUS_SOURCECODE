#include<iostream>
using namespace std;
class K{
	public:
	string nhanhieu, mauxe;
	int gn, gx;
	K(){
		nhanhieu=" ";
		mauxe="";
		gn=0;
		gx=0;
	}
	virtual void nhap(){
		cout<<"Nhap nhan hieu: ";
		cin.ignore();
		getline(cin, nhanhieu);
		cout<<"Nhap mau xe: ";
		getline(cin, mauxe);
		cout<<"Gia Nhap: ";
		cin>>gn;
		cout<<"Gia Xuat: ";
		cin>>gx;	}
	virtual void xuat(){
		cout<<"\nNhan hieu: "<<nhanhieu<<endl
			<<"Mau xe: "<<mauxe<<endl
			<<"Gia Nhap: "<<gn<<endl
			<<"Gia Xuat: "<<gx<<endl;
	}
	virtual float tinhlai()=0;
};
class BUS:public K{
	public:
		BUS():K(){
		}
		float tinhlai()
		{
			return (gx-gn)*0.1;
		}
};
class truck:public K{
	public:
		truck():K(){
		}
		float tinhlai()
		{
			return (gx-gn)*0.16;
		}
};
main()
{
	int sx;
	cout<<"Nhap so xe: ";
	cin>>sx;
	K *a[sx];
	for(int i=0; i<sx; i++)
	{
		int chon;
		cout<<"Nhap chon: ";
		cin>>chon;
		if(chon==1)
			a[i]=new BUS();
		if(chon==2)
			a[i]=new truck();
		a[i]->nhap();
	}
	cout<<"\nDanh sach xe: ";
	for(int i=0; i<sx; i++)
	{
		a[i]->xuat();
		cout<<"Lai: "<<a[i]->tinhlai();
	}
	
}

