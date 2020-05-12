#include<iostream>
using namespace std;
class HINH{
	public:
		virtual void nhap()=0;
		virtual void xuat()=0;
		virtual float Chuvi()=0;
		virtual float Dientich()=0;
};
class hcn:public HINH{
	float d, r;
	public:
		hcn(){
			d=r=0;
		}
		void nhap(){
			cin>>d>>r;
		}
		void xuat(){
			cout<<"Hinh chu nhat: "<<d<<" "<<r<<endl;
		}
		float Chuvi(){
			return (d+r)*2;
		}
		float Dientich(){
			return d*r;
		}
};

class htron:public HINH{
	float r;
	public:
		htron(){
			r=0;
		}
		void nhap(){
			cin>>r;
		}
		void xuat(){
			cout<<"Hinh tron: "<<r<<endl;
		}
		float Chuvi(){
			return 2*r*3.14;
		}
		float Dientich(){
			return r*r*3.14;
		}
};
main()
{
	htron a;
	a.nhap();
	a.xuat();
	cout<<a.Chuvi()<<" "<<a.Dientich();
}

