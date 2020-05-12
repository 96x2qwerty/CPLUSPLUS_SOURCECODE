#include<iostream>
using namespace std;
template <class T> void sXep(T a[])
{
	for(int i=0; i<n; i++)
	for(int j=0; j<n; j++)
	if(a[i]>a[j])
	{
		T tam=a[i];
		a[i]=a[j];
		a[j]=tam;
	}
}
class SV{
	//ten, ma, gioi tinh, diem;
	string ten, ma, gioitinh;
	float diem;
	public :
		/*SV(){
			ten = "";
			ma= "";
			gioitinh = "";
			diem = 0;
			}//SV a;
		SV(string tt, string mm, string gt, float d)	
		{
			ten = tt;
			ma = mm;
			gioitinh = gt;
			diem = d;
		}// SV a("A", "123", "nam", 6.5)*/
		SV(string tt="A", string mm="123", string gt="nam", float d=6.5)
		{
			ten = tt;
			ma=mm;
			gioitinh=gt;
			diem=d;
				}
//		void indl();
//		void nhapdl()
//		{
//			cin.ignore();
//			cout<<"\nNhap Ten SV: ";
//			getline(cin, ten);
//			cout<<"\nNhap ma SV: ";
//			getline(cin, ma);
//			cout<<"\nNhap gioi tinh: ";
//			getline(cin, gioitinh);
//			cout<<"\nNhap diem: ";
//			cin>>diem;
//		}
		friend istream & operator>>(istream & is, SV &p);
		friend ostream & operator<<(ostream & os, SV &p);
		friend SV operator+(SV &p, int n);
};
 SV operator+(SV &p, int n){
			p.diem=p.diem + n;
			return p;
}
istream & operator>>(istream & is, SV &p)
{
	cin.ignore();
	cout<<"\nNhap Ten SV: ";
	getline(cin, p.ten);
	cout<<"\nNhap Ma SV: ";
	getline(cin, p.ma);
	cout<<"\nNhap Gioi Tinh: ";
	getline(cin, p.gioitinh);
	cout<<"\nNhap Diem: ";
	is>>p.diem;
	return is;
}
ostream & operator<<(ostream & os, SV &p)
{
	os<<"\nTen SV: "<<p.ten<<endl
		<<"Ma SV: "<<p.ma<<endl
		<<"Gioi Tinh: "<<p.gioitinh<<endl
		<<"Diem: "<<p.diem<<endl;
}

class DSSV{
	int sosv;
	SV *p;
	public:
		DSSV(int n=0)
		{
			sosv =n;
			p=new SV[sosv];
		}
		void nhapds()
		{
			cout<<"Nhap so SV: ";
			cin>>sosv;
			p=new SV[sosv];
			for(int i=0; i<sosv; i++)
				cin>>p[i];
		}
		void xuatds()
		{
			for(int i=0; i<sosv; i++)
			{
				cout<<p[i];
			}
		}
};
main(){
	int a[]={5,4,6,7,8};
	sXep<int>(a,5);
	for(int i=0; i<5; i++)
		cout<<a[i]<<", ";
	float b[]={5.5, 4.5, 3.2, 8.6, 7.6};
	sXep<int>(b,5);
	cout<<"\n";
	for(int i=0; i<5; i++)
		cout<<b[i]<<", ";
}
