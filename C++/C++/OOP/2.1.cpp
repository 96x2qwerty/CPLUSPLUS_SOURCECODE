#include<iostream>
using namespace std;
class MT
{
	int n;
	int **a;
	public:
		MT(int n=0, int **a=NULL);
		~MT(){
		}
		friend ostream &operator<<(ostream &os, MT &r);
		friend istream &operator>>(istream &is, MT &r);
		MT operator+(MT &r);
		MT operator*(MT &r);
};
MT::MT(int n1, int **a1)
{
	n=n1;
	a=new int *[n];
	for(int i=0; i<n; i++)
	{
		a[i]=new int[n];
		for(int j=0; j<n; j++)
		{
			a[i][j]=a1[i][j];
		}
	}
}
istream &operator>>(istream &is, MT &r)
{
	cout<<"Nhap n: ";
	is>>r.n;
	r.a=new int*[r.n];
	for(int i=0; i<r.n; i++)
	{
		r.a[i]=new int[r.n];
		for(int j=0; j<r.n; j++)
		{
			cout<<"Nhap: ";
			is>>r.a[i][j];
		}
	}
	return is;
}
ostream &operator<<(ostream &os, MT &r)
{
	for(int i=0; i<r.n; i++)
	{
		for(int j=0; j<r.n; j++)
		{
			os<<r.a[i][j]<<" ";
		}
		
		os<<endl;
	}
	return os;
}
MT MT::operator+(MT &r)
{
	for(int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			a[i][j]=a[i][j]+r.a[i][j];
		}
	}
	return MT(n, a);
}
MT MT::operator*(MT &r)
{
	for(int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			float temp=0;
			for(int k=0; k<n;k++)
			{
				temp += a[i][j]*r.a[k][j];
			}
			a[i][j]=temp;
		}
	}
	return MT(n, a);
}
main()
{
	MT a, b;
	cin>>a>>b;
	cout<<a<<b;
	a=a+b;
	cout<<a;
}

