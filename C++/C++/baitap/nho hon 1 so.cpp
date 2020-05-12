/* #include<fstream>
#include<iostream>
using namespace std;
int* a;int* b;int *c;int n;int tong;int max=0;int m;
ofstream fout("output.txt");

void ghifile()
{
     for(int i=0; i<n; ++i)
     {if(c[i]=1) fout<<c[i]<<" ";}
     fout<<endl;
}

void kiemtra()
{
     int max;
     tong=0;
     for(int i=0;i<n;i++)
     {if(b[i]==1)
     {tong=tong+a[i];}}
      if((tong<=m) && (tong>max))
{ max=tong;
for(int i=0; i<n;++i) c[i]=b[i]; }
}

void thu(int i)
{
     for(int j=0;j<2;++j)
     {
             b[i]=j;
             if(i=n-1) kiemtra();
             else thu(i+1);
             }
}


int main()
{
     ifstream fin("input.txt");
    fin>>n;
    fin>>m;
    a=new int[n];
    b=new int[n];
    c=new int[n];
    for(int i=0;i<n;++i)
    {fin>>a[i];}
    thu(0);
    ghifile();
    fout.close(); fin.close();
}
*/

#include <iostream>
#include<fstream>
using namespace std;
int* a;
int* b;
int* c;
int n,m;
int _max=-1;
ofstream fout("output.txt");

void ghifile()
{
for(int i=0; i<n; ++i)
if ( c[i]==1 )fout<<a[i]<<" ";
fout<<endl;
}

void kiemtra()
{
int tong=0;
for(int i=0;i<n;i++)
{ if(b[i]==1)
tong=tong+a[i];}
if(tong<=m && tong>_max)
{ _max=tong;
for(int i=0; i<n;++i) c[i]=b[i]; }
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


int main()
{
ifstream fin("input.txt");

a=new int[n];
b=new int[n];
c=new int[n];
fin>>n;
for(int i=0;i<n;++i)
{fin>>a[i];}
fin>>m;
thu(0);
ghifile();
fout.close(); fin.close();
}
