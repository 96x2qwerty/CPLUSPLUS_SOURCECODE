#include <conio.h>
#include <iostream>
#include <iomanip>
#include <malloc.h>
using namespace std;
class taphop
{
      int *a,n;
      public:
	     taphop(){a=new int; n=0;}
	     ~taphop(){}
	     friend istream& operator >> (istream& is, taphop &b);
	     friend ostream& operator << (ostream& os, taphop &b);
	     taphop operator + (taphop b);
	     taphop operator * (taphop b);
	     taphop them ();
	     taphop xoa ();
	     int ktra (int x);
      };
int taphop::ktra(int x)
{
     if(n==0) return 1;
     else
     for(int i=0;i<n;i++) if(a[i]==x) return 0;
     return 1;
     }
taphop taphop::operator * (taphop b)
{
     taphop tg;
     int i,j,pt=0;
     for(i=0;i<n;i++)
      for(j=0;j<b.n;j++)
      if(tg.ktra(a[i])&& a[i]==b.a[j])
      {
	tg.a=(int*)realloc(tg.a,sizeof(int));
	tg.a[pt]=a[i];
	pt++;
      }
      tg.a[pt]='/0';
      tg.n=pt;
      return tg;
}
taphop taphop::operator + (taphop b)
{
       taphop tg;
       int i,j,pt=0;
       for(i=0;i<n;i++)
	 {
	  tg.a=(int*)realloc(tg.a,sizeof(int));
	  tg.a[pt]=a[i];
	  pt++;
	 }
       for(i=0;i<b.n;i++)
	if(ktra(b.a[i]))
       {
	 tg.a=(int*)realloc(tg.a,sizeof(int));
	 tg.a[pt]=b.a[i];
	 pt++;
       }
       tg.a=(int*)realloc(tg.a,sizeof(int));
       tg.a[pt]='/0';
       tg.n=pt;
       return tg;
}
istream& operator >> (istream& is, taphop &b)
{
	 int tg;
	 cout<<"Nhap so phan tu: ";
	 is>>b.n;
	 b.a=new int[b.n];
	 for(int i=0;i<b.n;i++)
	 {
	   do
	      {
		 cout<<"Nhap phan tu thu "<<i+1<<": ";
		 is>>tg;
	      }while(b.ktra(tg)==0);
	   b.a[i]=tg;
	 }
	 return is;
	 }
ostream& operator << (ostream& os, taphop &b)
{
	 for(int i=0;i<b.n;i++)
	 os<<b.a[i]<<setw(4);
	 return os;
	 }
taphop taphop:: them()
{
       taphop tg;
       int x,i;
       do
       {
	cout<<"Phan tu de them vao: ";
	cin>>x;
       }
       while(ktra(x)!=1);
       n++;
       tg.n=n;
       tg.a=new int[n];
       for(i=0;i<n;i++) if(tg.ktra(a[i])) tg.a[i]=a[i];
       tg.a[n-1]=x;
       return tg;
       }
taphop taphop::xoa()
{
       taphop tg;
       tg.n=n-1;
       tg.a=new int [n-1];
       for(int i=0;i<n-1;i++) tg.a[i]=a[i+1];
       tg.a[n-1]='/0';
       return tg;
       }
int main()
{
    taphop c,d,hop,giao;
    cout<<"Nhap tap hop c: "<<endl;
    cin>>c;
    cout<<"Nhap tap hop b: "<<endl;
    cin>>d;
    cout<<"Tap hop c: "<<c;
    cout<<endl<<"Tap hop b: "<<d<<endl;
    c=c.them();
    cout<<c;
    cout<<endl<<"Sau khi xoa 1 phan tu o dau: ";
    c=c.xoa();
    cout<<c;
    cout<<endl<<"Tap hop sau khi cong C+d: ";
    hop=d+c;
    cout<<hop;
    c=c*d;
    cout<<endl<<"Tap hop sau khi giao C va d: ";
    cout<<c;
    getch();
    return 0;
    }
