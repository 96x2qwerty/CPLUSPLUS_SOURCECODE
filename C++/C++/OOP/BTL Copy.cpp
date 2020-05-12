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
			hoten="";
			ngaysinh="";
			gioitinh="";
			tenlop="";
			khoa=0;
		}
	friend class Node;
	friend class DSSV;
};

class DSSV;
class DSSV
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
}

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
		void Remove_Head();
		void Add_Tail(SV d);
		void Add_VT(SV d, int vt);
		void Remove_VT(int vt);
		bool IsExist(int d);
		void Remove_MSV(int k);
		void Remove_Same();
		
}

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

void DSSV::Input_SV()
{
	cout<<"Nhap MSV: ";
	cin>>d.msv;
	cout<<"Nhap Ho Ten: ";
	cin.ignore();
	getline(cin, d.hoten);
	cout<<"Nhap Ngay Sinh: ";
	getline(cin, d.ngaysinh);
	cout<<"Nhap Gioi Tinh: ";
	getline(cin, d.gioitinh);
	cout<<"Nhap Ten Lop: ";
	getline(cin, d.tenlop);
	cout<<"Nhap Khoa: ";
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
{
	head=new Node(d, head);
	dem++;
}

void DSSV::Remove_Head()
{
	Node *head;
	if(p!=NULL)
	{
		head=head->next;
		delete p;
		dem--;
	}
}

void DSSV::Add_Tail(SV d)
{
	Node *p=head;
	Node *q= new Node(d, head);
	if(head==NULL)
	{
		head=q;
	}
	else
	{
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=q;
		q->next=NULL;
	}
	dem++;
}

void DSSV::Add_VT(SV d, int vt)
{
	Node *p=head;
	int i=1;
	if(vt<0 || vt>dem+1)
		cout<<"VT chen ko hop le!";
	else if(vt==1)
		Add_Head();
	else if(vt==0)
		{
			if(IsExist(d.msv)==false)
			Add_Tail(d);
		}
	else 
	{
		Node *q= new Node(d, head);
		while(p!=NULL && i!=vt-1)
		{
			i++;
			p=p->next;
		}
		q->next=p->next;
		p->next=q;
		dem++;
	}
}

void DSSV::Remove_VT(int vt)
{
	Node *p=head;
	int i=1;
	if(vt<1 || vt>dem)
		cout<<"Vi tri xoa khong hop le!"<<endl;
	else
	{
		if(vt==1) Remove_Head();
		else
		{
			while(p!=NULL && i!=vt-1)
			{
				p=p->next;
				i++;
			}
			p->next=p->next->next;
			dem--;
		}
		
	}
}

bool DSSV::IsExist(int d)
{
	for(Node *p=head; p!=NULL; p=p->next)
	{
		if(p->data.msv==d)
		return true;
	}
	return false;
}

void DSSV::Remove_MSV(int k)
{
	Node *p=head;
	Node *temp;
	if(head==NULL || IsExist(k)==false)
	{
		cout<<"Khong tim thay!";
	}
	else
	{
		if(p->data.msv==k)
		{
			head=p->next;
			delete p;
		}
		else
		{
			while(p!=NULL && p->data.msv!=k)
			{
				temp=p;
				p=p->next;
			}
			temp->next=p->next;
			delete p;
		}
		dem--;
	}
}

void DSSV::Remove_Same()
{
	Node *p=head;
	Node *q, *t;
	while (p!=NULL)
	{
		t=p;
		q=p->next;
		while(q!=NULL)
		{
			if(p->data.msv==p->data.msv)
			{
				Remove_MSV(p->data.msv)
				q=t->next;
			}
			else
			{
				t=q;
				q=q->next;
			}
		}
		p=p->next;
	}
}
