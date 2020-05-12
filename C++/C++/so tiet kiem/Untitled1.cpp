#include<iostream>
#include<conio.h>
#include<string>
#include<time.h>
#include<Date.h>
using namespace std;

class STKkhongkihan
{
      string ten;
      int cmnd;
      float tiengui,laixuat;
      Date ngaylap;
      long thanggui;
      public:
             STKkhongkihan(string t=" ",int cmnd1 = 0,float tg = 0,float lx = 0,int ngay = 0,int thang = 0,int nam = 0)
             {
                        ten = t;
                        cmnd = cmnd1;
                        tiengui = tg;
                        laixuat = lx;
                        Date();
             }
             
             
             
             virtual void nhap()
             {
                  cout<<"Nhap ten khach hang: ";
                  getline(cin,ten);
                  cout<<"Nhap so CMND: ";
                  cin>>cmnd;
                  cout<<"So tien gui: ";
                  cin>>tiengui;
                  cout<<"Lai xuat: ";
                  cin>>laixuat;
                  cout<<"Nhap ngay lap so: ";
                  cin>>ngaylap;
             }
             
             virtual void xuat()
             {
                  cout<<"\nTen chu STK: "<<ten
                      <<"\nSo CMND: "<<cmnd
                      <<"\nSo tien da gui: "<<tiengui
                      <<"\nLai xuat STK: "<<laixuat
                      <<"\nNgay lam STK: "<<ngaylap
                      <<lai();
             }
             
             Date now()
             {
             	int ngay,thang,nam ;
    			tm *today ;
    			time_t now;
    			time( &now );
    			today = localtime( &now );
    			ngay=today->tm_mday;
    			thang=today->tm_mon+1;
    			nam=today->tm_year+1900;
    			cout<<"Hom nay la ngay "<<ngay<<" thang "<<thang<<" nam "<<nam;
    			return (ngay, thang, nam);
             }
             
              float lai()
			{
					Date a = now();
					int sothangdagui;float n;
					sothangdagui=(a.getmonth()-ngaylap.getmonth())+12*(a.getyear()-ngaylap.getyear());
					if (a.getday()<ngaylap.getday())
						sothangdagui-=1;
					n= sothangdagui;
					cout<<"Lai cua so: "<<n*tiengui*laixuat;
			}
             
};

/*
class STKcokihan:public STK
{
      long thanggui;
      public:
             STKcokihan(string t=" ",int cmnd1 = 0,float tg = 0,float lx = 0,int ngay = 0,int thang = 0,int nam = 0,long n = 0): STK(t,cmnd1,tg,lx,ngay,thang,nam)
             {
                  thanggui = n;            
             }
             
             
             void nhap()
             {
                  STK::nhap();
             }
             
            
             
             void xuat()
             {
                  STK::xuat();
                  cout<<a;
                  //cout<<"\nSo thang gui: "<<thanggui;
             }
};
*/

main()
{
      STKkhongkihan a;
      a.nhap();
      a.xuat();
      getch();
}
