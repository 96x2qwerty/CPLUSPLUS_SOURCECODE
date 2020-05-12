#include<iostream>
#include<conio.h>
using namespace std;
class Printer
{
      string ten;
      int soluong;
      protected:
      float gianhap;
      public:
             Printer()
             {
                      ten="";
                      soluong = 0;
                      gianhap =0;
             }
             virtual void nhap();
             virtual void xuat();
             virtual float tinhthue()const =0;
};
void Printer::nhap()
{
     cout<<"Nhap ten: ";
     cin.ignore(1);
     getline(cin, ten);
     cout<<"Nhap so luong: ";
     cin>>soluong;
     cout<<"Nhap gia: ";
     cin>>gianhap;
}
void Printer::xuat()
{
     cout<<"\n\nTen : "<<ten<<"\nSo luong: "<<soluong
     <<"\nGia nhap: "<<gianhap;
}
class laserPrinter :public Printer
{
      int dpi;
      public:
             laserPrinter() : Printer() { dpi =0; }
             void nhap();
             void xuat();
             float tinhthue() const { return 0.1*gianhap;}
};
void laserPrinter::nhap()
{
     Printer::nhap();
     cout<<"Nhap chi so dpi: ";
     cin>>dpi;
}
void laserPrinter::xuat()
{
     Printer::xuat();
     cout<<"\nChi so dpi: "<<dpi<<"\nThue: "<<tinhthue();;
}

class colorPrinter : public Printer
{
      string mau;
      public:
             colorPrinter() : Printer() { mau = "";}
             void nhap();
             void xuat();
             float  tinhthue() const { return 0.15* gianhap; }
};
void colorPrinter::nhap()
{
     Printer::nhap();
     cout<<"Nhap mau: ";
     cin>>mau;
}
void colorPrinter::xuat()
{
     Printer::xuat();
     cout<<"\nMau: "<<mau<<"\nThue: "<<tinhthue();
}

main()
{
      Printer **a;
      int n,choice;
      cout<<"Nhap bao nhieu may in? : ";
      cin>>n;
      a=new Printer*[n];
      for(int i=0; i<n; i++)
      {
              cout<<"\nNhap cho may in thu "<<i<<"\n 1 = laser / 2 = color : ";
              cin>>choice;
              if( choice == 1 ) a[i]= new laserPrinter;
              else a[i]=new colorPrinter;
              a[i]->nhap();
      }
      
      for(int i=0; i<n; i++)
      a[i]->xuat();
      getch();
      return 0;
}
