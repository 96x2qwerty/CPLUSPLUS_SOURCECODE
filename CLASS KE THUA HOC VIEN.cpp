#include <iostream>
using namespace std;
class hocvien{
	protected:
		char ten[30];
		int ns;
		char diachi[30];
	public:
		void nhap();
		void in();
};
class diemmh{
	protected:
		float X;
		float Y;
		float Z;
	public:
		void nhap();
		void in();
};
class sinhvien:public hocvien,public diemmh{
	char tenmh[30];
	public:
		void nhap();
		void in();
};
void hocvien::nhap(){
	cout<<"Nhap ho ten: ";
	fflush(stdin);
	cin.getline(ten,30);
	cout <<"Nhap nam sinh: ";
	cin >> ns;
	cout <<"Nhap dia chi: ";
	fflush(stdin);
	cin.getline(diachi,30);
}
void hocvien::in(){
	cout<<"Ten: "<<ten<<endl<<"Nam sinh: "<<ns<<endl<<"Dia chi: "<<diachi<<endl;
}
void diemmh::nhap(){
	cout<<"Nhap diem X: ";cin>>X;
	cout<<"Nhap diem Y: ";cin>>Y;
	Z = 0.5*X + 0.5*Y;
}
void diemmh::in(){
	cout<<"Diem X: "<<X<<endl;
	cout<<"Diem Y: "<<Y<<endl;
	cout<<"Diem Z: "<<Z<<endl;
}
void sinhvien::nhap(){
	hocvien::nhap();
	cout<<"Nhap ten mon hoc: ";
	cin.getline(tenmh,30);
	diemmh::nhap();
}
void sinhvien::in(){
	hocvien::in();
	cout<<"Ten mon hoc: "<<tenmh<<endl;
	diemmh::in();
}
int main(){
	sinhvien sv[10];
	int n;
	cout<<"Nhap so luong sinh vien: ";cin>>n;
	for(int i=0;i<n;i++){
		cout<<"Nhap thong tin cho sinh vien thu "<<i<<endl;
		sv[i].nhap();
	}
	cout<<"Thong tin cac sinh vien da nhap la: "<<endl;
	for(int i=0;i<n;i++){
		cout<<"Sinh vien thu "<<i<<":"<<endl;
		sv[i].in();
	}
}
	
