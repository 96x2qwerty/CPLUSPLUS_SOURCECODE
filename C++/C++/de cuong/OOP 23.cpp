#include<iostream>
#include<conio.h>
using namespace std;
class phanso
{
      int tu,mau;
      public:
             phanso();
             phanso( int , int );
             float giatri();
             void nhap();
             void xuat();
             friend phanso operator + ( phanso, phanso);
             friend phanso operator * ( phanso, phanso );
             friend bool operator > (phanso , phanso );
};
phanso::phanso()
{
                tu = 1;
                mau = 2;
}
phanso::phanso ( int t, int m)
{
               tu =t;
               mau = m;
}
float phanso::giatri()
{
      return (float)tu/mau;
}
void phanso::nhap()
{
     cout<<"Nhap tu: ";
     cin>>tu;
     cout<<"Nhap mau: ";
     cin>>mau;
}
void phanso::xuat()
{
     cout<<endl<<tu<<"/"<<mau;
}
phanso operator + ( phanso a, phanso b )
{
       phanso c;
       c.tu = a.tu*b.mau + a.mau*b.tu ;
       c.mau=a.mau*b.mau;
       return c;
}
phanso operator * ( phanso a, phanso b )
{
       phanso c;
       c.tu = a.tu*b.tu ;
       c.mau=a.mau*b.mau;
       return c;
}
bool operator > (phanso a, phanso b)
{
       if ( a.giatri() > b.giatri() ) return true;
       return false;
}
main()
{
      phanso a,b,c;
      a.nhap();
      b.nhap();
      c=a*b;
      c.xuat();
      if( c>a ) cout<<"\nc lon hon a";
      getch();
      return 0;
}
