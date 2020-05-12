#include<iostream>
using namespace std;
class thisinh{
	char ten[30];
	float diem1,diem2,diem3;
	public:
		thisinh(){
		};
		thisinh(float d1,float d2,float d3){
			diem1 = d1;
			diem2 = d2;
			diem3 = d3;
		}
		friend istream&operator>>(istream&is,thisinh&q);
		friend ostream&operator<<(ostream&os,thisinh&q);
		float tong(){
			return (diem1+diem2+diem3);
		}
};
istream&operator>>(istream&is,thisinh&q){
	cout << "Nhap ten thi sinh: ";fflush(stdin);is.getline(q.ten,30);
	cout << "Nhap diem thi sinh: \n";
	cout << "Nhap diem 1: ";is>>q.diem1;
	cout << "Nhap diem 2: ";is>>q.diem2;
	cout << "Nhap diem 3: ";is>>q.diem3;
	return is;
}
ostream&operator<<(ostream&os,thisinh&q){
	os << "Ten thi sinh: ";os<<q.ten<<endl;
	os << "Diem 1: ";os<<q.diem1<<endl;
	os << "Diem 2: ";os<<q.diem2<<endl;
	os << "Diem 3: ";os<<q.diem3<<endl;
	os << "Tong diem 3 mon: "; os<<q.tong();
	return os;
}
int main(){
	thisinh t1;
	thisinh();
	thisinh(0,0,0);
	cin >> t1;
	cout << t1;
}
