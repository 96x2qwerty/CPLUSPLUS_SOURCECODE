#include<iostream>
using namespace std;
class sinhvien{
	protected:
		char ten[30];
		int ma;
		float diem;
	public:
		void nhap();
		void in();
};
class svut:public sinhvien{
	protected:
		char kv[10];
		char xl[10];
	public:
		void nhap();
		void in();
};
void sinhvien::nhap(){
	cout<<"Nhap ten sinh vien: ";fflush(stdin);cin.getline(ten,30);
	cout<<"Nhap ma sinh vien: ";cin>>ma;
	cout<<"Nhap diem sinh vien: ";cin>>diem;   
}
void sinhvien::in(){
	cout<<"Ten sinh vien: ";cout<<ten<<endl;
	cout<<"Ma sinh vien: ";cout<<ma<<endl;
	cout<<"Diem sinh vien: ";cout<<diem<<endl;
}
void svut::nhap(){
	sinhvien::nhap();
	cout<<"Nhap khu vuc: ";fflush(stdin);cin.getline(kv,10);
	cout<<"Nhap xep loai: ";fflush(stdin);cin.getline(xl,10);  
}
void svut::in(){
	sinhvien::in();
	cout<<"Khu vuc: ";cout<<kv<<endl;
	cout<<"Xep loai: ";cout<<xl<<endl;
}
int main(){
	svut sv[100];
	int n;
	do{
		cout<<"Nhap so sinh vien: ";
		cin >> n;
	}while(n<0||n>100);
	for(int i=0;i<n;i++){
		cout<<"Nhap thong tin cho sinh vien thu "<<i<<":"<<endl;
		sv[i].nhap();
	}
	for(int i=0;i<n;i++){
		cout<<"Thong tin cua sinh vien thu "<<i<<":"<<endl;
		sv[i].in();
	}
}

