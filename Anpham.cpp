#include <iostream>
#include<string.h>
using namespace std;
class anpham{
	protected:
		char ten[30];
		int ma;
		float gia;
	public:
		virtual void nhap();
		virtual void in();
		friend void timkiem(anpham a[],int n,char key[30]);
};
class ban_in:public anpham{
	protected:	
		char tacgia[30];
		char nhain[30];
		int sotrang;
	public:
		void nhap();
		void in();
};
class ban_so:public anpham{
	protected:
		int dungluong;
		int thoiluong;
	public:
		void nhap();
		void in();
};
void anpham::nhap(){
	cout<<"Nhap ten an pham: "; fflush(stdin);cin.getline(ten,30);
	cout<<"Nhap ma an pham: ";cin>>ma;
	cout<<"Nhap gia an pham: ";cin>>gia;
}
void anpham::in(){
	cout<<"Ten an pham: "<<ten<<endl;
	cout<<"Ma an pham: "<<ma<<endl;
	cout<<"Gia an pham: "<<gia<<endl;
}
void ban_in::nhap(){
	anpham::nhap();
	cout<<"Nhap tac gia: ";fflush(stdin);cin.getline(tacgia,30);
	cout<<"Nhap nha in: ";fflush(stdin);cin.getline(nhain,30);
	cout<<"Nhap so trang: ";cin>>sotrang;
}
void ban_in::in(){
	anpham::in();
	cout<<"Tac gia: ";cout<<tacgia<<endl;
	cout<<"Nha in: ";cout<<nhain<<endl;
	cout<<"So trang: ";cout<<sotrang<<endl;
}
void ban_so::nhap(){
	anpham::nhap();
	cout<<"Nhap dung luong: ";cin>>dungluong;
	cout<<"Nhap thoi luong: ";cin>>thoiluong;
}
void ban_so::in(){
	anpham::in();
	cout<<"Dung luong: ";cout<<dungluong;
	cout<<"Thoi luong: ";cout<<thoiluong;
}
void timkiem(anpham a[],int n,char key[30]){
	for(int i=0;i<n;i++){
		if(strcmp(a[i].ten, key) == 0) a[i].in();
		else cout <<"Khong tim thay an pham do !";
	}
}
int main(){
	anpham *x[1000];
	int chon;
	int n;
	cout<<"Nhap so doi tuong: ";
	cin >>n;
	for(int i=0;i<n;i++){
		cout << "Chon doi tuong nhap: (1: An pham; 2: Ban in; 3: Ban so: )";
		cin >> chon;
		if(chon == 1) x[i] = new anpham;
		if(chon == 2) x[i] = new ban_in;
		if(chon == 3) x[i] = new ban_so;
		x[i]->nhap();
		
	}
	for(int i=0;i<n;i++){
		cout<<"Doi tuong "<<i<<":"<<endl;
		x[i]->in();
	}
	return 0;
}

