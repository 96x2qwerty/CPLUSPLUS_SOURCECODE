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
		friend PS operator+(PS a, int b);
		friend PS operator+(int a, PS b);
		
};
void PS::in(){
	cout<<ts<<"/"<<ms<<endl;
}
PS operator+(PS a, int b){
	PS c;
	c.ts = a.ts + b*a.ms;
	c.ms = a.ms;
	return c;
}
PS operator+(int a, PS b){
	PS c;
	c.ts = b.ts + a*b.ms;
	c.ms = b.ms;
	return c;
}
main()
{
	PS x(3,5),z;
	int y =6;
	z = y+x;
	z.in();
	return 0;
}


