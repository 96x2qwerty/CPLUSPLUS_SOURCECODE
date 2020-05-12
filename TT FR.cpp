#include<iostream>
#include<cstring>
using namespace std;

class sinhvien{
	public:
		char ten[50];
		char masv[50];
		char khoa[50];
		friend void nhap( sinhvien s );
		
};

void nhap( sinhvien s ){
	cout <<"Nhap ten sinh vien: ";
	cin.getline(s.ten,50);
	cout << "Nhap ma sinh vien: ";
	cin >> s.masv;
	cout << "Nhap khoa: ";
	cin >> s.khoa;
}

int main(){
	sinhvien s1;
	nhap(s1);
	cout << "\nThong tin sinh vien da nhap la: "<<endl;
	cout << "Ten SV: " << s1.ten << endl;
	cout << "Ma SV: " << s1.masv << endl;
	cout << "Khoa: " << s1.khoa << endl;
	cout<< endl;
	return 0;
}
