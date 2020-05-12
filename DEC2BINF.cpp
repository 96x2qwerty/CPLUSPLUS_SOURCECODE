#include<iostream>
using namespace std;
void bin(int n){
	int a[100];
	int dem = 0;
	while(n > 0){
		a[dem] = n%2;
		n/=2;
		dem++;
	}
	for(int i=dem-1;i>=0;i--){
		cout << a[i];
	}
	
}
int main(){
	int n;
	cout<<"Nhap so can doi :";
	cin >> n;
	cout<<"Ket qua :";
	bin(n);
}
