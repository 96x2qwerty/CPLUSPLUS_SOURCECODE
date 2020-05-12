#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
class dssv;
class SV
{
	private:
      char hoten[50];
      int masv;
      float d1,d2,d3,dtb;
      public:
             void nhap()
             {
                  cout<<"Nhap hoten: ";
                  cin>>hoten;
                  cout<<"Nhap ma sv: ";
                  cin>>masv;
                  cout<<"Nhap d1,d2,d3: ";
                  cin>>d1>>d2>>d3;
         
                  dtb=(d1+d2+d3)/3;

             }
             void xuat()
             {
                  cout<<"Ho ten: "<<hoten<<"\n"
                      <<"Ma sv: "<<masv<<"\n"
                      <<"d1,d2,d3: "<<d1<<", "<<d2<<", "<<d3<<"\n"
                      <<"Diem trung binh: "<<dtb;
             }
             
             friend void dssv::sxsv(SV a[],int n);
			 friend void dssv::thongke();
};

class dssv
{
      int n;
      SV *a;
      public:
             dssv()
             {
                   n=0;
                   a=NULL;
             }
             
             dssv(int x)
             {
                 n=x;
                 a=new SV[n];
             }
             
             void nhap()
             {
                  cout<<"Nhap so sv: ";
                  cin>>n;
                  a=new SV[n];
                  for(int i=0;i<n;i++)
                  a[i].SV:: nhap();
             }
             
             void xuat()
             {
                  cout<<"Danh sach SV vua nhap:\n";
                  for(int i=0;i<n;i++)
                  a[i].SV:: xuat();
             }
             
             dssv(const dssv &b)
             {
                        n=b.n;
                        a=new SV[n];
                        for(int i=0;i<n;i++)
                        *(a+i)=*(b.a+i);
             }
             
             void sxsv(SV a[],int n)
             {
	              int i,j,vtm;
                  SV tg;
                  for(i=0;i<n-1;i++)
	              {
                       vtm = i;
		               for(j=i+1;j<n;j++)
		               if((strcmp(a[j].hoten,a[vtm].hoten)<0) || ( strcmp(a[j].hoten,a[vtm].hoten)==0) && (a[j].dtb<a[vtm].dtb ))
		               vtm = j;
			
                       if ( vtm != i)
		               {
		                  tg=a[i];
		                  a[i]=a[vtm];
		                  a[vtm]=tg;
                       }
                    }
             }
             
             void thongke()
             {
                  int i,d=0;
                  for(i=0;i<n;i++)
                  do{
                  	if(d1>=5.5&&d2>=5.5&&d3>=5.5&&dtb>=7)
                  	{
                       a[i].xuat();
                       d++;
                  	}
                  }while(d<=(n*6/100));
             }
              
}


main()
{
      dssv a;
      int i;
      a.nhap();
      a.xuat();
      a.sxsv(a,n);
      
      getch();
}
