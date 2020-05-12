#include <iostream>
using namespace std;
class vidu
{
int *a,n;
public:
vidu():n(0),a(NULL){}
~vidu(){n=0;delete [] a;}
void nhap();
void xuat();
vidu cainayhay();
};
vidu vidu::cainayhay()
{
vidu d;
d=*this;
return d;
}
void vidu::nhap()
{
cout<<"Nhap spt: ";
cin>>n;
a=new int [n];
for(int i=0;i<n;i++)
{
cout<<"Nhap phan tu thu "<<i+1<<": ";
cin>>a[i];
}
}
void vidu::xuat()
{
for(int i=0;i<n;i++)
cout<<a[i]<<", "<<endl;
}
main()
{
vidu A;
A.nhap();
A.xuat();
A.cainayhay();//ch? này!
A.xuat();//k?t qu? khác!
system("pause");
}
