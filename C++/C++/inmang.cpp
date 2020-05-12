#include<iostream>
#include<conio.h>
#include<time.h>
#include<stdlib.h>

using namespace std;

main()
{
	int n,i;
	int *x=new int(n);
	cout<<"Nhap n: ";
	cin>>n;
	srand(time(0));
	
	for(i=0;i<n;i++)
	{
		x[i]=rand()%20-10;
	}
	
	cout<<"Day so ngau nhien la:"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<x[i]<<" ";
	}
	getch();
}
