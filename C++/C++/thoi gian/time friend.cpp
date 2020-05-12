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
			h=x;m=y;s=z;
		}
		
		friend istream &operator >>(istream &is,Time &t);
		friend istream &operator <<(istream &os,Time t);
		
		Time operator ++();
		Time operator ++(int );
		Time operator +(int x);
		Time operator -(Time b);
};

Time Time:: operator ++()
{
	if(h==23&&m==59&&s==59)
	{
		h=0;
		m=0;
		s=0;
	}
	else if(m==59&&s==59)
	{
		h++;
		m=0;
		s=0;
	}
	else if(s==59)
	{
		m++;
		s=0;
	}
	else
	{
		s++;
	}
}

Time Time:: operator ++(int )
{
	if(h==23&&m==59&&s==59)
	{
		h=0;
		m=0;
		s=0;
	}
	else if(m==59&&s==59)
	{
		++h;
		s=0;
	}
	else if(s==59)
	{
		++m;
		s=0;
	}
	else
	{
		++s;
	}
}

Time Time:: operator +(int x)
{
	int j=0,k=0;
	int a,b,c,mdu,sdu;
	if(x>3600)
	{
		a=x/3600;
		h=h+a;
		mdu=x-a*3600;
		if(mdu>60)
		{
                  b=mdu/60;
		          m=m+b;
		          if(m>60)
		          {
                            h++;
                            m=m-60;
                            sdu=mdu-b*60;
          		            s=s+sdu;
                            else if(s>60)
                            {
                                   s=s-60;
                                   m++;
                            }
                  }
                  else
                  {
                            s=s+sdu;
          		            if(s>60&&m==59)
          		            {
                                   s=s-60;
                                   m=0;
                                   h++;
                            }
                            else if(s>60)
                            {
                                   s=s-60;
                                   m++;
                            }
                  }
          		  
          		  
	}
	else 
    if(x<3600)
	{
         b=x/60;
         sdu=x-b*60;
         m=m+b;
         s=s+sdu;
           else 
           {
                if(s>60)
              {
                     s=s-60;
                     m++;
              }
         
                  else
                  {
                            s=s+sdu;
          		            if(s>60&&m==59)
          		            {
                                   s=s-60;
                                   m=0;
                                   h++;
                            }
                            else if(s>60)
                            {
                                   s=s-60;
                                   m++;
                            }
                  }
         }
}}

istream &operator >>(istream &is,Time &t)
{
    cout<<"Nhap gio,phut,giay: ";
    cin>>h>>m>>s;
    return is;
}

ostream &operator <<(istream &os,Time t)
{
    cout<<h<<" gio "<<m<<" phut "<<s<<" giay ";
    return os;
}

main()
{
      Time a;
      cin>>a;
      a++;
      cout<<a;
      getch();
}
