#include<iostream>
#include<string>
using namespace std;
class hang_hoa{
	friend class cua_hang;
	string ten; 
	string hang;
	float g_ban, g_mua;
	float lai;
		
	public:
		hang_hoa(){
				ten ="";
				hang = "";
				g_ban = g_mua = lai = 0;
			}
	
};
class cua_hang{
	int spt;
	hang_hoa *a;
	public:
		cua_hang(){
			spt = 0;
			a = NULL;
		}
		cua_hang(int n);
		~cua_hang(){
			delete []a;
			spt = 0;	
		}
		void nhapdl();
		void indl();
		void tke_theo_hang(string t); // t la ten hang~ sp
		void sxep(); // sap xep ten theo ABC
};
cua_hang::cua_hang(int n){
		 	spt = n;
		 	a = new hang_hoa [n];
		}
void cua_hang::nhapdl(){
	for(int i=0 ; i < spt; i++ )
	{
		cout<<"Nhap ten san pham "<<i+1<<" : "; fflush(stdin); getline(cin,a[i].ten);
		cout<<"Nhap ten hang san xuat: "; fflush(stdin); getline(cin,a[i].hang);
		cout<<"Nhap gia mua: "; cin>>a[i].g_mua;
		cout<<"Nhap gia ban: "; cin>>a[i].g_ban;
		a[i].lai = a[i].g_ban - a[i].g_mua;
	}
}	

void cua_hang::indl(){
	for(int i=0; i< spt; i++)
	{
		cout<<endl;
		cout<<"Ten san pham: "<<a[i].ten<<endl;
		cout<<"Ten hang san xuat: "<<a[i].hang<<endl;
		cout<<"Gia mua: "<<a[i].g_mua<<endl;
		cout<<"Gia ban: "<<a[i].g_ban<<endl;
		cout<<"Lai: "<<a[i].lai<<endl;
		cout<<"============================="<<endl;
	}
}	

void cua_hang::tke_theo_hang(string t){
	cout<<"Cac sp cua hang "<<t<<" la :"<<endl;
	bool check = false;
	for(int i=0; i<spt; i++)
		if(a[i].hang  == t) 
		{
			this->indl();
			check = true;
		}	
	if(check == false ) cout<<" Khong co sp nao cua hang "<<t;
}	
void cua_hang::sxep(){
	hang_hoa x; 
	for(int i=0; i<spt-1; i++)
		for(int j= i+1; j<spt;j++)
		{
			if(a[i].ten > a[j].ten)
			{
				x=a[i]; a[i] = a[j]; a[j] = x;
			}	
			else if (a[j].ten == a[i].ten )
				if(a[j].lai > a[i].lai){
					x=a[i]; a[i] = a[j]; a[j] = x;
			}	
		}
	cout<<"DS sau khi sap xep la: "; 
	indl();
}	
main()
{
	cua_hang x(2);
	x.nhapdl();
	x.indl();
// thong ke 
	string m;
	cout<<"Nhap hang: "; fflush(stdin); getline(cin, m);
	x.tke_theo_hang(m);	
	x.sxep();
}


