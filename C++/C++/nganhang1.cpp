//Gui tiet kiem ngan hang, co/ko thoi han
#include<iostream>
#include<string>
#include<time.h>
#include<conio.h>
using namespace std;
int system_day,system_month,system_year;
void giohethong(){

  time_t hientai;
  tm *ngay;
  hientai = time (NULL);
  ngay = localtime (& hientai );//Convert time_t ve tm
  system_day=ngay->tm_mday;
  system_month=ngay->tm_mon+1;
  system_year=ngay->tm_year+1900;
}
class date{
int d,m,y;
public:
date(){
d=system_day;
m=system_month;
y=system_year;
}
date(const date &p){
d=p.d;
m=p.m;
y=p.y;
}
friend istream& operator>>(istream &is,date &p);
friend ostream& operator<<(ostream &os,date &p);
friend int namnhuan(date);
friend int songaytrongthang(date);
friend date operator+(date ,int);
friend date operator+(int,date);
friend int operator-(date,date);
friend int hieuthang(date,date);
};
istream &operator>>(istream &is,date &p){
cout<<"Nhap ngay, thang, nam: ";
is>>p.d>>p.m>>p.y;
while(p.d>songaytrongthang(p) || p.m>=13 ||p.m<=0||p.y<=0||p.d<=0){
cout<<"Ngay,thang,nam khong dung, moi ban nhap lai ngay,thang,nam: ";
is>>p.d>>p.m>>p.y;
}
return is;
}
ostream &operator<<(ostream &os,date &p){
os<<p.d<<"/"<<p.m<<"/"<<p.y<<endl;
return os;
}
int namnhuan(date a){
if((a.y%4==0 && a.y%100!=0)||a.y%400==0)
return 366;
return 365;
}
int songaytrongthang(date a){
if(a.m!=2){
if(a.m<8)
{if(a.m%2==1) return 31; else return 30;}
else {if(a.m%2==1) return 30;else return 31;}
}
else if(namnhuan(a)==366)
return 29;
return 28;
}

date operator+(date a,int n){
a.d=a.d+n;
while (a.d>songaytrongthang(a))
{
a.d=a.d-songaytrongthang(a);
a.m=a.m+1;
if(a.m>12){
a.y=a.y+1;
a.m=a.m-12;
}
}
return a;
}
date operator+(int n,date a){
a.d=a.d+n;
while (a.d>songaytrongthang(a))
{
a.d=a.d-songaytrongthang(a);
a.m=a.m+1;
if(a.m>12){
a.y=a.y+1;
a.m=a.m-12;
}
}
return a;
}
void swap(date &a,date &b){
date tg;
tg=a;
a=b;
b=tg;
}
int operator-(date b,date a){
int kq,dem=0;
if(a.y>b.y)swap(a,b);
else if(a.y==b.y && a.m>b.m)swap(a,b);
else if(a.y==b.y && a.m==b.m && a.d>b.d)swap(a,b);
while(a.d!=b.d||a.m!=b.m||a.y!=b.y){
dem++;
a=a+1;
}
kq=dem;
return kq;
}
int hieuthang(date a,date b){
	int hieu;
	while(b.y!=a.y){
		b.m=b.m+12;
		b.y=b.y-1;
	}
	hieu=b.m-a.m;
	if(b.d<a.d)
	hieu=hieu-1;
	return hieu;
}
class sokokihan{
	protected:
	string maso,ten,cmt;
	float sotiengui;
	date ngaylapso;
	float laixuat;
	public:
	virtual void nhapso(){
		cout<<"Nhap ma so: ";
		getline(cin,maso);
		cout<<"Nhap so chung minh nguoi gui tien: ";
		getline(cin,cmt);
		cout<<"Nhap ho ten nguoi gui: ";
		getline(cin,ten);
		cout<<"Nhap so tien gui (trieu dong): ";
		cin>>sotiengui;cin.get();cout<<endl;
		cout<<"nhap lai xuat cua phieu: (%) ";
		cin>>laixuat;cin.get();
		cout<<"Nhap ngay lap so: ";
		cin>>ngaylapso;cin.get();
		cout<<"\n";
	}
	virtual int tienlai(){
		int n,tong;
		date ngayrut;
		//cout<<"Ngay hom nay: "<<ngayrut;
		n=hieuthang(ngaylapso,ngayrut);
		tong=(sotiengui*laixuat*n/100)*1000000;
		return tong;
		
	}
	 virtual void xuatso(){
		int t=tienlai();
		cout<<"Ma so: "<<maso<<"; So CMT: "<<cmt<<"; Ten: "<<ten<<"; So tien gui: "<<sotiengui<<endl;
		cout<<" So tien lai: "<<t<<" dong"<<endl;
	}
	
};
class socokihan :public sokokihan{
	date ngayhethan;
	public:
		void nhapso(){
			cout<<"Nhap ma so: ";
		getline(cin,maso);
		cout<<"Nhap so chung minh nguoi gui tien: ";
		getline(cin,cmt);
		cout<<"Nhap ho ten nguoi gui: ";
		getline(cin,ten);
		cout<<"Nhap so tien gui (trieu dong): ";
		cin>>sotiengui;cin.get();cout<<endl;
		cout<<"nhap lai xuat cua phieu: (%) ";
		cin>>laixuat;cin.get();
		cout<<"Nhap ngay lap so: ";
		cin>>ngaylapso;cin.get();
			cout<<"Nhap ngay het han: ";
			cin>>ngayhethan;cin.get();
			cout<<"\n";
		}
		
		int tienlai(){
			int tong,n;
			date ngayrut;
			n=hieuthang(ngaylapso,ngayhethan);
			if(ngayrut-ngaylapso < ngayhethan-ngaylapso)
			return 0;
			else
			tong = 	(sotiengui*laixuat*n/100)*1000000;
			return tong;
			
		}
		void xuatso(){	
		int t=tienlai();
		cout<<"Ma so: "<<maso<<"; So CMT: "<<cmt<<"; Ten: "<<ten<<"; So tien gui: "<<sotiengui<<endl;
		cout<<" So tien lai: "<<t<<" dong"<<endl;
		
		}
};
class nganhang;
class node{
sokokihan *infor;
node *link;
public:
friend class nganhang;
friend ostream &operator<<(ostream &os,nganhang &p);
};
class nganhang{
int spt;
node *head;
public:
nganhang(){
spt=0;
head=NULL;
}
friend istream &operator>>(istream &is,nganhang &p);
friend ostream &operator<<(ostream &os,nganhang &p);
bool empty();
void push_front(sokokihan *x);
void add();
void drop();
int tongphaitra();
};
bool nganhang::empty(){
return (spt==0);
}
void nganhang::push_front(sokokihan *x){
node *p=new node;
string capchar;
cout<<"Ban muon them vao loai so nao: ? (c=socokihan,k =sokokihan)";
getline(cin,capchar);
if(capchar=="c" || capchar=="C"){
p->infor=new socokihan;
x=new socokihan;
x->nhapso();
p->infor=x;
}
else {
p->infor=new sokokihan;
x=new sokokihan;
x->nhapso();
p->infor=x;
}
p->link=NULL;
if(!empty()){
p->link=head;
head=p;
}
else{
head=p;
}
spt++;
}
void nganhang::add(){
	int n;
	sokokihan a;
	cout<<"ban muon them bao nhieu so? ";
	cin>>n;cin.get();
	spt=spt+n;
	for(int i=1;i<=n;i++)
	push_front(&a);
}
void nganhang::drop(){
	node *p=head,*xoa;
	int n;
	if(empty())return;
	cout<<"Ban muon xoa so thu may?";
	cin>>n;cin.get();
	while(n==0 || n>spt) {
	cout<<"ban nhap lai so^' so cho dung";
	cin>>n;cin.get();
	}if(n==1){
		head=p->link;
		delete p;
	}
	else{
	for(int i=1;i<n-1;i++)
	{
		p=p->link;
	}
	xoa=p->link;
	p->link=xoa->link;

delete xoa;
}
	spt--;
}
int nganhang::tongphaitra(){
	int tong=0;
	node *t;
for(t=head;t!=NULL;t=t->link)
tong=tong+t->infor->tienlai();
return tong;
}
istream &operator>>(istream &is,nganhang &p){
int n,i;
cout<<"nhap so^' so: ";
cin>>n;cin.get();
string capchar;
sokokihan y;
for(int i=1;i<=n;i++)
p.push_front(&y);
return is;
}
ostream &operator<<(ostream &os,nganhang &p){
int i;
node *t;
for(t=p.head;t!=NULL;t=t->link){
	t->infor->xuatso();
	
}
return os;
}
int main(){
	giohethong();
	nganhang a;
	cin>>a;
	cout<<a;
	a.add();
	cout<<a;
	a.drop();
	cout<<a;
	cout<<endl;
	cout<<"Tien lai ngan hang phai tra: "<<a.tongphaitra();
	//system("pause");
	
}

