#include<iostream>
using namespace std;
class canhan{
	protected:
	char ten[30];
	int ns;
	char diachi[30];
	public:
		void nhap();
		void in();
};
class nhanvien:public canhan{
	float hsl;
	int nkhd;
	public:
		void nhap();
		void in();
		bool kiemtra(int nht);
};
void canhan::nhap(){
	cout<<"Nhap ho ten: ";
	fflush(stdin);
	cin.getline(ten,30);
	cout <<"Nhap nam sinh: ";
	cin >> ns;
	cout <<"Nhap dia chi: ";
	fflush(stdin);
	cin.getline(diachi,30);
}
void canhan::in(){
	cout<<"Ten: "<<ten<<endl<<"Nam sinh: "<<ns<<endl<<"Dia chi: "<<diachi<<endl;
}
void nhanvien::nhap(){
	canhan::nhap();
	cout<<"He so luong: ";cin>>hsl;
	cout<<"Nam ki hop dong: ";cin>>nkhd;
}
void nhanvien::in(){
	canhan::in();
	cout<<"He so luong: "<<hsl<<endl<<"Nam ki hop dong: "<<nkhd<<endl;
}
bool nhanvien::kiemtra(int nht){
	if((nht - nkhd)%3 == 0) return true;
	else return false;
}
int main(){
	nhanvien nv[10];
	int n;
	cout << "Nhap so luong nhan vien: "; cin >> n;
	for(int i=0;i<n;i++){
		cout<<"Nhap thong tin nhan vien thu "<<i<<endl;
		nv[i].nhap();
	}
	cout<<"Thong tin nhan vien vua nhap la: "<<endl;
	for(int i=0;i<n;i++){
		cout<<"Nhan vien thu "<<i<<endl;
		nv[i].in();
	}
	int nht;
	cout<<"Hay nhap nam hien tai: ";cin>>nht;
	cout<<"In cac nhan vien duoc len luong trong nam hien tai:"<<endl;
	for(int i=0;i<n;i++){
		if((nv[i].kiemtra(nht) == true))
			nv[i].in();
	}
}


