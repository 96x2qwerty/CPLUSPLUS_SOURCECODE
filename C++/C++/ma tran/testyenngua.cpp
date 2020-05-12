#include <iostream>
#include <conio.h>

using namespace std;
main()
{
      int h,c,i,j,htam,ctam;
	float *b,*a;
	float m;
		


	//nhap ma tran
	cout<<"Nhap h,c: ";
	cin>>h>>c;
	b=new float[h*c];
	a=new float[h*c];
	
	cout<<"Nhap spt: \n";
	for(i=0;i<h;i++)
	for(j=0;j<c;j++)
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
	{
	for(j=0;j<c;j++)
        {
			b[i*c+j]=0;
	    }
	}
	
	
	//max hang
	for(i=0;i<h;i++)
	{m=a[i*c];
	htam=i;
	ctam=0;
	for(j=0;j<c;j++)
	{
		if(m<a[i*c+j])
		{m=a[i*c+j];
		htam=i;
		ctam=j;}
	}
    b[htam*c+ctam]++;
   cout<<m<<" ";
    }
	
	//min cot
	for(j=0;j<c;j++)
	{
		m=a[j];
		htam=0;
		ctam=j;
		for(i=0;i<h;i++)
	    	{
			if(m>a[i*c+j])
			{m=a[i*c+j];
			htam=i;
			ctam=j;
			}}
			b[htam*c+ctam]++;
			cout<<m<<" ";
			
    }
    
    for(i=0;i<h;i++)
    {for(j=0;j<c;j++)
    {
         if(b[i*c+j]==2)
         cout<<"\nDiem yen ngua: "<<a[i*c+j];
         }
 
}

   getch();
}
