#include <iostream>  //khuon hinh khuon ham
using namespace std;
template<class T, class U> bool Dieukien(T a, U a0)
{
	if(a > a0) return true;
	else return false;
}

class Diemtongket_sinhvien
{
	string hoten;
	int msv;
	float diem_hoc_tap;
	public:
	Diemtongket_sinhvien(string ht, int masv, float d)
	{
		hoten = ht;
		msv = masv;
		diem_hoc_tap = d;
	}
    	bool operator>(float a0)
	{
		if(diem_hoc_tap > a0)
			return true;
		else
			return false;
	}
	void in()
	{
		cout<<"Sinh vien: "<<hoten.c_str()
			<<", diem hoc tap: "<<diem_hoc_tap<<endl;
	}
};

int main()
{
	Diemtongket_sinhvien dtksv("Nguyen Van A", 30681, 7.25);
	if(Dieukien(dtksv,7.0))
		dtksv.in();
	else
		cout<<"Sinh vien diem duoi 7"<<endl;
	return 0;
}


