#include<iostream>
#include<cstring>
using namespace std;
class sinhvien{
		char *tenSV;
		int maSV;
		char *khoa;
	public:
		char *getName();
		char *getKhoa();
		int getMaSV();
		friend void nhap(sinhvien s);
		
};
void nhap(sinhvien s){
	cout <<"Nhap ten sinh vien: ";
	cin.getline(s.tenSV,50);
	cout << "Nhap ma sinh vien: ";
	cin >> s.maSV;
	cout << "Nhap khoa: ";
	cin >> s.khoa;
}
char* sinhvien::getName(){
	return tenSV;
}
char* sinhvien::getKhoa(){
	return khoa;
}
int sinhvien::getMaSV(){
	return maSV;
}
int main(){
	sinhvien s1;
	nhap(s1);
	cout << "\nThong tin sinh vien da nhap la: "<<endl;
	cout << "Ten SV: " << s1.getName() << endl;
	cout << "Ma SV: " << s1.getMaSV() << endl;
	cout << "Khoa: " << s1.getKhoa() << endl;
	return 0;
}
