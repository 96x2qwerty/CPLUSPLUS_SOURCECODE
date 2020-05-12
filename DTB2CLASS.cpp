#include<iostream>
using namespace std;
class dathuc{
	private:
		int a,b,c;
	public: 
		dathuc();
		dathuc(int oa,int ob,int oc);
		float tinh(float x);
		dathuc(const dathuc &k);
		void in();
		~dathuc();
};
dathuc::dathuc(const dathuc &k){
	this -> a = k.a;
	this -> b = k.b;
	this -> c = k.c;
}
dathuc::dathuc(){
	a = b = c = 0;
}
dathuc::dathuc(int oa,int ob,int oc){
	a = oa;
	b = ob;
	c = oc;
}
dathuc::~dathuc(){
	cout << "Ham huy !" << endl;
}
float dathuc::tinh(float x){
	return a*x*x+b*x+c;
}
void dathuc::in(){
	cout << "a = " << a << " b = " << b << " c = " << c <<endl;
}
int main(){
	dathuc *p = new dathuc();
	dathuc q(3,4,5);
	dathuc r = q;
	cout << "Gia tri ham tao khong tham so: "; p -> in();
	cout <<"Gia tri ham tao 3 tham so: "; q.in();
	cout << "Gia tri ham tao sao chep: "; r.in();
	cout << "Gia tri da thuc khi x = 6 la : "<<q.tinh(6)<<endl;
}




