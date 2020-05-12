#include<iostream>
using namespace std;
class SV{
	private:
		string ten;
		int ma;
		float d1, d2, d3;
	public:
		SV(){
			ten="";
			ma=0;
			d1=d2=d3=0.0;
			}
			void nhap();
			void indl();
			float dtb(){
				return (d1+d2+d3)/3;
						};
			bool ktra();
		};
void SV::nhap(){
	cout<<"Nhap ten: ";
	cin>>ten;
	cout<<"Nhap ma: ";
	cin>>ma;
	cout<<"Nhap d1: ";
	cin>>d1;
	cout<<"Nhap d2: ";
	cin>>d2;
	cout<<"Nhap d3: ";
	cin>>d3;
	}

void SV::indl(){
	cout<<"Ho ten: "<<ten<<endl
	<<"Ma SV: "<<ma<<endl
	<<"Diem 1: "<<d1<<endl
	<<"Diem 2: "<<d2<<endl
	<<"Diem 3: "<<d3<<endl
	<<"Diem TB: "<<dtb()<<endl
	<<"Tinh trang thi lai: "<< ktra();
				}

bool SV::ktra(){
	return ((d1>=0 && d1<4) || (d2>=0 && d2<4) || (d3>=0 && d3<4));
				}

main(){
	SV a
}
