#include<iostream>
#include<conio.h>
#include<string.h>
#include<date.h>

class email
{
	//protected:
	string a;
	public:
		email(string t)
		{
			a=t;
		}
		
		virtual void print()
		{
			cout<<a;
		}
};

class nhansu:public email
{
	public:
		nhansu(string a):email(a)
		{}
		
		void print()
		{
			cout<<"\nPhong ban nhan su: Tuyen nhan vien.";
		}
};

class hanhchinh:public email
{
	public:
		hanhchinh(string a):email(a)
		{}
		
		void print()
		{
			cout<<"\nPhong ban hanh chinh: Giai quyet cac thu tuc hanh chinh.";
		}
};

class khtc:public email
{
	public:
	khtc(string a):email(a)
	{}
	
	void print()
		{
			cout<<"\nPhong ban ke hoach tai chinh: Nop bao cao tai chinh.";
		}
};

class sanxuat:public email
{
	public:
	sanxuat(string a):email(a)
	{}
	
	void print()
		{
			cout<<"\nXuong san xuat: Nang cao nang suat."<<endl;
		}
};


main()
{
	int n;
	cout<<"Nhap so lan gui email: ";
	cin>>n;
	email *e[n];
	for(int i=0;i<n;i++)
	{
		cout<<"\nLan gui thu "<<i+1;
		e[i]=new nhansu(" ");
		e[i]->print();
		e[i]=new hanhchinh(" ");
		e[i]->print();
		e[i]=new khtc(" ");
		e[i]->print();
		e[i]=new sanxuat(" ");
		e[i]->print();
	}
	getch();
}
