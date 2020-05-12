#include<iostream>
using namespace std;
class sinhvien{
	public:
		char tenSV[50];
		int maSV;
		char khoa[50];
		void nhap();
};
void sinhvien::nhap(){
	cout <<"Nhap ten sinh vien: ";
	cin.getline(tenSV,50);
	cout << "Nhap ma sinh vien: ";
	cin >> maSV;
	cout << "Nhap khoa: ";
	cin.getline(khoa,50);
}
int main(){
	sinhvien s1;
	s1.nhap();
	cout << "Thong tin sinh vien da nhap la: "<<endl;
	cout << "Ten SV: " << s1.tenSV << endl;
	cout << "Ma SV: " << s1.maSV << endl;
	cout << "Khoa: " << s1.khoa << endl;
	return 0;
}
