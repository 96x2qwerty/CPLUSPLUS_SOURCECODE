#include<iostream>
using namespace std;
template <class T> void Dcho(T &a, T &b)
{
	T tg=a;
	a=b;
	b=tg;
}
template <class T> void Sxep(T x[], int n, int m)
	{
		for(int i=n; i<m; i++)
			for(int j=i+1; j<=m; j++)
			if(x[i]>x[j])
			{
				T tg=x[i];
				x[i]=x[j];
				x[j]=tg;
			}
	}
main()
{
	int a[8]={1,2,3, 7, 8, 3, 9, 12};
	//int a[]={1,2,6,4,7,8,3,5,12,19};
	Sxep(a, 0, 7);
	for (int i=0; i<=7; i++)
	cout<<a[i]<<" ";
}
