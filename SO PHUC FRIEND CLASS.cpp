#include<iostream>
#include<math.h>
using namespace std;
class Sophuc
{
	int real, img;
	public:
	void nhap(int r = 0, int i = 0)
	{
		real = r; img = i;
	}
	void in()
	{
		cout<<real<<((img >= 0)?"+j":"-j")<<abs(img)<<endl;
	}
	friend class Daysophuc;
};

class Daysophuc
{
	Sophuc *Sp;
	int N;
	public:
	void nhap();
	void in();
	void tim_so_phuc_max();
};

void Daysophuc::nhap()
{
	cout<<"So luong: "; cin>>N;
	Sp = new Sophuc[N];
	int i, real, img;
	for(i=0; i<N; i++)
	{
		cout<<"So thu: "<<i+1<<endl;
		cout<<"Phan thuc: "; cin>>real;
		cout<<"Phan ao: "; cin>>img;
		Sp[i].nhap(real,img);
	}
}

void Daysophuc::tim_so_phuc_max()
{
    int i, k=0;
	float mag = Sp[k].real*Sp[k].real + Sp[k].img*Sp[k].img;
	for(i=1; i<N; i++)
	{
		if(mag < Sp[i].real*Sp[i].real + Sp[i].img*Sp[i].img)
		{
			mag = Sp[i].real*Sp[i].real + Sp[i].img*Sp[i].img;
			k = i;
		}
	}
	cout<<"So phuc max: "; Sp[k].in();
}

void Daysophuc::in()
{
	int i;
	for(i=0; i<N; i++)
	{
		cout<<"So thu: "<<i+1<<endl;
		Sp[i].in();
	}
}

int main()
{
	Daysophuc Daysp;
	Daysp.nhap();
	Daysp.in();
	Daysp.tim_so_phuc_max();
	return 0;
}

