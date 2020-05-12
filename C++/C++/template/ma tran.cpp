#include<iostream>
#include<conio.h>
#include<string.h>
#include<math.h>
using namespace std;

template <class T> class matran
{
	int d,c;
	T *p;
	public:
		matran()
		{
			d=c=0;
			p=NULL;
		}
		
		void nhap()
		{
			cout<<"Nhap so dong,cot ma tran: ";
			cin>>d>>c;
			p=new T[d*c];
			cout<<"Nhap phan tu ma tran:\n";
			for(int i=0;i<d;i++)
			for(int j=0;j<c;j++)
			{
				cin>>p[i*c+j];
			}
		}
		
		void xuat()
		{
			cout<<"Ma tran vua nhap la:\n";
			for(int i=0;i<d;i++)
			{
				for(int j=0;j<c;j++)
					{
						cout<<p[i*c+j]<<" ";
					}
				cout<<"\n";
			}
		}
};

main()
{
	matran<int> a;
	a.nhap();
	a.xuat();
	getch();
}
