#include<iostream>
#include<string.h>
using namespace std;
class thisinh{
	protected:
		char ten[30];
		int ma;
		float diem;
};
class tsut:public thisinh{
		char kv[30];
		float diemkv;
		float diemt;
	public:
		friend istream&operator>>(istream&is,tsut&q);
		friend ostream&operator<<(ostream&os,tsut&q);		
};
istream& operator>>(istream&is,tsut&q){
	cout<<"Nhap ten thi sinh: "; fflush(stdin); is.getline(q.ten,30);
	cout<<"Nhap ma thi sinh: "; is>>q.ma;
	cout<<"Nhap diem thi sinh: ";is>>q.diem;
	cout<<"Nhap khu vuc (KV1,KV2,KV3): ";fflush(stdin);is.getline(q.kv,30);
	if(strcmp(q.kv,"KV1") == 0) q.diemkv = 1;
	if(strcmp(q.kv,"KV2") == 0) q.diemkv = 0.5;
	if(strcmp(q.kv,"KV3") == 0) q.diemkv = 0;
	q.diemt = q.diem + q.diemkv;
	return is;
}
ostream&operator<<(ostream&os,tsut&q){
	os<<"Ho ten thi sinh: "<<q.ten<<endl;
	os<<"Ma thi sinh: "<<q.ma<<endl;
	os<<"Diem thi sinh: "<<q.diem<<endl;
	os<<"Diem uu tien: "<<q.diemkv<<endl;
	os<<"Diem tong (da tinh diem uu tien): "<<q.diemt<<endl;
	return os;
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
		cin>>ts[i];
	}
	for(int i=0;i<n;i++){
		cout<<"Thi sinh thu "<<i<<":"<<endl;
		cout<<ts[i];
	}
}
