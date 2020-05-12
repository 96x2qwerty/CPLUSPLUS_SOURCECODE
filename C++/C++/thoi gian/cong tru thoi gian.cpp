#include<iostream>
#include<conio.h>
using namespace std;
class Time
{
      int h,m,s;
      public:
             Time()
             {
                   h=m=s=0;
             }
             
             Time(int x,int y,int z)
             {
                      h=x;
                      m=y;
                      s=z;
             }
             
             void nhap()
             {
                  do{
                  cin>>h>>m>>s;
                  }while(h<0&&h>24&&m<0&&m>60&&s<0&&s>60);
             }
             
             void xuat()
             {
                  cout<<h<<" gio "<<m<<" phut "<<s<<" giay ";
             }
             
		friend istream &operator >>(istream &is,Time &t);
		friend ostream &operator <<(ostream &os,Time t);
		
		Time hour(int x);
		int second();
		Time operator ++();
		Time operator ++(int x);
		Time operator +(int x);
		Time operator -(Time b);
};

istream &operator >>(istream &is, Time &t)
{
        t.nhap();
}

ostream &operator <<(ostream &os, Time t)
{
        t.xuat();
}

int Time:: second()
{
     return h*3600+m*60+s;
}

Time Time:: hour(int x)
{
     Time tg;
     tg.h=x/3600;
     x=x-tg.h*3600;
     tg.m=x/60;
     tg.s=x-tg.m*60;
     return tg;
}

Time Time:: operator ++()
{
     long a=this->second()+1;
     Time tg=hour(a);
     return tg;
}

Time Time:: operator ++(int x)
{
     long a=this->second()+1;
     Time tg=hour(a);
     return tg;
}

Time Time:: operator +(int x)
{
     long a=this->second + x;
     a.hour();
     return a;
}

Time Time:: operator -(Time b)
{
     Time tg;
     if(this->second> b.second)
     tg.second=this->second - b.second;
     else
     tg.second=b.second - this->second;
     return tg;
}

main()
{
      Time a,b;
      cout<<"Nhap thoi gian: ";
      cin>>a;
      cout<<a;
      getch();
}
