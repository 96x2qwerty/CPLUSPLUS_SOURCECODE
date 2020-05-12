// Trieu Than @Pro - Let's grow together!

#include<iostream>
#include<cstring>
using namespace std;

class Nguoi{
	private:
		char *name;
		char *addr;
		char *phone;
	public:
		Nguoi( char *na, char *ad, char *ph ): name(na), addr(ad), phone(ph){
//			name = na;
//			addr = ad;
//			phone = ph;
			cout<< "\nDoi tuong da duoc tao!";
		}
		char *getName(){
			return name;
		}
		
		char *getAddr(){
			return addr;
		}
		
		char *getPhone(){
			return phone;
		}
		friend void printName( Nguoi n );
		
};

void printName( Nguoi n ){
	cout<< "\nTen: " << n.getName();
	cout<< endl;
}

class SuperMan{
	friend class Nguoi;
	public:
		char *getName( Nguoi n ){
			return n.getName();
		}
		
		char *getAddr( Nguoi n ){
			return n.getAddr();
		}
		
		char *getPhone( Nguoi n ){
			return n.getPhone();
		}
};

int main(){
	char na[40], ad[40], ph[20];
	strcpy(na, "Tran Van Nam");
	strcpy(ad, "Ha Noi");
	strcpy(ph, "0948 1234 12");
	Nguoi n1(na, ad, ph);
	SuperMan s1;
	cout<< endl;
//	printName( n1 );
	cout<< "\nName: " << s1.getName( n1 ) << endl;
	cout<< "\nAddr: " << s1.getAddr(n1) << endl;
	cout<< "\nPhone: "<< s1.getPhone(n1) << endl;
	return 0;
}
