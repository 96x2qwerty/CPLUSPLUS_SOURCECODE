#include<iostream>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
using namespace std;]]]]]]]]]

void inran(int n,int x[])
{
	int i;
	
	for(i=0;i<n;i++)
	{
		x[i]=rand()%80-40;
	}
}

void xuatran(int n,int x[])
{
	int i;
	cout<<"Day so ngau nhien la:"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<x[i]<<" ";
	}
}

main()
{
	int n;
	int *x=new int(n);
	srand(time(NULL));
	cout<<"Nhap n: ";
	cin>>n;
	inran(n,x);
	xuatran(n,x);
	getch();
}
