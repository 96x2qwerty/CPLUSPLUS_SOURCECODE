#include<fstream>
#include<iostream>
using namespace std;
int* a;
int* b;
int *c;
int *d;
int m,n;
int tongkhoiluong=0;
int tonggiatri=0;
ofstream fout("output1.txt");

void ghifile()
{
     for(int i=0;i<n;++i)
     { 
     if(c[i]=1)
     fout<<a[i]<<" ";
     fout<<d[i]<<" ";
     fout<<endl;}
}

/*void kiemtra()
{
     int giatri=0;
     int khoiluong=0;
     for(int i=0;i<n;++i)
     {if(b[i]==1)
     {giatri=giatri+d[i];
     khoiluong=khoiluong+a[i];}}
     if((khoiluong<=m) && (giatri>tonggiatri))
     {giatri=tonggiatri;
     for(int i=0;i<n;++i)
     c[i]=b[i];}
}
*/

void kiemtra()
{
     int giatri=0;
     int khoiluong=0;
         for(int i=0; i<n; ++i)
                 {
                 if (b[i]==1)
                    {
                    giatri=giatri+d[i];
                    khoiluong=khoiluong+a[i];
                    }
                 }
                 if ((khoiluong<=m)&&(giatri>tonggiatri))
                    {
                    giatri=tonggiatri;
                    for(int k=0; k<n; ++k)
                    c[k]=b[k];
                    }
}

void thu(int i)
{
     for(int j=0;j<2;++j)
     {
     b[i]=j;
     if(i==n-1) kiemtra();
     else thu(i+1);
     }
}

main()
{
     ifstream fin("input1.txt");

     a=new int[n];
     b=new int[n];
     c=new int[n];
     fin>>n;
     fin>>m;
     for(int i=0;i<n;++i) {fin>>a[i];}
     for(int i=0;i<n;++i) {fin>>d[i];}
     
     thu(0);
     ghifile();
     fout.close(); fin.close();
}

     
     
