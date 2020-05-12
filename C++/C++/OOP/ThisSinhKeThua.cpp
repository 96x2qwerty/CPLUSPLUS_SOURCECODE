#include<iostream>

using namespace std;

class TS
{
	string ten;
	int sbd;
	float dcs, dcn, dta;
	public:
		TS(string tt="", int ma=0, float d1=0, float d2=0, float d3=0)
		{
			ten=tt;
			sbd=ma;
			dcs=d1;
			dcn=d2;
			dta=d3;
		}
		float tong()
		{
			return dcs+dcn;
		}
		bool kt()
		{
			if(dta>=5.0 && dcn>=2.0 && tong()>=11)
				return true;
			else
				return false;
		}
		friend istream &operator >> (istream &in, TS &p);
		friend ostream &operator << (ostream &out, TS &p);
};

istream &operator >> (istream &is, TS &p)
{
	cout<<"Nhap ten: "; is>>p.ten;
	cout<<"Nhap SBD: "; is>>p.sbd;
	cout<<"Diem mon co so: "; is>>p.dcs;
	cout<<"Diem mon chuyen nganh: "; is>>p.dcn;
	cout<<"Diem tieng anh: "; is>>p.dta;
	return is;
}


ostream &operator << (ostream &os, TS &p)
{
	cout<<"Ten thi sinh: "<<p.ten<<endl
		<<"So bao danh: "<<p.sbd<<endl
		<<"Diem co so: "<<p.dcs<<endl
		<<"Diem chuyen nganh: "<<p.dcn<<endl
		<<"Diem tieng anh: "<<p.dta<<endl;
}

class TSUT
{
	int loai;
	float dut;
	TSUT(int lo=0, string tt="", int bd=0, )
}
