#include<iostream>
#include<conio.h>
using namespace std;
class phanso;
class dsps
{
      int n;
      phanso *a;
      public:
             dsps();
             dsps(int );
             ~dsps();
             dsps ( const dsps &);
             void nhap();
             void xuat();
             void sapxep();
             void thongke();
};
class phanso
{
      int tu,mau;
      public:
             phanso();
             phanso( int , int );
             float giatri();
             void nhap();
             void xuat();
             friend void dsps::sapxep();
             friend void dsps::thongke();
};
// cac phuong thuc cua class dsps
dsps::dsps()
{
            n=0;
            a=NULL;
}
dsps::dsps(int b)
{
               n=b;
               a=new phanso[n];
}
dsps::~dsps()
{
             n=0;
             delete[] a;
}
dsps::dsps ( const dsps &b)
{
           n=b.n;
           a=new phanso[n];
           for(int i=0;i<n;i++)
           a[i]=b.a[i];
}
void dsps::nhap()
{
     cout<<"Nhap so luong phan tu: ";
     cin>>n;
     a=new phanso[n];
     for(int i=0; i<n; i++)
     a[i].nhap();
}
void dsps::xuat()
{
     for(int i=0; i<n; i++)
     a[i].xuat();
}

void dsps::sapxep()
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
void dsps::thongke()
{
     cout<<"\nThong ke phan so co tu va mau chan: ";
     for( int i=0; i<n; i++)
     if( a[i].tu %2 ==0 && a[i].mau%2 ==0 )
     a[i].xuat();
}

// cac phuong thuc cua class phanso
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

main()
{
      dsps b;
      b.nhap();
      b.sapxep();
      b.xuat();
      b.thongke();
      
      getch();
      return 0;
}
      
