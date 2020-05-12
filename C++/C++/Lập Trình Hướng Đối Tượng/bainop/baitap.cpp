#include<iostream>
#include<cstring>
#include<stdio.h>
#include<fstream>
#include<conio.h>
#include<stdlib.h>

using namespace std;
class Khudat
{
	protected:
		char dd[100];
		int gb;
	private:
		int dt;
	public:
		Khudat(char *dd = NULL, int = 0, int = 0);
		~Khudat(){}
		virtual int kiemtra(){
			return 1;
		}
		virtual void nhap();
		virtual void xuat();
		virtual void ghifile(char *tenfile);
		virtual void docfile(char *tenfile);
};
Khudat::Khudat(char *dd1, int gb1, int dt1)
{
	if(dd1!=NULL)
		strcpy(dd,dd1);
	else
		strcpy(dd," ");
	gb = gb1;
	dt = dt1;	
}
void Khudat::nhap()
{
	cout << "Nhap dia diem: ";
	fflush(stdin);
	cin.getline(dd,100);
	cout << "Nhap gia ban: ";
	cin >> gb;
	cout << "Nhap dien tich: ";
	cin >> dt;
}
void Khudat::xuat()
{
	cout << "Dia diem: " << dd << endl;
	cout << "Gia ban: " << gb << endl;
	cout << "Dien tich: " << dt << endl;
}

void Khudat::ghifile(char *tenfile)
{
	fstream f;
	f.open(tenfile, ios::app | ios::out);
	f << "Dia diem: " << dd << endl;
	f << "Gia ban: " << gb << endl;
	f << "Dien tich: " << dt << endl;
	f.close();
}
void Khudat::docfile(char *tenfile)
{
	fstream f;
	f.open(tenfile, ios::in);
	string line;
	while (!f.eof())
	{
		getline(f, line);
		cout << line << endl;
	}
	f.close();
}
class Canho: public Khudat
{
	protected:
		int dtxd;
	public:
		Canho(char *dd = NULL, int = 0, int = 0);
		~Canho(){}
		void nhap();
		void xuat();
		void ghifile(char *tenfile);
		void docfile(char *tenfile);	
};
Canho::Canho(char *dd1, int gb1, int dtxd1)
{
	if(dd1!=NULL)
		strcpy(dd,dd1);
	else
		strcpy(dd," ");
	gb = gb1;
	dtxd = dtxd1;
}
void Canho::nhap()
{
	cout << "Nhap dia diem: ";
	fflush(stdin);
	cin.getline(dd,100);
	cout << "Nhap gia ban: ";
	cin >> gb;
	cout << "Nhap dien tich xay dung: ";
	cin >> dtxd;
}
void Canho::xuat()
{
	cout << "Dia diem: " << dd << endl;
	cout << "Gia ban: " << gb << endl;
	cout << "Dien tich xay dung: " << dtxd << endl;
}
void Canho::ghifile(char *tenfile)
{
	fstream f;
	f.open(tenfile, ios::app | ios::out);
	f << "Dia diem: " << dd << endl;
	f << "Gia ban: " << gb << endl;
	f << "Dien tich xay dung: " << dtxd << endl;
	f.close();
}
void Canho::docfile(char *tenfile)
{
	Khudat::docfile(tenfile);
}
class Nhasanvuon: public Canho
{
	int dtsv;
	public:
		Nhasanvuon(char *dd = NULL, int = 0, int = 0, int = 0);
		~Nhasanvuon(){}
		int kiemtra(){
			return 2;
		}
		void nhap();
		void xuat();
		void ghifile(char *tenfile);
		void docfile(char *tenfile);				
};
Nhasanvuon::Nhasanvuon(char *dd1, int gb1, int dtxd1, int dtsv1):Canho(dd1, gb1, dtxd1)
{
	dtsv = dtsv1;
}
void Nhasanvuon::nhap()
{
	Canho::nhap();
	cout << "Nhap dien tich san vuon: ";
	cin >> dtsv;
}
void Nhasanvuon::xuat()
{
	Canho::xuat();
	cout << "Dien tich san vuon: " << dtsv << endl;
}
void Nhasanvuon::ghifile(char *tenfile)
{
	fstream f;
	f.open(tenfile, ios::app | ios::out);
	f << "Dia diem: " << dd << endl;
	f << "Gia ban: " << gb << endl;
	f << "Dien tich xay dung: " << dtxd << endl;
	f << "Dien tich san vuon: " << dtsv << endl;
	f.close();
}
void Nhasanvuon::docfile(char *tenfile)
{
	Canho::docfile(tenfile);
}
class Nhapho: public Canho
{
	int st;
	public:
		Nhapho(char *dd = NULL, int = 0, int = 0, int = 0);
		~Nhapho(){}
		int kiemtra(){
			return 3;
		}
		void nhap();
		void xuat();
		void ghifile(char *tenfile);
		void docfile(char *tenfile);
			
};
Nhapho::Nhapho(char *dd1, int gb1, int dtxd1, int st1):Canho(dd1, gb1, dtxd1)
{
	st = st1;
}
void Nhapho::nhap()
{
	Canho::nhap();
	cout << "Nhap so tang: ";
	cin >> st;
}
void Nhapho::xuat()
{
	Canho::xuat();
	cout << "So tang: " << st << endl;
}
void Nhapho::ghifile(char *tenfile)
{
	fstream f;
	f.open(tenfile, ios::app | ios::out);
	f << "Dia diem: " << dd << endl;
	f << "Gia ban: " << gb << endl;
	f << "Dien tich xay dung: " << dtxd << endl;
	f << "So tang: " << st << endl;
	f.close();
}
void Nhapho::docfile(char *tenfile)
{
	Canho::docfile(tenfile);
}
void menu()
{
	cout << "============================== CHUONG TRINH QUAN LI KHU DAT VA CAN HO ==============================";
	cout << "|                                    __________ MENU __________                                    |";
	cout << "|                                   |                          |                                   |";
	cout << "|                                   |       1. NHAP            |                                   |";
	cout << "|                                   |       2. HIEN THI        |                                   |";
	cout << "|                                   |       3. GHI FILE        |                                   |";
	cout << "|                                   |       4. DOC FILE        |                                   |";
	cout << "|                                   |                          |                                   |";
	cout << "|                                   |_________________ q. THOAT|                                   |";
	cout << "====================================================================================================";
}
void menunhap()
{
	cout << "============================== CHUONG TRINH QUAN LI KHU DAT VA CAN HO ==============================";
	cout << "|                                    __________ NHAP __________                                    |";
	cout << "|                                   |                          |                                   |";
	cout << "|                                   |      1. KHU DAT          |                                   |";
	cout << "|                                   |      2. NHA SAN VUON     |                                   |";
	cout << "|                                   |      3. NHA PHO          |                                   |";
	cout << "|                                   |                          |                                   |";
	cout << "|                                   |                          |                                   |";
	cout << "|                                   |b. TROLAI_________________|                                   |";
	cout << "====================================================================================================";
}
void menuxuat()
{
	cout << "============================== CHUONG TRINH QUAN LI KHU DAT VA CAN HO ==============================";
	cout << "|                                    __________ XUAT __________                                    |";
	cout << "|                                   |                          |                                   |";
	cout << "|                                   |      1. KHU DAT          |                                   |";
	cout << "|                                   |      2. NHA SAN VUON     |                                   |";
	cout << "|                                   |      3. NHA PHO          |                                   |";
	cout << "|                                   |      4. TAT CA           |                                   |";
	cout << "|                                   |                          |                                   |";
	cout << "|                                   |b. TROLAI_________________|                                   |";
	cout << "====================================================================================================";
}
void menughi()
{
	cout << "============================== CHUONG TRINH QUAN LI KHU DAT VA CAN HO ==============================";
	cout << "|                                    ________ GHI FILE ________                                    |";
	cout << "|                                   |                          |                                   |";
	cout << "|                                   |      1. KHU DAT          |                                   |";
	cout << "|                                   |      2. NHA SAN VUON     |                                   |";
	cout << "|                                   |      3. NHA PHO          |                                   |";
	cout << "|                                   |      4. TAT CA           |                                   |";
	cout << "|                                   |                          |                                   |";
	cout << "|                                   |b. TROLAI_________________|                                   |";
	cout << "====================================================================================================";
}
int main()
{
	Khudat *data[1000];
	menu();
	char chose1 = 0, chose2 = 0, chose3 = 0;
	int i = 0;
	while(chose1!='q')
	{
		chose1 = getch();
		switch(chose1)
		{
			case '1':
				system("cls");
				menunhap();
				while(chose2!='b')
				{
				chose2 = getch();
				switch(chose2)
				{
					case '1':
						data[i] = new Khudat();
						data[i]->nhap();
						i++;
						break;
					case '2':
						data[i] = new Nhasanvuon();
						data[i]->nhap();
						i++;
						break;
					case '3':
						data[i] = new Nhapho();
						data[i]->nhap();
						i++;
						break;		
				}
				}
				chose2 = 0;
				system("cls");
				menu();
				break;
			case '2':	
				system("cls");
				menuxuat();	
				while(chose3!='b')
				{
				chose3 = getch();
				switch(chose3)
				{
					case '1':
						system("cls");
						menuxuat();
						for(int j = 0; j<i; j++)
						{
							if(data[j]->kiemtra()==1)
							{
								data[j]->xuat();
							}
						}
						break;
					case '2':
						system("cls");
						menuxuat();
						for(int j = 0; j<i; j++)
						{
							if(data[j]->kiemtra()==2)
							{
								data[j]->xuat();
							}
						}
						break;
					case '3':
						system("cls");
						menuxuat();
						for(int j = 0; j<i; j++)
						{
							if(data[j]->kiemtra()==3)
							{
								data[j]->xuat();
							}
						}
						break;
					case '4':
						system("cls");
						menuxuat();
						for(int j = 0; j<i; j++)
						{
								data[j]->xuat();
						}
						break;	
				}
				}
			chose3 = 0;
				system("cls");
				menu();
				break;
		}
}
}
