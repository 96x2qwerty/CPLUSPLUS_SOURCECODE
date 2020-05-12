#include<iostream>
#include<conio.h>
using namespace std;

class dayso
{
      int n;
      float *a;
      public:
             dayso()//khoi tao mang co 100 phan tu, moi phan tu deu = 1.5
             {
                    n=100;
                    a=new float[n];
                    for(int i=0;i<n;i++)
                    a[i]=1.5;
             }
             
             ~dayso()//huy day so da nhap
             {
                     if(n!=0)
                     delete[] a;
             }
             friend istream &operator >>(istream &is,dayso &ds);
             friend ostream &operator <<(ostream &os,dayso &ds);
             void sapxep();
             void thongke(float x);
};

istream &operator >>(istream &is,dayso &ds)
{
     cout<<"Nhap so phan tu: ";
     cin>>ds.n;
     for(int i=0;i<ds.n;i++)
     {
             cout<<"Nhap phan tu thu "<<i+1<<": ";
             is>>ds.a[i];
     } 
}

ostream &operator <<(ostream &os,dayso &ds)
{
        cout<<"\nDay so la:\n";
        for(int i=0;i<ds.n;i++)
        os<<ds.a[i]<<" ";
}

void dayso::sapxep()// sap xep giam dan
{
     for(int i=0;i<n-1;i++)
     {for(int j=i+1;j<n;j++)
              if(a[i]<a[j])
              {
               float tg = a[i];
                  a[i] = a[j];
                  a[j] = tg;
                  }
     }
     cout<<"\nDay so sau khi sap xep la:\n";
     for(int i=0;i<n;i++)
     cout<<a[i]<<" ";
}

void dayso::thongke(float x)//thong ke nhung so lon hon x
{
     cout<<"\nNhap x: ";
     cin>>x;
     cout<<"Nhung so lon hon "<<x<<" la:";
     for(int i=0;i<n;i++)
     if(a[i]>x)
     cout<<a[i]<<" ";
}

main()
{
      dayso a;
      float x;
      cin>>a;
      cout<<a;
      a.sapxep();
      a.thongke(x);
      getch();
}
