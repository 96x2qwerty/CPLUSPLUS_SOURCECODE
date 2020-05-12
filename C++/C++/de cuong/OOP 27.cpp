#include<conio.h>
#include<iostream>
using namespace std;
class sinhvien
{
      string ten,ma;
      float dcs, dcn;
      public:
             sinhvien();
             sinhvien( string , string, float, float);
             void nhap();
             void xuat();
             float hocbong ();
};
sinhvien::sinhvien()
{
                    ten = ma = "";
                    dcs= dcn = 0;
}
sinhvien::sinhvien( string t, string m, float cs, float cn )
{
                    ten =t; 
                    ma = m;
                    dcs = cs;
                    dcn= cn;
}
void sinhvien::nhap()
{
     cout<<"Nhap ten: ";
     cin.ignore(1);
     getline( cin,ten );
     cout<<"Nhap ma: ";
     getline( cin,ma);
     cout<<"Nhap diem co so va diem chuyen nganh: ";
     cin>>dcs>>dcn;
}
void sinhvien::xuat()
{
     cout<<"\nTen :" <<ten<<"\nMa sv: "<<ma
     <<"\nDiem co so: "<<dcs<<"    Diem chuyen nganh: "<<dcn<<endl;
}
float sinhvien::hocbong()
{
      return (dcs+dcn)/2;
}
class canbo: public sinhvien
{
      float dt;
      public:
             canbo():sinhvien() { dt= 0; }
             canbo( string t, string m, float cs, float cn, float dt2)
             : sinhvien( t,m,cs,cn)
             {
                         dt= dt2;
             }
             void nhap();
             void xuat();
             float hocbong();
};
void canbo::nhap()
{
     sinhvien::nhap();
     cout<<"Nhap diem thuong: ";
     cin>>dt;
}
void canbo::xuat()
{
     sinhvien::xuat();
     cout<<"Diem thuong: "<<dt<<endl;
}
float canbo::hocbong ()
{
      return sinhvien::hocbong() + dt;
}
main()
{
      canbo a;
      a.nhap();
      a.xuat();
      cout<<a.hocbong();
      getch();
      return 0;
}
     
