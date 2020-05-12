#include<iostream>
#include<conio.h>
using namespace std;
class printer
{
      protected:
      string ten;
      int soluong;
      float gianhap;
      public:
             printer()
             {ten=" ";soluong = 0;gianhap =0;}
             printer(string t1,int sl,float gn)
             {
                  ten = t1;
                  soluong = sl;
                  gianhap = gn;
             }
             
             virtual void nhap()
             {
                  cout<<"Nhap ten: ";
                  cin.ignore(1);
                  getline(cin,ten);
                  cout<<"Nhap so luong: ";
                  cin>>soluong;
                  cout<<"Nhap gia: ";
                  cin>>gianhap;
             }
             
             virtual float thue()
             {return (soluong*gianhap);}
             
             virtual void xuat()
             {
                  cout<<"\nTen may in: "<<ten
                      <<"\nSo luong nhap: "<<soluong
                      <<"\nGia nhap: "<<gianhap
                      <<"\nTinh thue: "<<thue();
             }
};

class laserprinter:public printer
{
      int dpi;
      public:
             laserprinter():printer()
             {dpi=0;}
             laserprinter(string t1,int sl,float gn,int dpi1):printer(t1,sl,gn)
             {dpi = dpi1;}
             
             void nhap()
             {
                  printer::nhap();
                  cout<<"Nhap so dpi: ";
                  cin>>dpi;
             }
             
             float thue()
             {return (soluong*gianhap+soluong*gianhap*0,1);}
             
             void xuat()
             {
                  printer::xuat();
                  cout<<"\nChi so dpi: "<<dpi<<endl;
             }
};

class colorprinter:public printer
{
      string mau;
      public:
             colorprinter():printer()
             {mau = " ";}
             colorprinter(string t1,int sl,float gn,string m):printer(t1,sl,gn)
             {mau = m;}
             
             void nhap()
             {
                  printer::nhap();
                  cin.ignore(1);
                  cout<<"Nhap mau: ";
                  getline(cin,mau);
             }
             
             float thue()
             {return (soluong*gianhap+soluong*gianhap*0,15);}
             
             void xuat()
             {
                  printer::xuat();
                  cout<<"\nMau in: "<<mau<<endl;
             }
};


main()
{
      printer *a[100];
      int n;
      cout<<"Nhap so luong: ";
      cin>>n;
      
      for(int i=0;i<n;i++)
      {
              int ck;
              cout<<"1.May in thuong     2.May in laser     3.May in mau\n";
              cin>>ck;
              if(ck==1)
              {
                       a[i]=new printer();
                       a[i]->nhap();
              }
              else if(ck==2)
              {
                   a[i]=new laserprinter();
                   a[i]->nhap();
              }
              else if(ck==3)
              {
                   a[i]=new colorprinter();
                   a[i]->nhap();
              }
      }
      
      for(int i=0;i<n;i++)
      a[i]->xuat();
      
      getch();
}
