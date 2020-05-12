#include <iostream>
using namespace std;
class Time{
                int h, m, s;
                public:
                       Time(){ h=m=s= 0; }
                       Time(int a, int b, int c)
                       {
                                h= a; m= b; s= c;
                       }
                friend istream &operator >>( istream &is, Time &t);
                friend ostream &operator <<( ostream &os, Time &t);               
                void operator ++();                      
                void operator +(int n);
                void operator +(Time b);
                };
istream &operator >>(istream &is, Time &t)
{
        do{
                  cout<<"Nhap gio, phut, giay : ";
                  is>>t.h>>t.m>>t.s;
        }while( t.h<0 || t.h > 23 || t.m<0 || t.m>59 || t.s<0 || t.s>59 );
        return is;
}
ostream &operator <<( ostream &os, Time &t)
{
        os<<t.h<<" : "<<t.m<<" : "<<t.s;
        return os;
}
void Time::operator ++()
{          
     s = s+1;
     int mm= s/60;
     s= s%60;
     m = m + mm;
     
     int hh= m/60;
     m = m%60;
     h = h + hh;
     h = h%24;    
}
void Time::operator +(int n)
{
     s = s+ n;
     
     m = m + s/60;     
     s= s%60;
                    
     h = h + m/60;
     m = m%60;
     
     h = h%24;
}
void Time::operator +(Time b)
{   
     s = s + b.h*3600 + b.m *60 + b.s;     
     
     m = m + s/60;     
     s= s%60;
                    
     h = h + m/60;
     m = m%60;
     
     h = h%24;
}     
     
int main()
{
    Time a;
    cout<<"\nNhap thoi cho a:\n";
    cin>>a;
    cout<<"\nGio vua nhap la:\n";
    cout<<a;
        
    cout<<"\nGio sau khi cong them 1s :\n";
    ++a;    
    cout<<a;
    
    int n;
    cout<<"\nNhap so giay muon cong them: ";
    cin>>n;
    cout<<"\nGio sau khi cong them: \n";     
    a+n;
    cout<<a;
    
    cout<<"\nNhap thoi cho b:\n";    
    Time b;
    cin>>b;
    cout<<"\nGio a + b la:\n";
    a+b;
    cout<<a;
    
    cout<<endl;
    system("pause");
