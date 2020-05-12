#include <iostream>
 #include <fstream>
 using namespace std;
 ofstream fout("caituiout.txt");
 int n;
 int m;
 int khoiluongmax=-1;
 int giatrimax=-1;
 int* a;
 int* b;
 int *c;
 int *d;
 void xuat()
 {
 fout<<giatrimax<<endl;
 for(int i=0; i<n; ++i)
 {
 if(c[i]==1) fout<<a[i]<<" ";
 }

 }
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
 if ((khoiluong<=m)&&(giatri>giatrimax))
 {
 giatrimax=giatri;
 for(int k=0; k<n; ++k)
 c[k]=b[k];
 }
 }
 void thu(int i)
 {
 for (int j=0;j<2;++j)
 {
 b[i]=j;
 if (i==n-1) kiemtra();
 else thu(i+1);
 } 
 }

 main()
 {
 ifstream fin("caituiin.txt");
 fin>>n;
 fin>>m;
 a=new int[n];
 b=new int[n];
 c=new int[n];
 d=new int[n];
 for(int i=0; i<n; ++i) fin>>a[i];
 for(int i=0; i<n; ++i) fin>>d[i];
 thu(0);
 xuat();
 fin.close();
 fout.close();
 }
