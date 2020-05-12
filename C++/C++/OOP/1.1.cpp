#include<iostream>
using namespace std;
class taphop{
	int n;
	int *a;
	public:
		taphop(int n=0, int *a=NULL);
		friend istream &operator>>(istream &is, taphop &p){
			cout<<"Nhap so phan tu: ";
			is>>p.n;
			p.a=new int[p.n];
			for(int i=0; i<p.n; i++)
			{
				cout<<"Nhap a["<<i<<"]= ";
				is>>p.a[i];
			}
			return is;
		}
		friend ostream &operator<<(ostream &os, taphop &p)
		{
			for(int i=0; i<p.n; i++)
			{
				os<<p.a[i]<<" ";
			}
			return os;
		}
		void add(int gt)
		{
			n=n+1;
			a[n-1]=gt;
		}
		void del(int vt)
		{
			int i;
			for(i=vt; i<n; i++)
			{
				a[i]=a[i+1];
			}
			n=n-1;
		}
		int check(int gt)
		{
			for(int i=0; i<n; i++)
			{
				if(a[i]==gt)
					return true;
					return false;
			}
		}
		friend taphop operator+(taphop a, taphop b)
		{
			taphop c(a.n, a.a);
			for(int i=0; i<b.n; i++)
			{
				c.add(b.a[i]);
			}
			return c;
		}
};
taphop::taphop(int n1, int *a1){
	n=n1;
	a=new int[n];
	for(int i=0; i<n; i++)
	{
		a[i]=a1[i];
	}
}
main()
{
	taphop a;
	cin>>a;
	cout<<a<<endl;
	a.add(1);
	cout<<a<<endl;
	a.del(2);
	cout<<a<<endl;
	a.check(3);
	taphop b;
	cin>>b;
	a=a+b;
	cout<<endl<<a;
}

