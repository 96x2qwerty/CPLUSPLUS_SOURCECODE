#include<iostream>
#include<math.h>
using namespace std;
class timer{
	int gio, phut, giay;
	public:
		timer(){
			gio = phut = giay = 0;
		}
	void nhap();
	void in();
	friend bool operator>(timer a, timer b);
	friend bool operator<(timer a, timer b);
	friend bool operator==(timer a, timer b);
	friend int khoang_tg(timer a, timer b);
};

void timer::nhap(){
	cout<<"Nhap gio:"; cin>>gio;
	nhap_phut:
	cout<<"Nhap phut:"; cin>>phut;
	if(phut >= 60){
		cout<<"Nhap sai ( >= 60). Moi nhap lai\n"; goto nhap_phut;
	}
	nhap_giay:
	cout<<"Nhap giay:"; cin>>giay;
	if(giay >= 60){
		cout<<"Nhap sai ( >= 60). Moi nhap lai\n"; goto nhap_giay;
	}
	cout<<"____________________\n\n";
}
bool operator>(timer a, timer b){

	return  (a.gio*3600 + a.phut*60 + a.giay) > (b.gio*3600 + b.phut*60 + b.giay);

}
bool operator<(timer a, timer b){

	return  (a.gio*3600 + a.phut*60 + a.giay) < (b.gio*3600 + b.phut*60 + b.giay);

}
bool operator==(timer a, timer b){

	return  (a.gio*3600 + a.phut*60 + a.giay) == (b.gio*3600 + b.phut*60 + b.giay);

}
int khoang_tg(timer a, timer b){
	return abs((a.gio*3600 + a.phut*60 + a.giay) - (b.gio*3600 + b.phut*60 + b.giay));
}
main()
{
	timer a,b;
	a.nhap();
	b.nhap();
	if(a>b)	cout<<"a > b"<<endl;
	else if(a<b)cout<<"a < b "<<endl;
	else cout<<"a = b"<<endl;
	cout<<"Khoang thoi gian giua a va b la: "<<khoang_tg(a,b);
	return 0;
}


