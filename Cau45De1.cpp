#include<iostream>

using namespace std;

class DTNT{
	protected:
		string ten;
		float luong;
	public:
		DTNT(string ="", float =.0f);
		~DTNT(){
		}
		virtual void nhap();
		virtual void xuat();
		virtual float thue(){
		}
};

DTNT::DTNT(string ten1, float luong1){
	ten = ten1;
	luong = luong1;
}

void DTNT::nhap(){
	fflush(stdin);
	cout << "Nhap ho ten: ";
	getline(cin, ten);
	cout << "Nhap luong hang thang: ";
	cin >> luong;
}

void DTNT::xuat(){
	cout << "Ho ten: " << ten << endl;
	cout << "Luong: " << luong << endl;
}

class CNVC:public DTNT{
	float phucap;
	public:
		CNVC(){
		}
		~CNVC(){
		}
		void nhap(){
			DTNT::nhap();
			cout << "Nhap phu cap: ";
			cin >> phucap; 
		}
		void xuat(){
			DTNT::xuat();
			cout << "Phu cap: " << phucap << endl;
		}
		float thue(){
			return (luong+phucap)*0.1;
		}
};

class DNTN:public DTNT{
	float chiphi;
	public:
		DNTN(){
		}
		~DNTN(){
		}
		void nhap(){
			DTNT::nhap();
			cout << "Nhap chi phi di lai: ";
			cin >> chiphi;
		}
		void xuat(){
			DTNT::xuat();
			cout << "Chi phi: " << chiphi << endl;
		}
		float thue(){
			return (luong+chiphi)*0.12;
		}
};

class DNNN:public DTNT{
	float thuong;
	public:
		DNNN(){
		}
		~DNNN(){
		}
		void nhap(){
			DTNT::nhap();
			cout << "Nhap thuong hang thang: ";
			cin >> thuong;
		}
		void xuat(){
			DTNT::xuat();
			cout << "Thuong hang thang: " << thuong <<endl;
		}
		float thue(){
			return (luong+thuong)*0.15;	
		}
};
int main()
{
	DTNT *dt[1000];
	int n, chon;
	cout << "Nhap so doi tuong chiu thue: ";
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cout << "Nhap cho doi tuong: cong nhan vien chuc (0), doanh nghiep trong nuoc (1), doanh nghiep nuocngoai (2): ";
		cin >> chon;
		if(chon == 0) dt[i] = new CNVC;
		else if(chon == 1) dt[i] = new DNTN;
		else dt[i] = new DNNN;
		dt[i]->nhap();
	}
	for(int i = 0 ; i < n ; i++)
	{
		dt[i]->xuat();
		cout << "Thue: " << dt[i]->thue() << endl;
	}
		
 	return 0;
}

