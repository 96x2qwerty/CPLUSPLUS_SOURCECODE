#include <iostream>
#include <conio.h>
#include <iomanip>  
using namespace std;
class matran
{
	private:
		int h,c;
		float *a;
	public:
		matran()
		{
			h=c=5;
			a=new float[h*c];
			for(int i=0;i<h;i++)
			{
				for(int j=0;j<c;j++)
				{
					a[i*h+j]=1.1;
				}
			}
		};
		~matran();
		void nhap();
		void xuat();
		void maxcot();
		void yenngua();
};

void matran:: nhap()
{
	cout<<"Nhap so hang+cot: ";
	cin>>h>>c;
	a=new float[h*c];
	cout<<"Nhap cac phan tu ma tran:"<<endl;
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<c;j++)
		{
			cin>>a[i*c+j];
		}
	}
}

matran:: ~matran()
{
	if(h!=0&&c!=0)
	delete[] a;
}

void matran:: xuat()
{
	cout<<"\nMa tran vua nhap la:\n";
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<c;j++)
		{
		cout << setiosflags(ios::showpoint) << setprecision(3) ;
		cout << setw(6) << a[i*c+j] << " ";
//		cout<<a[i*c+j]<<" ";
        }
		cout<<"\n";
	}
}

void matran:: maxcot()
{
	float max;
	
		for(int j=0;j<c;j++)
		{
		max=a[j];
		for(int i=0;i<h;i++)
	    	{
			if(max<a[i*c+j])
			max=a[i*c+j];
			}
        cout<<"Max cot "<<j+1<<" = "<<max<<endl;
		}
}

void matran:: yenngua()
{
	float *b;
	float m,d=0;
	int htam,ctam,i,j;
	b=new float[h*c];
	//tao ptu ma tran b = 0
	for( i=0;i<h;i++)
	{
	for( j=0;j<c;j++)
        {
			b[i*c+j]=0;
	    }
	}
	
	
	//max hang
	for( i=0;i<h;i++)
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
			
    }
    
    for(i=0;i<h;i++)
    {for(j=0;j<c;j++)
    	{
         if(b[i*c+j]==2)
         cout<<"\nDiem yen ngua: "<<a[i*c+j];
         }
	}
}
main()
{
	matran x;
	x.nhap();
	x.xuat();
	x.maxcot();
	x.yenngua();
	getch();
}
