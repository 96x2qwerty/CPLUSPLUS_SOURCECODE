#include<iostream>
#include<iomanip>

using namespace std;

int Count_SPT(int k)
{
	int dem=0;
	int t=k;
	while (t!=0)
	{
		dem=dem+1;
		t=t/10;
	}
	return dem;
}

main()
{
	int dem;
	cout<<"Nhap dem";
	cin>>dem;
	cout<<"\n  旼컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�"
		<<"\n  쿞o SV trong DS: "<<dem<<setw(16)<<"�"
		<<"\n  읕컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�";
}

