//CLASS NHAP XUAT HOC VIEN 
#include<iostream>
#include<string.h>
using namespace std;
class hocvien{
	char ten[30];
	int masv;
	char nganh[30];
	float diemht;
	public:
		void nhap();
		void in();
		bool test();
		friend int hvhockha(hocvien a[],int n);
};
bool hocvien::test(){
	if(diemht <7.0 || strcmp(nganh,"CNT") !=0)
		return false;
	else
		return true;
}
void hocvien::nhap(){
	cout << "Nhap ten sinh vien: ";
	fflush(stdin);
	cin.getline(ten,30);
	cout << "Nhap ma sinh vien: ";
	cin >> masv;
	cout << "Nhap nganh hoc: ";
	cin >> nganh;
	cout << "Nhap diem hoc tap: ";
	cin >> diemht;
		
}
void hocvien::in(){
	cout << "Ten SV : " <<ten<<endl;
	cout << "Ma SV: " <<masv<<endl;
	cout << "Nganh: " <<nganh<<endl;
	cout << "Diem hoc tap: "<<diemht<<endl;
	cout <<"==============================="<<endl;
}
int hvhockha(hocvien a[],int n){
	int counter_cnt = 0,counter_kpm =0,counter_ttm = 0;
	int max = 0;
	for(int i=0;i<n;i++){
		if(a[i].diemht >=7.0 || strcmp(a[i].nganh,"CNT") ==0) counter_cnt ++;
		if(a[i].diemht >=7.0 || strcmp(a[i].nganh,"KPM") ==0) counter_kpm ++;
		if(a[i].diemht >=7.0 || strcmp(a[i].nganh,"TTM") ==0) counter_ttm ++;
		if (max<counter_cnt) max = counter_cnt;
		if (max<counter_kpm) max = counter_kpm;
		if (max<counter_ttm) max = counter_ttm;
	}
	if(max == counter_cnt) cout <<"CNT co nhieu hoc vien kha gioi nhat !";
	if(max == counter_kpm) cout <<"KPM co nhieu hoc vien kha gioi nhat !";
	if(max == counter_ttm) cout <<"TTM co nhieu hoc vien kha gioi nhat !";
	
}
int main(){
	hocvien a[100];
	int n;
	cout <<"Nhap so hoc vien: ";
	cin >> n;
	for(int i=0;i<n;i++){
		cout <<"Nhap thong tin cho hoc vien thu "<<i<<":"<<endl;
		a[i].nhap();
	}
	cout<<"Danh sach hoc vien kha gioi thuoc CNT da nhap la: "<<endl;
	for(int j=0;j<n;j++){
		if(a[j].test() == true){
			a[j].in();
		}
	}
	hvhockha(a,n);
	return 0;
}

