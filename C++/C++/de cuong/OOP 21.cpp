#include<iostream>
#include<conio.h>
using namespace std;
class phanso
{
      int tu,mau;
      public:
             phanso();
             phanso( int , int );
             float giatri();
             void nhap();
             void xuat();
             friend void sapxep( phanso [], int );
};
phanso::phanso()
{
                tu = 1;
                mau = 2;
}
phanso::phanso ( int t, int m)
{
               tu =t;
               mau = m;
}
float phanso::giatri()
{
      return (float)tu/mau;
}
void phanso::nhap()
{
     cout<<"Nhap tu: ";
     cin>>tu;
     cout<<"Nhap mau: ";
     cin>>mau;
}
void phanso::xuat()
{
     cout<<endl<<tu<<"/"<<mau;
}
void sapxep( phanso a[], int n)
{
     phanso tam;
     for(int i=0; i<n-1; i++)
     for(int j=i+1; j<n; j++)
     {
             if( a[i].giatri() < a[j].giatri() )
             {
                 tam =a[i];
                 a[i]=a[j];
                 a[j]=tam;
             }
     }
}
main()
{
      phanso *a;
      int n;
      
      cout<<"Nhap bao nhieu phan so ?: ";
      cin>>n;
      a=new phanso[n];
      
      for(int i=0;i<n; i++)
      a[i].nhap();
      
      sapxep(a,n);
      
      for(int i=0;i<n; i++)
      a[i].xuat();
      
      
      getch();
      return 0;
}
      
