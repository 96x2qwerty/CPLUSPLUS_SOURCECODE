#include <iostream>
#include <fstream>
using namespace std;
ofstream fout("out1.txt");
int n;
int* a;
int* b;
void xuat()
{
     int ok=0;
     for (int i=0;i<n;++i)
     {
      if (a[i]==1)
      {
      fout<<b[i]<<" ";
      ok=1;
      }
      }
if(ok==1)fout<<endl;
}
void thu(int i)
{
for (int j=0;j<2;++j)
{
a[i]=j;
if (i==n-1) xuat();
else thu(i+1);
}
}
int main()
{
ifstream fin("inp1.txt");
fin>>n;
b=new int[n];
a=new int[n];
for (int i=0;i<n;++i) fin>>b[i];
thu(0);
fin.close();
fout.close();
}
