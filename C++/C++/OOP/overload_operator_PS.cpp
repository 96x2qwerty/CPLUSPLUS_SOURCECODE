#include<iostream>
using namespace std;
class PS{
	int ts,ms;
	public: 
		PS(int n =1, int m=2){
			ts = n; ms = m;
		}
		void nhap();
		void in();
		friend PS operator*(PS a, PS b);
		friend PS operator/(PS a, PS b);
		
};
void PS::in(){
	cout<<ts<<"/"<<ms<<endl;
}
void PS::nhap(){
	cout<<"Nhap tu so: "; cin>>ts;
	cout<<"Nhap mau so: "; cin>>ms;
}

PS operator*(PS a , PS b){
	PS c;
	c.ts = a.ts*b.ts;
	c.ms = a.ms*b.ms;
	return c;
}

PS operator/(PS a, PS b){  // a/b
	PS c;
	c.ts = a.ts* b.ms;
	c.ms = a.ms * b.ts;
	return c;
}
main()
{
	PS x(2,3), y(3,5);
	PS z;
	z = x*y;
	z.in();
	z = x/y;
	z.in();
	return 0;
}


