#include<fstream>
using namespace std;
int n,*a; //a la bien chua chuoi co do dai n
ofstream fout("output.txt");
void ghifile()
{
     for(int i=0; i<n; ++i) fout<<a[i];
     fout<<endl;
}


void thu(int i)// su dung ham de quy thu lan luot tung truong hop
{ for( int j=0 ; j<2; ++j)
{
       a[i]=j;
       if(i==n-1) ghifile();
       else thu(i+1);}
}

int main()
{
    ifstream fin("input.txt");
    fin>>n; a=new int[n];
    thu(0);
    fout.close(); fin.close();
}
