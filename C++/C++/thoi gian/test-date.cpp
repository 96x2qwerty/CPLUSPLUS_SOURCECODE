#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
long a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
class Date
{
      int d,m,y;
      public:
             friend Date getdate(long );
             long getday();
             Date(int dd=1,int mm=1,int yy=1) 
             { d=dd; m=mm; y=yy; }
             friend istream& operator >>(istream &, Date &);
             friend ostream& operator <<(ostream &, Date &);
             void operator ++();
             void operator ++(int);
             Date operator + (Date );
             Date operator + (int );
             friend Date operator +( int , Date );
             friend long operator - (Date ,Date);
             //Date operator - (Date );
             
};
bool namnhuan(int t)
{
     return ((t%4==0 && t %100 !=0) || (t%400 ==0));
}
// toan tu << >> 
istream& operator >>(istream &is, Date &dd)
{
         cin>>dd.d>>dd.m>>dd.y;
}
ostream& operator <<(ostream &os, Date &dd)
{
         cout<<dd.d<<"/"<<dd.m<<"/"<<dd.y<<endl;
}
// ham chuyen date -> day
long Date::getday()
{
    long day=d;
    for(int i=1; i<y; i++)
    day+=365 + namnhuan(i);
    for(int i=1; i<m; i++)
    day+=a[i] + ((i==2)?namnhuan(y):0);
    return day;
}

// ham chuyen day->date
Date getdate(long day)
{
     int dd=0,mm=1,yy=1;
     while( day>=365&&!namnhuan(yy) || day>=365&&namnhuan(yy))
     {
            day-=365 + namnhuan(yy);
            yy++;
     }
     while( day>a[mm] + ((mm==2)?namnhuan(yy):0) )
     {
            day-=a[mm] + ((mm==2)?namnhuan(yy):0);
            mm++;
     }
     dd=day;
     return Date(dd,mm,yy);
}
// toan tu ++
void Date::operator ++() // ++Date
{
     *this=getdate(this->getday()+1);
}

void Date::operator ++(int n) // Date++
{
     *this=getdate(this->getday()+1);
}
// toan tu + 
Date Date::operator + ( Date b) // Date = Date + Date
{
     return getdate(this->getday() + b.getday());
}

Date Date:: operator + (int n) // Date = Date + day
{
     return getdate(this->getday()+n);
}

Date operator +(  int n, Date a ) // Date = day + Date
{
     return getdate(a.getday()+n);
}
// toan tu - 
long operator - ( Date a, Date b) // day = Date - Date
{
     return abs( a.getday() - b.getday() );
}
/*Date Date::operator - (Date b ) // Date = Date - Date
{
     return getdate(abs( this->getday() - b.getday()));
}*/

main()
{
      Date vidu;
      cout<<"Nhap ngay/thang/nam : ";
      cin>>vidu;
      cout<<"\nNgay/thang/nam vua nhap: ";
      cout<<vidu;
      vidu++;
      cout<<"Tang len 1 ngay : ";
      cout<<vidu;
      int day;
      cout<<"Tang date len ? day : ";
      cin>>day;
      Date ketqua = day + vidu;
      cout<<"Ngay/thang/nam sau khi tang: "<<ketqua;
      cout<<"So day da tang: ";
      cout<<ketqua-vidu;
      getch();
      return 0;
}
