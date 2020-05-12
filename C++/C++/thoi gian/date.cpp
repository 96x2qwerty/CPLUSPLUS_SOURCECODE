#include<iostream>
#include<conio.h>
using namespace std;

class Date
{
	private:
		int d,m,y;
	public:
		//int nhuan();
		bool kiemtra();
		long cachngay(Date );
		void nhap();
		void xuat();
		long tong();
		Date curdate()
		{
              d=m=1;
              y=2000;
        }
        char* thu();
};

int n[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int nhuan(int n)
{
	     return ((n%4==0 && n %100 !=0) || (n%400 ==0));
}

bool Date:: kiemtra()
{
     if( d<0 || m <0 || m >12 || y<0 ) return false;
     else if ( (m == 1 || m ==3 || m ==5 || m ==7 || m ==8 || m ==10 || m ==12 )&& d>31 ) return false;
     else if( ( m ==4 || m == 6 || m == 9 || m ==11 ) && d >30 ) return false;
     else if( m ==2 && nhuan(y) && d >29 ) return false;
     else if( m ==2 && !nhuan(y) && d > 28 ) return false;
     return true;
}

void Date:: nhap()
{
	cout<<"Nhap ngay, thang, nam: ";
	do{
	cin>>d>>m>>y;
    }while(!kiemtra());
}

int thangnhuan(int m,int y)
{
     return n[m] + ((m==2)? nhuan(y):0);
}

long Date:: tong()
{
     long i;
     long kq;
     for(i=1;i<y;i++)
     kq+=(365+ nhuan(i));
     for(i=1;i<m;i++)
     kq+=thangnhuan(i,y);
     kq+=d;
     return kq;
}

long Date:: cachngay(Date d)
{
     return this->tong()-d.tong();
}

char* Date:: thu()
{
      Date x;
      long kc=this->cachngay(x);
      int du=kc%7;
      if(du<0) du+=7;
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

int main()
{
	Date x;
      int i;
      x.nhap();
      cout<<" la "<<x.thu();
	getch();
}
