//Bai 1 De 1
#include<iostream>
using namespace std;
class taphop{
	int n;
	int *a;
	public:
		taphop(int n = 0, int *a = NULL);
		friend istream &operator>> (istream &is, taphop &r)
		{
			cout<<"Nhap so phan tu: ";
			is>>r.n;
			r.a = new int[r.n];
			for(int i=0; i<r.n; i++)
			{
				cout<<"Nhap a["<<i<<"]= ";
				is >>r.a[i];
			}
			return is;
		}
		friend ostream &operator<<(ostream &os, taphop &r)
		{
			for(int i=0; i<r.n; i++)
			{
			os<<r.a[i]<<" ";
			
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
			{c.add(b.a[i]);
			}
			return c;
		}
};
taphop::taphop(int n1, int *a1){
	n = n1;
	a = new int[n];
	for(int i = 0; i<n; i++){
		a[i] = a1[i];
	}
}
main()
{
	taphop a;
	cin>>a;
	cout<<a<<endl;
		taphop b;
	cin>>b;
	a=a+b;
	cout<<a;
	}
