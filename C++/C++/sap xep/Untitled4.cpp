#include<fstream>
#include<iostream>
using namespace std;
int  n, *a, *b, *c;
ofstream fout("output.txt");
void ghifile()
{
     for(int i=0; i<n; ++i) fout<<a[i];
     fout<<endl;
}

void thu(int i)
{ 
     for(int j=0;j<n;++j)
     {
             if(c[j]=0)
             {a[i]=b[j];
             c[j]=1;
             if(i==n-1) ghifile();
             c[j]=0;
             }
}}

int main()
{
    ifstream fin("input.txt");
    fin>>n; a=new int[n];
    b=new int[n];
    c=new int[n];
    thu(0);
    ghifile();
    fout.close(); fin.close();
}
