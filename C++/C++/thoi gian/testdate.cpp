#include<iostream>
#include<conio.h>
using namespace std;

int songay[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
class Date
      {
          int ngay,thang,nam;
          public:
                 Date(){ ngay=thang=1; nam = 2000; }// 1/1/2000 la thu 7
                 void nhap();
                 void xuat() { cout<<ngay<<"/"<<thang<<"/"<<nam; }
                 long tongngay();
                 bool kiemtra();
                 long khoangcach(Date );
                 char* thu();
                 
      };
      
int namnhuan(int n)
{
     return ((n%4==0 && n %100 !=0) || (n%400 ==0));
}

bool Date::kiemtra()
{
     if( ngay<0 || thang <0 || thang >12 || nam<0 ) return false;
     else if ( (thang == 1 || thang ==3 || thang ==5 || thang ==7 || thang ==8 || thang ==10 || thang ==12 )&& ngay>31 ) return false;
     else if( ( thang ==4 || thang == 6 || thang == 9 || thang ==11 ) && ngay >30 ) return false;
     else if( thang ==2 && namnhuan(nam) && ngay >29 ) return false;
     else if( thang ==2 && !namnhuan(nam) && ngay > 28 ) return false;
     return true;
}

void Date::nhap()
{
     do{
            cout<<"Nhap ngay - thang - nam: ";
            cin>>ngay>>thang>>nam;
        } while ( !kiemtra() );
}

int ngaycuathang( int thang, int nam)
{
    return songay[thang]+ ( (thang==2)?namnhuan(nam):0 );
}

long Date::tongngay()
{
     long i,kq=0;
     for( i=1; i<nam; i++)
     kq += 365 + (long )namnhuan(i);
     for( i=1; i<thang; i++)
     kq += ngaycuathang(i,nam);
     kq += ngay;
     return kq;
}

long Date::khoangcach(Date d)
{
     return this->tongngay()-d.tongngay();
}

char* Date::thu()
{
      Date x;
      long kc=this->khoangcach(x);
      int du=kc%7;
      if( du<0 ) du += 7;
      char* kq= new char[7];
      switch(du)
      {
           case 0: strcpy(kq,"thu bay");break;
           case 1: strcpy(kq,"chu nhat");break;
           case 2: strcpy(kq,"thu hai");break;
           case 3: strcpy(kq,"thu ba");break;
           case 4: strcpy(kq,"thu tu");break;
           case 5: strcpy(kq,"thu nam");break;
           case 6: strcpy(kq,"thu sau");break;
      }
      return kq;
}

main()
{
      Date x;
      int i;
      do{
           x.nhap();
           cout<<" la "<<x.thu();
           cout<<"\nThu lai ? ( 1/0 ) : ";
           cin>>i;
      }while (i );
      return 0;
}
