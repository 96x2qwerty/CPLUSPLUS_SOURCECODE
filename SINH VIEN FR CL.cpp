#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;
class SV
{
char ten[10];
int ns;
float dt1,dt2,dt3;
public :
SV()
{
strcpy(ten,”");
ns=0;
dt1=dt2=dt3=0;
}
friend istream &operator>>(istream &is,SV &a);
friend ostream &operator<<(ostream &os,SV &a);
float dtb()    { return (dt1+dt2+dt3)/3; }
friend class DSSV;
};
istream &operator>>(istream &is,SV &a)
{
cout<<”Nhap ten SV: “;
fflush(stdin);
is.getline(a.ten,10);
cout<<”Nhap ngay sinh: “;
is>>a.ns;
cout<<”Nhap dien thi 1,2,3: “;
is>>a.dt1>>a.dt2>>a.dt3;
return is;
}
ostream &operator<<(ostream &os,SV &a)
{
os<<”\nTen: “<<a.ten<<”, Ngay sinh: “<<a.ns<<endl;
os<<”diem thi 1,2,3: “<<a.dt1<<”, “<<a.dt2<<”, “<<a.dt3<<”,DTB: “<<a.dtb();
return os;
}
class DSSV
{
SV *ds;
int spt;
public :
DSSV()
{ spt=100; ds=new SV[spt]; }
DSSV(int n)    { spt=n; ds=new SV[spt]; }
~DSSV()    { spt=0; delete []ds; }
friend istream &operator>>(istream &is,DSSV &a);
friend ostream &operator<<(ostream &os,DSSV &a);
SV &operator[](int i)    { return ds[i]; }
int vtri();
DSSV& operator=(DSSV &b);
};
istream &operator>>(istream &is,DSSV &a)
{
cout<<”Nhap so luong SV:”;    is>>a.spt;
a.ds=new SV[a.spt];
for(int i=0;i<a.spt;i++)
{
cout<<”\n———-Nhap SV thu “<<i+1<<”: “<<endl;
is>>a.ds[i];
}
return is;
}
ostream &operator<<(ostream &os,DSSV &a)
{
for(int i=0;i<a.spt;i++)
{
os<<”\n———-Sinh vien thu “<<i+1<<”:”<<endl;
os<<a.ds[i];
}
os<<endl;
return os;
}
DSSV& DSSV::operator=(DSSV &b)
{
if (this != &b)
{
delete []ds;
spt=b.spt    ;
ds=new SV[spt];
for(int i=0;i<spt;i++)
ds[i]=b.ds[i];
}
return *this;
}
int DSSV::vtri()
{
int x=0;
float max=ds[0].dtb();
for(int i=1;i<spt;i++)
if (max < ds[i].dtb())    x=i;
return (int)x+1;
}
int main()
{
DSSV a;
cin>>a;
cout<<”\n———Hien thi: “;
cout<<a;
//Tim Sv co diem bt cao nhat
cout<<”Vi tri Sv co DTB cao nhat: “<<a.vtri()<<endl;
//Tim SV thu i
int n;
cout<<”\nNhap thu tu sinh vien muon hthi:”; cin>>n;
cout<<”\n—-Sinh vien thu “<<n<<” : “<<endl<<a[n-1];
DSSV b;
//Gan b=a;
b=a;
cout<<”\n—-Hien thi ds b:\n”<<b;
system(“pause”);
return 0;
