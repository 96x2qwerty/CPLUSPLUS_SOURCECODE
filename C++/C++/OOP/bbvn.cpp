#include<iostream>

using namespace std;

class Date{
	int ngay,thang,nam;
	public:
		Date(int d=0, int m=0, int y=0){
			ngay=d;
			thang=m;
			nam=y;
		}
		void SoNgayTrongThang(int a[13]);
		int KiemTraNgay();
		int KiemTraNam();
		int tinhngay(Date);
		Date operator++();
		Date operator++(int);
		bool operator>(Date b);
		Date operator+(int n);
		friend istream &operator>>(istream &is,Date&p);
		friend ostream &operator<<(ostream &os,Date&p);
};


istream&operator>>(istream&is,Date&p){
	cout<<"Nhap ngay-thang-nam: ";
	is>>p.ngay>>p.thang>>p.nam;
}

ostream&operator<<(ostream&os,Date&p){
	os<<p.ngay<<"/"<<p.thang<<"/"<<p.nam<<endl;
}

int Date::KiemTraNam()
{
	bool check;
    if(nam%400==0 || (nam%4==0 && nam%100!=0)){
        check=0;
    }
    else check=1;
    return check;
}

int Date::KiemTraNgay(){
	bool check;
    int a[13];
    SoNgayTrongThang(a);
    if(ngay<=a[thang] && ngay>0)
        check=1;
    else check=0;
    return check;
}

void Date::SoNgayTrongThang(int a[13]){
	int i;
    for(i=1;i<=12;i++){
        if(i<=7)
            if(i%2!=0) a[i]=31;
            else a[i]=30;
        if(i>=8)
            if(i%2==0) a[i]=31;
            else a[i]=30;
        if(i==2)
            if(KiemTraNam()==0) a[i]=29;
            else a[i]=28;
		}
}

Date Date::operator++(){
	int a[13];
    SoNgayTrongThang(a);
    if(ngay<a[thang]) ngay=ngay+1;
    if(ngay==a[thang]){
        ngay=1;        
        if(thang==12){
            ngay=1;
            thang=1;
            nam=nam+1;
        }else thang=thang+1;
    }
    return *this;
}

int Date::tinhngay(Date a)
{
	int dem1=0,dem2=0,dem3=0,dem4=0,dem5=0,dem6=0;
	for(int i=1;i<a.thang;i++)
	{
		if(i!=2&&((i<8&&i%2==1)||(i>=8&&i%2==0)))
			dem1++;
		else if(i!=2)
			dem2++;
		else if(i==2)
		{
			if(a.nam%400==0||(a.nam%4==0&&a.nam%100!=0))
				dem3++;
			else
				dem4++;
		}
	}
	int ngaythang=(dem1*31+dem2*30+dem3*29+dem4*28);
	for(int j=0;j<a.nam;j++)
	{
		if(j%400==0||(j%4==0&&j%100!=0))
			dem5++;
		else
			dem6++;
	}
	int ngaynam=(dem5*366+dem6*365);
	int tongngay=a.ngay+ngaythang+ngaynam;
	return tongngay;
}

bool Date::operator>(Date b){
	return (tinhngay(*this)>tinhngay(b));
}

Date Date::operator+(int n){
	int a[13];
    SoNgayTrongThang(a);
    if(ngay<a[thang]) ngay=ngay+n;
    if(ngay==a[thang]){
        ngay=1;        
        if(thang==12){
            ngay=1+(n-1);
            thang=1;
            nam=nam+1;
        }else thang=thang+1;
    }
    return *this;
}


main()
{
	Date a,b,c;
	cin>>a;
	cout<<"a= "<<a<<endl;
	Date d=++a;
	cout<<"d= "<<d<<endl;
	cin>>b;
	cout<<"b= "<<b<<endl;
	cin>>c;
	cout<<"c= "<<c<<endl;
	bool t=b>c;
	cout<<boolalpha<<t<<endl;
	Date e;
	cin>>e;
	cout<<"e= "<<e<<endl;
	Date f=e+2;
	cout<<"f= "<<f<<endl;
	
}
