#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<string>
#include<fstream>

using namespace std;

class Node;
class DSSV;
class SV
{
	int msv, khoa;
	string hoten, ngaysinh, gioitinh, tenlop;
	public:
		SV()
		{
			msv=0;
			khoa=0;
			hoten="";
			ngaysinh="";
			gioitinh="";
			tenlop="";
		}
		friend class DSSV;
		friend class Node;
};

class DSSV;
class Node
{
	SV data;
	Node *next;
	public:
		Node(SV dt, Node *next1)
		{
			data=dt;
			next=next1;
		}
		friend class DSSV;
};

class DSSV
{
	Node *head;
	int dem;
	public:
		DSSV()
		{
			dem=0;
			head=NULL;
		}
		~DSSV();
		void Input_SV(SV &d);
		int Count_SPT(int k);
		void Add_Head(SV d);
		void Add_Tail(SV d);
		void Add_VT(SV d, int vt);
		void Remove_Head();
		void Remove_VT(int vt);
		void Remove_MSV(int k);
		void Remove_Same();
		int Search_MSV(int mssv);
		int Search_Ten(string ten);
		int empty()const;
		bool IsExist(int d);
		void Printall();
		void Svae_File();
		void Load_File();
		void Sort(string type);
};

DSSV::~DSSV()
{
	Node *p=head;
	while(p!=NULL)
	{
		head=head->next;
		delete p;
		p=head;
	}
	dem=0;
}

void DSSV::Input_SV(SV &d)
{
	cout<<"Nhap MSV: ";
	cin>>d.msv;
	cout<<"Nhap ho ten: ";
	cin.ignore();
	getline(cin, d.hoten);
	cout<<"Nhap ngay sinh: ";
	getline(cin, d.ngaysinh);
	cout<<"Nhap gioi tinh: ";
	getline(cin, d.gioitinh);
	cout<<"Nhap ten lop: ";
	getline(cin, d.tenlop);
	cout<<"Nhap khoa: ";
	cin>>d.khoa;
}

int DSSV::Count_SPT(int k)
{
	int dem=0;
	int t=k;
	while(t!=0)
	{
		dem=dem+1;
		t=t/10;
	}
	return dem;
}

void DSSV::Add_Head(SV d)
