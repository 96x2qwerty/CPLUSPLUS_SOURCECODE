#include<iostream>
using namespace std;
class mtrv{
	int n;
	int **a;
	public:
		mtrv(int n=0 ,int **a=NULL);
		
		~mtrv(){
			n=0;
			delete a;
		}
		friend istream &operator>>(istream &is, mtrv &p)
		{
			cout<<"Nhap cap ma tran vuong: ";
			is>>p.n;
			p.a=new int*[p.n];
			for(int i=0; i<p.n; i++)
			{
				p.a[i]= new int[p.n];
				for(int j=0; j<p.n; j++)
				{
					cout<<"Nhap a["<<i<<"]["<<j<<"]= ";
					is>>p.a[i][j];
				}
			}
			return is;
		}
		friend ostream &operator<<(ostream &os, mtrv &p)
		
		{
			os<<"ma tran vua nhap la: "<<endl;
			for(int i=0; i<p.n; i++)
			{
				for(int j=0; j<p.n; j++)
				{
				
				os<<p.a[i][j]<<" ";
			}
			os<<endl;
			}
			
			return os;
		}
		mtrv operator +(mtrv &r)
		{
			for(int i=0; i<r.n; i++)
			{
				for(int j=0; j<r.n; j++)
				{
					a[i][j]=a[i][j]+r.a[i][j];
				}
			}
			return mtrv(n, a);
		}
};
mtrv::mtrv(int n1, int **a1)
{
	n=n1;
	a=new int*[n];
	for(int i=0; i<n; i++)
	{
		a[i]=new int[n];
		for(int j=0; j<n; j++)
		{
			a[i][j]=a1[i][j];
		}
	}
}

main()
{
	mtrv a, a1;
	cin>>a>>a1;
	cout<<a<<a1;
	a=a+a1;
	cout<<a;
}

