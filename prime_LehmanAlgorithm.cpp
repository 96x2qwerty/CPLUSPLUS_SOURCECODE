#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;
int main(){
	unsigned long N,a,Y1,Y;
	cout<<"Nhap N: ";cin>>N;
	for(int i=0;i<1000;i++){
		srand(time(NULL));
		a = rand()%(N/2-10+1)+10;
		Y1 = pow(a,(N-1)/2);
		Y = Y1 % N;
		if(Y!=1 && Y!=N-1){
			cout<<"N khong nguyen to !";
			return 0;
		}
	}
	cout << "N la nguyen to !";
}
