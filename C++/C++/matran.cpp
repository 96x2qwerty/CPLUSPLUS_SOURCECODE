#include<iostream>
#include<conio.h>
using namespace std;
class Matrix
{
     private:
             int m,n;
             int *MT;
     public:
            bool ktra();
            void nhap();
            void xuat();
            void max_hang();
            void max_cot();
            Matrix()
            {m=n=0;}
};

bool Matrix:: ktra()
{
     if(m<0||n<0)
     return false;
     else return true;
}

void Matrix:: nhap()
{
     int i,j;
     MT=new int[m*n];
     cout<<"Nhap so hang: ";
     cin>>m;
     cout<<"Nhap so cot: ";
     cin>>n;
     cout<<"Nhap so phan tu:\n";
     for(i=0;i<m;i++)
     {
             for(j=0;j<n;j++)
             cin>>MT[i*n+j];
     }
}

void Matrix:: xuat()
{
     cout<<"Ma tran vua nhap la:\n";
     for(int i=0;i<m;i++)
     {
             for(int j=0;j<n;j++)
             cout<<MT[i*n+j]<<" ";
             cout<<endl;
     }
}

//void Matrix:: max_hang()
//{
//     int i,j,max;
//     for(i=0;i<m;i++)
//     for(j=0;j<n;j++)
//}

main()
{
      Matrix x;
      x.nhap();
      x.xuat();
      getch();
}
