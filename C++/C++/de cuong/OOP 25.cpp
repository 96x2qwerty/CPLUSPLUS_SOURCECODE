#include<iostream>
#include<string>
#include<conio.h>
using namespace std;
class sv
{
      string ten,ma;
      float dtk ;
      int drl;
      public:
             sv();
             sv(string t, string m, float tk, int rl);
             friend istream &operator >>(istream &is , sv &s);
             friend ostream &operator <<(ostream &os, sv &s);
             bool operator > (sv b);
             friend void sapxep(sv [], int n);
};
sv::sv()
{
        ten="";
        ma="00000";
        dtk=0;
        drl=0;
}
sv::sv(string t, string m, float tk, int rl)
{
              ten =t;
              ma = m;
              dtk = tk;
              drl = rl;
}
istream &operator >>(istream &is , sv &s)
{
        cout<<"\nNhap ten: ";
        cin.ignore(1);
        getline(is, s.ten);
        cout<<"Nhap ma: ";
        getline(is,s.ma);
        cout<<"Nhap diem tong ket: ";
        is>>s.dtk;
        cout<<"Nhap diem ren luyen: ";
        is>>s.drl;
        
        return is;
}
ostream &operator <<(ostream &os, sv &s)
{
        os<<"\n\nSinh vien: "<<s.ten<<"\nMa sv: "<<s.ma
        <<"\nDiem tong ket: "<<s.dtk<<"  Diem ren luyen: "<<s.drl;
        return os;
}
bool sv::operator > (sv b)
{
     if (dtk > b.dtk ) return true;
     if ( dtk == b.dtk && drl > b.drl ) return true;
     return false;
}
void sapxep(sv a[], int n)
{
          for( int i=0; i<n-1; i++)
          for( int j=i+1; j<n; j++)
          if( a[i] > a[j] )
          {
              sv tam = a[i];
              a[i]=a[j];
              a[j]=tam;
          }
}
main()
{
      sv *a;
      int n;
      
      cout<<"Nhap so luong sinh vien: ";
      cin>>n;
      a=new sv[n];
      
      for( int i=0; i<n ; i++)
      cin>>a[i];
      
      sapxep(a,n);
      
      for( int i=0; i<n; i++)
      cout<<a[i];
      
      
      getch();
      return 0;
}
