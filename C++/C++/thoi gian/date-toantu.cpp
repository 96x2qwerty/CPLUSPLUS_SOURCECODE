#include<iostream>
#include<conio.h>
using namespace std;
long a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
class Date
{
      int d,m,y;
      public:
             Date()
             {
                   d=m=1;
                   y=2000;
             }
             
             Date(int dd,int mm,int yy)
             {
                      d=dd;m=mm;y=yy;
             }
             friend bool nhuan(int y);
             friend bool kiemtra(int d,int m,int y);
             friend Date CDate(long d);
             long Day();
             void operator ++();
             void operator ++(int e);
             Date operator --();
             Date operator --(int e);
             Date operator +(int b );
             Date operator +(Date b);
             friend Date operator +(int b,Date a);
             Date operator -(Date n);
             friend istream &operator >>(istream &is,Date &t);
             friend ostream &operator <<(ostream &os,Date &t);
};

//check
bool nhuan(int y)
{
     return (y%4==0);
}

bool kiemtra(int d,int m,int y)
{
     if( d<0 || m <0 || m >12 || y<0 ) return false;
     else if ( (m == 1 || m ==3 || m ==5 || m ==7 || m ==8 || m ==10 || m ==12 )&& d>31 ) return false;
     else if( ( m ==4 || m == 6 || m == 9 || m ==11 ) && d >30 ) return false;
     else if( m ==2 && nhuan(y) && d >29 ) return false;
     else if( m ==2 && !nhuan(y) && d > 28 ) return false;
     return true;
}

//input-output
istream &operator >>(istream &is,Date &t)
{
        do{
                  cout<<"Nhap ngay, thang, nam:";
                  cin>>t.d>>t.m>>t.y;
        }while(!kiemtra(t.d,t.m,t.y));
        return is;
}

ostream &operator <<(ostream &os,Date &t)
{
        cout<<"Ngay "<<t.d<<" thang "<<t.m<<" nam "<<t.y<<endl;
        return os;
}


//check date+day
long Date::Day()
{
     long day=d;
     int i;
     for(i=1;i<y;i++)
     day+=365+nhuan(i);
     for(i=0;i<m;i++)
     day+=a[i]+((i==2)?nhuan(y):0);
     return day;
}

Date CDate(long d)
{
     int dd=0,mm=1,yy=1;
     while(d>=365&&nhuan(yy)||d>=365&&!nhuan(yy))
     {
              d-=365+nhuan(yy);
              yy++;
     }
     while(d>(a[mm]+((mm==2)?nhuan(yy):0)))
     {
              d-=a[mm]+((mm==2)?nhuan(yy):0);
              mm++;
     }
     dd=d;
     return Date(dd,mm,yy);

}

//++
void Date:: operator ++()
{
     *this= CDate(this->Day()+1);
}

void Date:: operator ++(int e)
{
     *this= CDate(this->Day()+1);
}

//--
Date Date:: operator --()
{
     return CDate(this->Day()-1);
}

Date Date:: operator --(int e)
{
     return CDate(this->Day()-1);
}

//+
Date Date:: operator +(int b)
{
     *this= CDate(this->Day()+b);
}

Date Date:: operator +(Date b)
{
     return CDate(this->Day()+b.Day());
}

Date operator +(int b,Date a)
{
     return CDate(a.Day()+b);
}


main()
{
      Date a;
      int b;
      cin>>a;
      cout<<a;
      a++;

      cout<<a;
      cout<<"Nhap b:";
      cin>>b;
      Date kq=b+a;
      cout<<kq;
      getch();
}
