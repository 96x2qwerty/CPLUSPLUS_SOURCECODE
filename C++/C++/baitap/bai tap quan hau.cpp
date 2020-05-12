#include <iostream>
 #include <fstream>
 using namespace std;
 ofstream fout("out6.txt");
 int dung=0;
 int n=8;
 int* ngang;
 int* doc;
 int* cheo1;
 int* cheo2;
 int* a;
 int* b;
 void xuat()
 {
 for(int i=0; i<n; ++i)
 {
 fout<<a[i]<<" "<<b[i]<<endl;
 }
 dung=1;
 }
 void thu(int i)
 {
 if(dung==0)
 for (int x=0; x<n; ++x)
 for (int y=0; y<n; ++y)
 if( (ngang[y]==0) && (doc[x]==0) && (cheo1[x-y+n-1]==0) && (cheo2[x+y]==0))
 {
 a[i]=x;
 b[i]=y;
 ngang[y]=1;
 doc[x]=1;
 cheo1[x-y+n-1]=1;
 cheo2[x+y]=1;
 if(i==n-1) xuat();
 else thu(i+1);
 ngang[y]=0;
 doc[x]=0;
 cheo1[x-y+n-1]=0;
 cheo2[x+y]=0;
 }
 }
 main()
 {
 a= new int[n];
 b= new int[n];
 ngang=new int[n];
 doc=new int[n];
 cheo1=new int[2*n-1];
 cheo2=new int[2*n-1];
 for(int i=0;i<n;++i) ngang[i]=doc[i]=cheo1[i]=cheo2[i]=0;
 for(int i=n;i<2*n-1;++i) cheo1[i]=cheo2[i]=0;
 thu(0);
 fout.close();
 }
