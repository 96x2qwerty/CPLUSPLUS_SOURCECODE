#include<iostream>
#include<iomanip>
using namespace std;
class CMatrix
{
	int hang,cot;
	float **a;
	float * MangDong;
	public:
		CMatrix();
		CMatrix(int p, int q);
		CMatrix(CMatrix &x);
		~CMatrix();
		void nhap();
		void xuat();
		void dayso();
		void max();
		int ktrCong(CMatrix &x);
		int ktrNhan(CMatrix &x);
		friend CMatrix operator+(CMatrix a, CMatrix b);
		friend CMatrix operator*(CMatrix a, CMatrix b);		
};
void CMatrix::nhap(){
	cout<<"Nhap so hang: ";cin>>hang;
	cout<<"Nhap so cot: ";cin>>cot;
	a= new float *[hang];
	for (int i=0;i<hang;i++)
	a[i]= new float [cot];
	for (int i=0;i<hang;i++){
		for (int j=0;j<cot;j++)
		{
			cout<<"a["<<i<<j<<"]: ";
			cin>>a[i][j];
		}
	}
}
CMatrix::~CMatrix(){
	delete []MangDong;
	for (int i=0;i<hang;i++){
		delete a[i];
	}
	delete a;
}
CMatrix::CMatrix(CMatrix &x){
	hang=x.hang;
	cot=x.cot;
	MangDong = new float [hang*cot];
	a = new float *[hang];
	for(int i=0;i<hang;i++){
		a[i] = new float[cot];
	}
	for(int i=0;i<hang;i++){
		for(int j=0;j<cot;j++){
			a[i][j] = x.a[i][j];
		}
	}
}
CMatrix::CMatrix(int p, int q){
	hang=p;
	cot=q;
	MangDong = new float[hang * cot];
	a = new float *[hang];
	for(int i=0;i<hang;i++){
		a[i] = new float [cot];
	}
}
CMatrix::CMatrix(){
	MangDong = NULL;
	hang =0;
	cot  =0;
	a = new float *[hang];
	for(int i=0;i<hang;i++){
		a[i] = new float [cot];
	}
}
// xuat du lieu ra man hinh.
void CMatrix::xuat()
{
	for(int i=0;i<hang;i++){
		cout <<"|";
		for(int j=0;j<cot;j++){
			cout <<setw(5)<< a[i][j]<<" |";	
		}
		cout << endl;
	}	
}
void CMatrix::dayso()
{
	int t=0;
	MangDong = new float [hang*cot];
	for(int i=0;i<hang;i++){		
		for(int j=0;j<cot;j++){
			MangDong[t] = a[i][j];
			t++;
		}
	}
	for(int k=0;k<t;k++){
		cout <<MangDong[k]<<", ";
	}
}
void CMatrix::max()
{
	float Max;
	int i,j;
	Max = a[0][0];
	for(int i=0;i<hang;i++){
		for(int j=0;j<cot;j++){
			if(Max < a[i][j]){
				Max = a[i][j];
			}
		}
	}
	cout << "\nMax: " << Max << endl;
	cout<<"Vi tri cua Max la: ";
	for(i=0;i<hang;i++){
		for(j=0;j<cot;j++){
			if(Max == a[i][j]){
				cout<<"A["<<i<<"]["<<j<<"]"<<setw(5);
			}
		}
	}
}
// kiem tra 2 ma tran co CONG duoc voi nhau hay khong.
int CMatrix::ktrCong(CMatrix &x){
	if(hang == x.hang && cot == x.cot) return 1;
	return 0;
}
// kiem tra 2 ma tran co NHAN duoc voi nhau hay khong.
int CMatrix::ktrNhan(CMatrix &y){
	if(cot == y.hang) return 1;
	return 0;
}
// CONG 2 ma tran
CMatrix operator+(CMatrix d, CMatrix e){
	CMatrix c=d;
	for(int i=0;i<d.hang;i++){
		for(int j=0;j<d.cot;j++){
			c.a[i][j] = d.a[i][j] + e.a[i][j];
		}
	}
	return c;
}
// NHAN 2 ma tran
CMatrix operator*(CMatrix d, CMatrix e){
	CMatrix c;
	for(int i=0;i<d.hang;i++){
		for(int j=0;j<d.cot;j++){
			CMatrix c;
			for(int t=0;t<c.hang;t++){
				c.a[i][j] += d.a[i][t] * e.a[t][j];
			}
		}
	}
	return c;
}
// HAM chinh
int main()
{
	int Control;
	CMatrix d,e;
	cout << "                 *********************************************" << endl
		<<"                         *****************************   " << endl
		<< "               CHUONG TRINH NHAP VA TINH TOAN TREN MA TRAN NHOM 08" << endl
		<< "START" << endl;
		cout<<" 1. Nhap ma tran."<< endl
			<<" 2. In day so thuc trong ma tran." <<endl
			<<" 3. Tim Max cua ma tran." <<endl
			<<" 4. Cong 2 ma tran." <<endl
			<<" 5. Nhan 2 ma tran." <<endl
			<<" 6. Thoat." <<endl;
	do
		{
			cout << endl<<"---------------------------------" << endl
			     <<"Lua chon tinh nang cua chuong trinh: ";
			cin >> Control;
			switch(Control)
				{
					case 1:						
						{
							cout<< "Nhap ma tran D :" << endl;
							d.nhap();
							cout << "Ma tran ban vua nhap la:" << endl;		
							d.xuat();
							break;
						}
					case 2:
						{
							cout <<"Cac so thuc trong ma tran: "<< endl;
							d.dayso();
							break;
						}
					case 3:
						{
							d.max();
							break;
						}
					case 4:
						{
							cout<<"CHUONG TRINH CONG 2 MA TRAN!!!"<<endl;
							cout<<"Nhap ma tran E:"<<endl;
							e.nhap();
							if(d.ktrCong(e)==1){
								d.xuat();
								cout<<" + \n";
								e.xuat();
								cout<<" = \n";
								(d+e).xuat();
							}
							else cout<<"Hai ma tran khong cung cap!!!";
							break;
						}
					case 5:
						{	
							cout<<"CHUONG TRINH NHAN 2 MA TRAN!!!"<<endl;
							cout<<"Nhap ma tran E:"<<endl;
							e.nhap();
							if(d.ktrNhan(e) == 1){
								d.xuat();
								cout<<" * \n";
								e.xuat();
								cout<<" = \n";
								(d*e).xuat();
							}
							else cout<<"Khong the nhan 2 ma tran!!!";
							break;
						}
					case 6:
						{
							return 0;
							break;
						}
					default :
						{
							cout<<"<!> Khong tim thay lua chon cua ban ! Nhap lua chon tu 1 -> 7";
							break;
						}
				}
		}while(Control!=6);
	return 0;
}

