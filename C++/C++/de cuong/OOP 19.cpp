#include<iostream>
#include<conio.h>
using namespace std;
class mang_so_thuc
{
      float *p;
      int n;
      public:
             mang_so_thuc()
             {
                    n=100;
                    p=new float[100];
                    for( int i=0; i<100; i++)
                    p[i]= 2.5;
             }
             ~mang_so_thuc()
             {
                 delete p;
                 n=0;
             }
             void nhap();
             void xuat();
             void sapxep();
             void thongke(float);             
};
void mang_so_thuc::nhap()
{
     cout<<"Nhap so phan tu: ";
     cin>>n;
     p=new float[n];
     cout<<"Nhap gia tri cua cac phan tu: ";
     for(int i=0; i<n; i++)
     cin>>p[i];
}
void mang_so_thuc::xuat()
{
     cout<<"\nMang :\n";
     for(int i=0; i<n; i++)
     cout<<p[i]<<endl;
}
void mang_so_thuc::sapxep()
{
     float tam;
     for(int i=0; i<n-1; i++)
     for(int j=i+1; j<n; j++)
     if( p[i] < p[j])
     {
         tam=p[i];
         p[i]=p[j];
         p[j] = tam;
     }
}
void mang_so_thuc::thongke(float x)
{
     cout<<"\nThong ke cac phan tu nho hon "<<x<<endl;
     for( int i=0; i<n; i++)
     if( p[i] <x )
     cout<<p[i]<<endl;
}
main()
{
      mang_so_thuc a;
      a.nhap();
      a.sapxep();
      a.xuat();
      a.thongke(2.4);
      getch();
      return 0;
}
