#include<iostream>
using namespace std;
class sinhvien{
	protected:
		char ten[30];
		int ma;
		float diem;
	public:
		friend istream&operator>>(istream&is,sinhvien&q);
		friend ostream&operator<<(ostream&os,sinhvien&q);
};
istream&operator>>(istream &is,sinhvien &q){
	cout<<"Nhap ten sinh vien: ";is>>q.ten;
	cout<<"Nhap ma sinh vien: ";is>>q.ma;
	cout<<"Nhap diem sinh vien: ";is>>q.diem;
}
ostream&operator<<(ostream &os,sinhvien &q){
	os<<"Ten sinh vien: ";os<<q.ten;
	os<<"Ma sinh vien: ";os<<q.ma;
	os<<"Diem sinh vien: ";os<<q.diem;
}
int main(){
	sinhvien sv[100];
	int n;
	do{
		cout << "Nhap so sinh vien: ";
		cin >> n;
	}while(n<0||n>100);
	for(int i=0;i<n;i++){
		cout << "Nhap thong tin cho sinh vien thu"<<i<<":"<<endl;
		cin >> sv[i];
	}
	for(int i=0;i<n;i++){
		cout << "Thong tin cua sinh vien thu"<<i<<":"<<endl;
		cout << sv[i];
	}
}
