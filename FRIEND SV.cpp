#include<iostream>
using namespace std;
class sinhvien{
	private:
		char *tenSV;
		char *maSV;
		char *khoa;
	public:
		friend void nhap(sinhvien s);
		char *getTen(){
			return tenSV;
		}
		char *getMasv(){
			return maSV;
		}
		char *getKhoa(){
			return khoa;
		}
};
void nhap(sinhvien s){
	cout <<"Nhap ten sinh vien: ";
	cin.getline(s.tenSV,50);
	cout << "Nhap ma sinh vien: ";
	cin >> s.maSV;
	cout << "Nhap khoa: ";
	cin.getline(s.khoa,50);
}
int main(){
	sinhvien s1;
	nhap(s1);
	cout << "Thong tin sinh vien da nhap la: "<<endl;
	cout << "Ten SV: " << s1.getTen() << endl;
	cout << "Ma SV: " << s1.getMasv() << endl;
	cout << "Khoa: " << s1.getKhoa() << endl;
	return 0;
}
