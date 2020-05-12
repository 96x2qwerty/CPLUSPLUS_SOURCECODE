#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;

class SV
{
      protected:
      string ten,masv;
      float d1,d2,d3;
      public:
             SV()
             {
                 ten = " ";
                 masv="0";
                 d1=d2=d3=0;
             }
             
             SV(string t1,string m1,float d11,float d22,float d33)
             {
                       ten = t1;
                       masv = m1;
                       d1=d11;d2=d22;d3=d33;
             }
             
             SV(const SV &a)
             {
                      ten = a.ten;
                      masv = a.masv;
                      d1=a.d1;d2=a.d2;d3=a.d3;
             }
             
             void nhap();
             void xuat();
             float dtb()
             {return (d1+d2+d3)/3;}
             bool operator > (SV b);
             friend class DSSV;
};

void SV::nhap()
{
     cout<<"Nhap ten sv: ";
     cin.ignore(1);
     getline(cin,ten);
     cout<<"Nhap ma sv: ";
     getline(cin,masv);
     cout<<"Nhap diem 3 mon: ";
     cin>>d1>>d2>>d3;
}

void SV::xuat()
{
     cout<<"\nTen SV: "<<ten
         <<"\nMa SV: "<<masv
         <<"\nCac diem: "<<d1<<", "<<d2<<", "<<d3
         <<"\nDiem trung binh: "<<dtb()<<endl;
}

class DSSV
{
      
      SV *a;
      int n;
      public:
             DSSV()
             {
                   a=NULL;
                   n=0;
             }
             
             ~DSSV()
             {
                    if(n!=0)
                    delete[] a;
                    n=0;
             }
             
             friend istream &operator >>(istream &is,DSSV &p);
             friend ostream &operator <<(ostream &os,DSSV &p);
             void sapxep();
};

istream &operator >>(istream &is,DSSV &p)
{
        cout<<"Nhap so luong SV: ";
        cin>>p.n;
        p.a=new SV[p.n];
        for(int i=0;i<p.n;i++)
        {
                cout<<"Nhap sinh vien thu "<<i+1<<endl;
                p.a[i].nhap();
        }
}

ostream &operator <<(ostream &os,DSSV &p)
{
        cout<<"Danh sach SV vua nhap la:\n";
        for(int i=0;i<p.n;i++)
        {
                p.a[i].xuat();
        }
}

bool SV::operator >(SV b)
{
     if( dtb()>b.dtb() )
     return true;
     else return false;
}

void DSSV::sapxep()
{
     for(int i=0;i<n-1;i++)
     for(int j=i+1;j<n;j++)
     if(a[i]>a[j])
     {SV t = a[i];
     a[i] = a[j];
     a[j] = t;}
}

main()
{
      DSSV a;
      cin>>a;
      cout<<a;
      a.sapxep();
      cout<<a;
      getch();
}
