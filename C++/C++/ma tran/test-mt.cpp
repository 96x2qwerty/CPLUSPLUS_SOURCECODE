#include<iostream>
#include<conio.h>
using namespace std;

class matrix
{
      int n;
      float *a;
      public:
             matrix()
             {
                     n=0;
                     a= NULL;
             }
             matrix()
             {
                     n=2;
                     a=new float(n);
                     for(int i=0;i<n;i++)
                     for(int j=0;j<n;j++)
                     a[i*n+j]=1,1;
             }
             bool operator ==(matrix b);
             matrix operator +(matrix b);
             friend istream &operator >>(istream &is,matrix &t);
             friend ostream &operator <<(ostream &os,matrix &t);
};

bool matrix::operator ==(matrix b)
{
     if()
