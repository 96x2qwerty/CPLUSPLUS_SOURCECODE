#include<iostream>
#include<conio.h>
using namespace std;
class Time
{
      int h,m,s;
      public:
             Time();
             Time( int, int, int);
             friend istream &operator >> ( istream &, Time &);
             friend ostream &operator << ( ostream &, Time &);
             friend Time convert_s_to_t (long );
             long convert_t_to_s ();
             void operator ++ ();
             Time operator + (int );
             Time operator - (Time);
};
Time::Time()
{
            h=m=s=0;
}
Time :: Time ( int hh, int mm, int ss)
{
     h=hh;
     m=mm;
     s=ss;
}
istream &operator >> ( istream &is, Time &t)
{
        cout<<"\nNhap gio, phut, giay: ";
        is>>t.h>>t.m>>t.s;
        return is;
}
ostream &operator << ( ostream &os, Time &t)
{
        os<<endl<<t.h<<"h"<<t.m<<"m"<<t.s<<"s";
        return os;
}
Time convert_s_to_t ( long x)
{
     Time a;
     a.h = x/3600;
     a.m= (x%3600) / 60;
     a.s = x%60;
     return a;
}
long Time::convert_t_to_s ()
{
     return h*3600 + m*60 + s;
}
void Time::operator ++()
{
     long a= this->convert_t_to_s();
     a=a+1;
     *(this) = convert_s_to_t(a);
}
Time Time::operator + (int n)
{
     long a= this->convert_t_to_s();
     a=a+n;
     return convert_s_to_t(a);
}
Time Time::operator - (Time y)
{
     long a= this->convert_t_to_s();
     long b= y.convert_t_to_s();
     long c= a-b;
     return convert_s_to_t(c);
}
main()
{
      Time a,b,c;
      cin>>a;
      cout<<a;
      ++a;
      cout<<a;
      a=a+23;
      cout<<a;
      cin>>b;
      c=a-b;
      cout<<"Khoang cach giua 2 moc thoi gian vua nhap: "<<c;
      getch();
      return 0;
}
        
        
        
        
        
        
        
        
        
        
