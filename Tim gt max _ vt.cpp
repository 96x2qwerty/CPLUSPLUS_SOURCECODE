#include <iostream>;
using namespace std;


int main(){
    int N , maxx;// Khai báo s? ph?n t? trong m?ng và maxx
    cin >> N; //Nh?p vào s? N
    int a[N];//M?ng a có N ph?n t? nh?p t? bàn phím

	for(int i = 0;i < N; i++){
		cout<<"Nhap phan tu thu "<<i+1<<" : ";
		cin>>a[i];
	}

    maxx = a[0];
	for(int i = 1; i < N; i++)
	if (maxx < a[i])
	{
		maxx = a[i];
	}
	cout<<"Gia tri lon nhat cua day a la: "<<maxx<< endl;
	cout<<"Cac vi tri cua max la: ";

	for(int i = 0;i < N; i++){
	if (a[i]==maxx)
	{
		cout<<i+1<<" ";
	}
	}
	return 0;
}
