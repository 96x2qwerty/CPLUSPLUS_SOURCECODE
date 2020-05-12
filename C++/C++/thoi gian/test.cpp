#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;

class Time
{
      private:
              int h,m,s;
      public:
             bool ktra();
             void nhap();
             void xuat();
             Time()
             {
                  h=m=s=0;
             }
             Time(int ,int ,int =12);
};

bool Time:: ktra()
{
     if(h>=0&&h<=24&&m>=0&&m<=60&&s>=0&&s<=60)
     return true;
     else return false;
}

void Time:: nhap()
{
     do{
     cout<<"Nhap gio, phut, giay: ";
     cin>>h>>m>>s;
     }while(!ktra());
}

void Time:: xuat()
{
     if(h<13)
     cout<<h<<" gio "
         <<m<<" phut "
         <<s<<" giay am";
     else cout<<h-12<<" gio "
         <<m<<" phut "
         <<s<<" giay pm ";
}

main()
{
      Time a;
      a.nhap();
      a.xuat();
      getch();
}
