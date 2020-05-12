#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
class NV
{
      string ten;
      float hsl,pc,tu;
      public:
             NV(string t=" ",float hsl1 = 0,float pc1 = 0,float tu1 = 0)
             {
                 ten = t;
                 hsl = hsl1;
                 pc = pc1;
                 tu = tu1;
             }
             
             virtual void nhap()
             {
                  cin.ignore(1);
                  cout<<"Nhap ten: ";
                  getline(cin,ten);
                  cout<<"Nhap he so luong: ";
                  cin>>hsl;
                  cout<<"Nhap phu cap: ";
                  cin>>pc;
                  cout<<"Nhap tam ung: ";
                  cin>>tu;
             }
             
             float luong()
             {
                   return (hsl*1150*pc -tu);
             }
             
             virtual void xuat()
             {
                  cout<<"Ten NV: "<<ten
                      <<"\nHe so luong: "<<hsl
                      <<"\nPhu cap: "<<pc
                      <<"\nTam ung: "<<tu
                      <<"\nLuong: "<<luong()<<"\n";                  
             }
};

class CB:public NV
{
      string cv;
      float pccv;
      public:
             CB(string t=" ",float hsl1 = 0,float pc1 = 0,float tu1 = 0,string cv1=" ",float pccv1=0):NV(t,hsl1,pc1,tu1)
             {
                       cv = cv1;
                       pccv = pccv1;
             }
             
             void nhap()
             {
                  NV::nhap();
                  cin.ignore(1);
                  cout<<"Chuc vu: ";          
                  getline(cin,cv);
                  cout<<"Phu cap chuc vu: ";
                  cin>>pccv;
             }
             
             float luong()
             {
                   NV::luong()+pccv;
             }
             
             void xuat()
             {
                  NV::xuat();
                  cout<<"Chuc vu: "<<cv
                      <<"\nPhu cap chuc vu: "<<pccv<<"\n";
             }
};

main()
{
      int n,i,k;
      cout<<"Nhap n: ";
      cin>>n;
      NV *p[n];
      for(i=0;i<n;i++)
      {
                      cout<<"Nhap cho 1-can bo, 2-nhanvien: ";
                      cin>>k;
                      if(k==1)
                             p[i]=new CB();
                      else
                             p[i]=new NV();
                      p[i]->nhap();
      }
      
      cout<<"\nDanh sach vua nhap:\n ";
      for(i=0;i<n;i++)
      p[i]->xuat();
      getch();
}
