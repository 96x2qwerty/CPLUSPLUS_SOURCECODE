#include <iostream>
#include <conio.h>
#include <iomanip>  
using namespace std;
main()
{
    int h,c,i,j,hangtam,cottam;
	float *b,*a;
	float m;
	
	//nhap ma tran
	cout<<"Nhap h,c: ";
	cin>>h>>c;
	b=new float[h*c];
	a=new float[h*c];
	cout<<"Nhap spt: ";
	for(i=0; i<h; i++)
	for(j=0; j<c; j++)
	cin>>a[i*c+j];
	
	//xuat ma tran
	cout<<"Ma tran vua nhap la: "<<endl;
	for(i=0;i<h;i++)
	{
           for(j=0;j<c;j++)
	       {
               cout<<a[i*c+j]<<" ";
           }
           cout<<"\n";
    }
    
   	//tao ptu ma tran b = 0
	for(i=0;i<h;i++)
	for(j=0;j<c;j++)
	b[i*c+j]=0;
	cout<<"\nMang b:\n";
    for(i=0;i<h;i++)
	{
           for(j=0;j<c;j++)
	       {
               cout<<b[i*c+j]<<" ";
           }
           cout<<"\n";
    }
	
	//max hang
	for(i=0;i<h;i++)
	{
        m=a[i*c];
        hangtam=i;
        cottam=0;
	    for(j=0;j<c;j++)
        {
             if(m<a[i*c+j])
             {
                  m=a[i*c+j];
                  hangtam=i;
                  cottam=j;
             }
        }
        b[hangtam*c+cottam]++;
    }
    //in ma tran b sau khi da~ danh' dau dc cac max hang
    cout<<"\nMax hang:\n";
    for(i=0;i<h;i++)
	{
           for(j=0;j<c;j++)
	       {
               cout<<b[i*c+j]<<" ";
           }
           cout<<"\n";
    }
	//min cot
	for(j=0; j<c; j++)
	{
		m=a[j];
		hangtam=0;
        cottam=j;
		for(i=0;i<h;i++)
 	    {
             if(m>a[i*c+j])
             {
                  m=a[i*c+j];
                  hangtam=i;
                  cottam=j;
             }
		}
		b[hangtam*c+cottam]++;
    }
    //in ma tran b sau khi da~ danh' dau dc cac max hang + min cot
    cout<<"\nMax hang + Min cot:\n";
    for(i=0;i<h;i++)
	{
           for(j=0;j<c;j++)
	       {
               cout<<b[i*c+j]<<" ";
           }
           cout<<"\n";
    }
    cout<<"\nYen ngua:\n";
    for(i=0;i<h;i++)
    {
          for(j=0;j<c;j++)
          {
               if(b[i*c+j]==2)
               cout<<a[i*c+j];
          }
    }
    getch();
    delete[] b;
    delete[] a;
}
