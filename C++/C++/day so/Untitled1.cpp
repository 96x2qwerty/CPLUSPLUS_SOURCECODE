#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
class dathuc
{
      int n;
      float *a;
      public:
             dathuc()
             {
                     n=0;
                     a=NULL;
             }
             
             dathuc(int x)
             {
                        n=x;
                        a=new float[n];
                        for(int i=0;i<=n;i++)
                        *(a+i)=0;
             }
             
             ~dathuc()
             {
                      cout<<"\nKet thuc.";
                      n=0;
                      delete[] a;

             }
             
             dathuc(const dathuc &d)
             {
                          n=d.n;
                          a=new float[n+1];
                          for(int i=0;i<=n;i++)
                          *(a+i)=*(d.a+i);
             }
             
             void nhap();
             void xuat();
             float giatri(float x);
             dathuc cong(dathuc y);
             
             bool sosanh(dathuc y);
            
};

void dathuc:: nhap()
{
     cout<<"Nhap n:\n";
     cin>>n;
     a=new float[n+1];
     cout<<"Nhap spt:\n";
     for(int i=0;i<=n; i++)
     cin>>a[i];
}

void dathuc:: xuat()
{
     for(int i=0;i<=n; i++)
     {
             if(a[i]!= 0)
             {
             	cout<< a[i] <<"*x^"<<i;
             }
             if(i<n)
             cout<<" + "; 
     }

}

dathuc dathuc::cong(dathuc y)
{
	dathuc z;
	z.n=(n>y.n)?n:y.n;
	z.a=new float[z.n+1];
	for(int i=0;i<=n;i++)
	{
		z.a[i]=0;
		if((i<=n)&&(i<=y.n))
		z.a[i]=a[i]+y.a[i];
		else if(i<=n)
		z.a[i]+=a[i];
		else if(i<=y.n)
		z.a[i]+=y.a[i];
	}
	return z;
}

float dathuc:: giatri(float x)
{
      float t=0;
      for(int i=0;i<=n; i++)
      t+=a[i]*(pow(x,i));
      return t;
}

bool dathuc::sosanh(dathuc y)
{
	int i;
	if(n!=y.n)
	return false;
	else for(i=0;i<=n;i++)
	{
		if(a[i]!=y.a[i])
		return false;
	}
	return true;
}

int main()
{
      dathuc a,b,c;
      float x,k;
      a.nhap();
      a.xuat();
      b.nhap();
      b.xuat();
      c=a.cong(b);
      c.xuat();
      getch();
}
