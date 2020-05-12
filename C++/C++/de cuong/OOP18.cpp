#include<iostream>
#include<conio.h>
using namespace std;
class sinhvien
{
      char hoten[50],masv[5];
      float d1,d2,d3;
      public:
            sinhvien()
            {
                      strcpy(hoten,"");
                      strcpy(masv,"00000");
                      d1=d2=d3=0;
            }
            void nhap();
            void xuat();
            float dtb();
};
void sinhvien::nhap()
{
     cout<<"Nhap ho ten: ";
     cin.ignore(1);
     cin.getline (hoten,50);
     cout<<"Nhap ma sinh vien: ";
     cin>>masv;
     cout<<"Nhap diem cua 3 mon hoc: ";
     cin>>d1>>d2>>d3;
}
void sinhvien::xuat()
{
     cout<<"Ten sinh vien: "<<hoten<<endl
     <<"Ma sinh vien: "<<masv<<endl
     <<"Diem 3 mon : "<<d1<<" "<<d2<<" "<<d3<<endl
     <<"Diem trung binh : "<<dtb();
}
float sinhvien::dtb()
{
      return (d1+d2+d3)/3;
}
main()
{
      sinhvien a;
      a.nhap();
      a.xuat();
      getch();
} 
      
