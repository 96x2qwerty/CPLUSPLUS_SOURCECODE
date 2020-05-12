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
	cout<<"\n  ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿"
		<<"\n  ³So SV trong DS: "<<dem<<setw(16)<<"³"
		<<"\n  ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ";
}

