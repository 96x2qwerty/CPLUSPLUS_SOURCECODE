#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;

class pt
{
      float a,b,c;
      public:
             pt()
             {a=b=c=0;}
             
             pt(float a1,float b1,float c1)
             {a=a1;b=b1;c=c1;}
             
             pt(const pt &x)
             {a=x.a;b=x.b;c=x.c;}
             
             friend istream &operator >>(istream &is,pt &t);
             friend ostream &operator <<(ostream &os,pt &t);
             float giatri(float x);
             void giaipt();
};

istream &operator >>(istream &is,pt &t)
{
        cout<<"Nhap he so: ";
        cin>>t.a>>t.b>>t.c;
}

ostream &operator <<(ostream &os,pt &t)
{
        cout<<"Pt vua nhap la: "<<t.a<<"*x^2 + "<<t.b<<"*x + "<<t.c<<endl;
}

float pt::giatri(float x)
{
      return(a*pow(x,2)+b*x+c);
}

void pt:: giaipt()
{
     float d;
     if(a==0)
     cout<<"Pt co 1 nghiem: "<<-b/c;
     else if(a==0&&b==0)
     cout<<"Pt vo nghiem.";
     else
     d=pow(b,2)-4*a*c;
         if(d<0)
         cout<<"Pt vo nghiem.";
         else if(d==0)
         cout<<"Pt co 1 nghiem: "<<-b/(2*a);
         else cout<<"Pt co 2 nghiem: "<<((-b+sqrt(d))/4*a)<<"; "<<((-b-sqrt(d))/4*a);
}

main()
{
      pt a;
      float x;
      cin>>a;
      cout<<a;
      cout<<"Nhap x: ";
      cin>>x;
      cout<<"Pt =";
      cout<<a.giatri(x);
      
      a.giaipt();
      getch();
}
