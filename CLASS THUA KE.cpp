#include<iostream>
#include<string.h>
using namespace std;
class thisinh{
	protected:
		char ten[30];
		int ma;
		float diem;
	public:
		void nhap();
		void in();
};
class tsut:public thisinh{
	protected:
		char kv[30];
		float diemkv;
		float diemt;
	public:
		void nhap();
		void in();
		friend void tsmax(tsut a[],int n);
};
void thisinh::nhap(){
	cout<<"Nhap ten thi sinh: "; fflush(stdin); cin.getline(ten,30);
	cout<<"Nhap ma thi sinh: "; cin>>ma;
	cout<<"Nhap diem thi sinh: ";cin>>diem;
}
void thisinh::in(){
	cout<<"+ Ho ten thi sinh: "<<ten<<endl;
	cout<<"+ Ma thi sinh: "<<ma<<endl;
	cout<<"+ Diem thi sinh: "<<diem<<endl;
}
void tsut::nhap(){
	thisinh::nhap();
	cout<<"Nhap khu vuc (KV1,KV2,KV3): ";fflush(stdin);cin.getline(kv,30);
	if(strcmp(kv,"KV1") == 0) diemkv = 1;
	if(strcmp(kv,"KV2") == 0) diemkv = 0.5;
	if(strcmp(kv,"KV3") == 0) diemkv = 0;
	diemt = diem + diemkv;
}
void tsut::in(){
	thisinh::in();
	cout<<"+ Diem uu tien: "<<diemkv<<endl;
	cout<<"+ Diem tong (da tinh diem uu tien): "<<diemt<<endl;
}
void tsmax(tsut ts[],int n){
	float max = 0;
	int vt;
	cout<<"Thi sinh co diem cao nhat la: "<<endl;
	for(int i=0;i<n;i++){
		if (max<ts[i].diemt){
			vt = i;
		}
	}
	ts[vt].in();
}
int main(){
	tsut ts[100];
	int n;
	do{
		cout<<"Nhap so thi sinh: ";
		cin >> n;
	}while(n<0||n>100);
	for(int i=0;i<n;i++){
		cout<<"Nhap thong tin cho thi sinh thu "<<i<<":"<<endl;
		ts[i].nhap();
	}
	for(int i=0;i<n;i++){
		cout<<"Thi sinh thu "<<i<<":"<<endl;
		ts[i].in();
	}
	tsmax(ts,n);
}
