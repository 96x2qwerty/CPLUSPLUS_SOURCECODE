#include<iostream>
#include<math.h>
using namespace std;
class Hinh{
	public:
		string loai;
		Hinh(string ll="")
		{
			loai=ll;
		}
		virtual float dien_tich()=0;
		virtual float chu_vi()=0;
};
class HinhVuong:public Hinh
{
	float a;
	public: 
	HinhVuong(string ll="Hinh Vuong", float canh=5):Hinh(ll)
	{
		a=canh;
	}
	void indl1()
	{
		cout<<"\nHinh: "<<loai<<endl
			<<"Chu Vi: "<<chu_vi()<<endl
			<<"Dien tich: "<<dien_tich()<<endl;
	}
	float dien_tich()
	{
		return pow(a, 2);
	}
	float chu_vi()
	{
		return 4*a;
	}
};
class HCN:public Hinh
{
	float dai, rong;
	public:
		HCN(string ll="Hinh chu nhat", float dd=0, float rr=0)
		{
			dai=dd;
			rong=rr;
		}
		float dien_tich()
		{
			return dai*rong;
		}
		float chu_vi()
		{
			return (dai+rong)*2;
		}
};
class TamGiac:public Hinh
{
	float a, b, c;
	public:
		TamGiac(string ll="Tam Giac", float c1=0, float c2=0, float c3=0)
		{
			a=c1;
			b=c2;
			c=c3;
		}
		float dien_tich()
		{
			float p=chu_vi()/2;
			return sqrt(p*(p-a)*(p-b)*(p-c));
		}
		float chu_vi()
		{
			return a+b+c;
		}
};
main(){
	HinhVuong a;
	a.indl1();
}
