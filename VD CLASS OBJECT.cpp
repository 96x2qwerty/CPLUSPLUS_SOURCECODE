//VI DU VE CLASS - OBJECT : TINH S,P HCN
#include<iostream>
#include<math.h>
using namespace std;
class Rectangle{
	private:
		float x1,y1,x2,y2,x3,y3,x4,y4;
	protected:
		float a,b,c,d;
	public:
		float dientich();
		float chuvi();
		void nhap();
};
void Rectangle::nhap(){
	cout << "Nhap toa do: "<<endl;
	cout << "x1 = " ; cin >> x1;
	cout << "y1 = " ; cin >> y1;
	cout << "x2 = " ; cin >> x2;
	cout << "y2 = " ; cin >> y2;
	cout << "x3 = " ; cin >> x3;
	cout << "y3 = " ; cin >> y3;
	cout << "x4 = " ; cin >> x4;
	cout << "y4 = " ; cin >> y4;
	a = sqrt(pow((x2-x1),2)+pow((y2-y1),2));
	b = sqrt(pow((x3-x2),2)+pow((y3-y2),2));
	c = sqrt(pow((x4-x3),2)+pow((y4-y3),2));
	d = sqrt(pow((x4-x1),2)+pow((y4-y1),2));
}
float Rectangle::chuvi(){
	return (a+b+c+d);
}
float Rectangle::dientich(){
	return (a*b);
}
int main(){
	Rectangle p;
	p.nhap();
	cout << "Chu vi hcn da nhap la: "<<p.chuvi()<<endl;
	cout << "Dien tich hcn da nhap la: "<<p.dientich()<<endl;
}

