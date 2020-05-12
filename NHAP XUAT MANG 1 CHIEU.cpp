#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
void nhapMang(int n,int a[]){
	for (int i=0;i<n;i++){
		cout << "Nhap phan tu thu " << i <<":";
		cin >> a[i];
	}
}
//---------------------------------------
void nhapMangrandom(int n,int a[]){
	srand(time(NULL));
	for (int i=0;i<n;i++){
		a[i] = rand()%100-1;
	}
}
//----------------------------------------
void inMang(int n,int a[]){
	cout << "Mang da nhap la: "<<endl;
	for (int i=0;i<n;i++){
		cout << a[i] << " ";
	}
}
//-----------------------------------------
int main(){
	int a[100];
	int n;
	do{
		cout << "Nhap so phan tu trong mang: ";
		cin >> n;
	}while (n<0 || n>100);
	nhapMang(n,a);
	//nhapMangrandom(n,a);
	inMang(n,a);
	return 0;
}
