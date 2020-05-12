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
		friend istream& operator>>(istream&is,nhanvien&q);
		friend ostream& operator<<(ostream&os,nhanvien&q);
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
istream& operator>>(istream&is,nhanvien&q){
	cout<<"Nhap ho ten: ";
	fflush(stdin);
	is.getline(q.ten,30);
	cout <<"Nhap nam sinh: ";
	is >> q.ns;
	cout <<"Nhap dia chi: ";
	fflush(stdin);
	is.getline(q.diachi,30);
	cout<<"He so luong: ";is>>q.hsl;
	cout<<"Nam ki hop dong: ";is>>q.nkhd;
	return is;
}
ostream& operator<<(ostream&os,nhanvien&q){
	os<<"Ten: "<<q.ten<<endl<<"Nam sinh: "<<q.ns<<endl<<"Dia chi: "<<q.diachi<<endl;
	os<<"He so luong: "<<q.hsl<<endl<<"Nam ki hop dong: "<<q.nkhd<<endl;
	return os;
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
		cin >> nv[i];
	}
	cout<<"Thong tin nhan vien vua nhap la: "<<endl;
	for(int i=0;i<n;i++){
		cout<<"Nhan vien thu "<<i<<endl;
		cin >> nv[i];
	}
	int nht;
	cout<<"Hay nhap nam hien tai: ";cin>>nht;
	cout<<"In cac nhan vien duoc len luong trong nam hien tai:"<<endl;
	for(int i=0;i<n;i++){
		if((nv[i].kiemtra(nht) == true))
			cout<<nv[i];
	}
}
//friend istream& operator>>(istream&is,nhanvien&q);
//friend ostream& operator<<(ostream&os,nhanvien&q);
//cin.nv[i]


