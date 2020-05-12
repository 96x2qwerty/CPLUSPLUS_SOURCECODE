#include<iostream>
using namespace std;
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

//void SV::indl()
//{
//	cout<<"\nTenSV: "<<ten<<endl
//		<<"MaSV: "<<ma<<endl
//		<<"GioiTinh: "<<gioitinh<<endl
//		<<"Diem: "<<diem<<endl;
//}

main()
{
	DSSV a;
	SV x;
	x+5;
	cout<<x;
	a.nhapds();

	cout<<"\n\nDanh sach SV vua nhap: ";
	a.xuatds();
}
