#include<iostream>
using namespace std;
class sohuuty{
	private:
		int tuso;
		int mauso;
	public:
		void nhap(int t = 0,int m = 1){
			tuso = t;
			mauso = m;
		}
		void in(){
			cout<<tuso<<"/"<<mauso<<endl;
		}
	friend class listsht;
};		

class listsht{
	sohuuty *sht;
	int n;
	public:
		void nhap();
		void in();
		void shtmax();
};
void listsht::nhap(){
	cout<<"Nhap so luong: ";cin>>n;
	sht = new sohuuty[n];
	int tuso,mauso;
	for(int i=0;i<n;i++){
		cout<< "Nhap so thu "<<i<<":"<<endl;
		cout<< "Nhap tu so: ";cin>>tuso;
		cout<< "Nhap mau so: ";cin>>mauso;
		sht[i]->nhap(tuso,mauso);
	}
}
void listsht::in(){
	for(int i=0;i<n;i++){
		cout<<"So thu "<<i<<":";
		sht[i].in();
	}
}
void listsht::shtmax(){
	float max = sht[0].tuso/sht[0].mauso;
	int k=0;
	for(int i=0;i<n;i++){
		if(sht[i].tuso/sht[i].mauso > max)
			k = i;
	}
	cout<<"So huu ty lon nhat la: "<<sht[k].tuso<<"/"<<sht[k].mauso;
}
int main(){
	listsht sht;
	sht.nhap();
	cout<<"Danh sach cac so huu ty da nhap la: "<<endl;
	sht.in();
	sht.shtmax();
	return 0;
}
