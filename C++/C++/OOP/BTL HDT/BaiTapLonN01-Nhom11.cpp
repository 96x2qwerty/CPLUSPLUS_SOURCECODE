#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<string>
#include<fstream>

using namespace std;

bool KTraChuoi(string s){
	if(s=="")
		return false;
	int do_dai=s.length();
	for(int i=0; i<do_dai;i++)
	{
		if((s[i]<'A'||(s[i]>'Z'&&s[i]<'a')||s[i]>'z')&&s[i]!=' ')
			return false;
	}
	return true;
}
//==================================================================
bool KTNgaySinh(string s)
{
	if(s=="")
		return false;
	int do_dai=s.length();
	for(int i=0;i<do_dai;i++){
		if((s[i]<'0'||s[i]>'9'||s[i]==' ')&&s[i]!='/')
			return false;                                                                                               
	}
	return true;
}
//==================================================================
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
//==================================================================
class DSSV;
class Node
{
	SV data;
	Node*next;
	public:
		Node(SV dt, Node*next1)
		{
			data=dt;
			next=next1;
		}
	friend class DSSV;
};
//==================================================================
class DSSV
{
	Node*head;
	int dem;
	public:
		DSSV()
		{ 	
			dem=0;
			head=NULL;
		}
		~DSSV();
		void Input_SV(SV&d);
		int Count_SPT(int k);
		void Add_Head(SV d);
		void Remove_Head();
		void Add_Tail(SV d);
		void Add_VT(SV d, int vt);
		void Remove_VT(int vt);
		bool IsExist(int d);
		void Remove_MSV(int k);
		void Remove_Same();
		int Search_MSV(int mssv);
		int Search_Ten(string ten);
		int empty()const;
		void Printall();
		void Save_File();
		void Load_File();
		void Sort(string type);
};
//Huy tu============================================================
DSSV::~DSSV()
{
	Node*p=head;
	while(p!=NULL)
	{
		head=head->next;
		delete p;
		p=head;
	}
	dem=0;
}
//Nhap==============================================================
void DSSV::Input_SV(SV&d)
{
	nhap1:
	cout<<"Nhap MSV:       ";
	cin>>d.msv;
	if(d.msv<0)
	{
		cout<<"Nhap sai MSV. Moi nhap lai!"<<endl;
		goto nhap1;
	}
	nhap2:
	cout<<"Nhap ho ten:    ";
	cin.ignore();
	getline(cin, d.hoten);
	if(KTraChuoi(d.hoten)==false)
	{
		cout<<"Nhap sai Ho Ten. Moi nhap lai!"<<endl;
		goto nhap2;
	}
	nhap3:
	cout<<"Nhap ngay sinh: ";
	getline(cin, d.ngaysinh);
	if(KTNgaySinh(d.ngaysinh)==false)
	{
		cout<<"Nhap sai ngay sinh. Moi nhap lai!"<<endl;
		goto nhap3;
	}
	nhap4:
	cout<<"Nhap gioi tinh: ";
	getline(cin, d.gioitinh);
	if(KTraChuoi(d.gioitinh)==false)
	{
		cout<<"Nhap sai gioi tinh. Moi nhap lai!"<<endl;
		goto nhap4;
	}
	nhap5:
	cout<<"Nhap ten lop:   ";
	getline(cin, d.tenlop);
	nhap6:
	string s2;
	cout<<"Nhap khoa:      ";
	cin>>d.khoa;
	if(d.khoa<0)
	{
		cout<<"Nhap sai khoa. Moi nhap lai!"<<endl;
		goto nhap6;
	}
}
//kiem tra spt======================================================
int DSSV::Count_SPT(int k)
{
	int dem=0;
	int t=k;
	while (t!=0)
	{
		dem=dem+1;
		t=t/10;
	}
	return dem;
}
//Them dau==========================================================
void DSSV::Add_Head(SV d)
{
	head=new Node(d, head);
	dem++;
}
//them cuoi=========================================================
void DSSV::Add_Tail(SV d)
{
	Node*p=head;
	Node*q=new Node(d, head);
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
		p->next = q;
		q->next=NULL;
	}
	dem++;
}
//kiem tra ton tai==================================================
bool DSSV::IsExist(int d)
{
	for(Node*p=head; p!=NULL; p=p->next)
	{
		if(p->data.msv==d)
			return true;
	}
	return false;
} 
//them vao vi tri===================================================
void DSSV::Add_VT(SV d, int vt)
{
	Node*p=head;
	int i=1;
	if(vt<0||vt>dem+1)
		cout<<"VT chen k hop le !";
	else if(vt==1) 
		Add_Head(d);
	else if(vt==0)
		{
			if(IsExist(d.msv)==false)
			Add_Tail(d);
		}	
	else
	{
		Node*q=new Node(d, head);
		while(p!=NULL&&i!=vt-1)
		{
			i++;
			p=p->next;
		}
		q->next=p->next;
		p->next=q;
		dem++;
	}
}
//xoa dau===========================================================
void DSSV::Remove_Head()
{
	
	Node*p=head;
	if(p!=NULL)
	{
		head=head->next;
		delete p;
		dem--;
	}
}
//xoa theo msv======================================================
void DSSV::Remove_MSV(int k)
{
    Node *p=head;
    Node*temp;
    if(head==NULL||IsExist(k)==false)
    {
    	cout<<"Khong tim thay !";
	}
	else
	{
		if(p->data.msv==k)
		{
			head=p->next;
			delete p;
		}
		else{
			while(p!=NULL&&p->data.msv!=k)
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
//xoa theeo vi tri==============================================
void DSSV::Remove_VT(int vt)
{
    Node *p=head;
    int i=1;
    if (vt<1 || vt>dem)
		cout<<"Vi tri xoa khong hop le !"<<endl;
    else
    {
        if (vt==1) Remove_Head();
        else
        {
            while (p != NULL && i != vt-1)
            {
                p=p->next;
                i++;
            }
            p->next = p->next->next;
    		delete p->next;
            dem--;
        }
    }
}
//xoa cac phan tu trung msv===========================================
void DSSV::Remove_Same()
{ 
	Node*p=head;
	Node*q, *t;
	while(p!=NULL) 
    { 
        t=p; 
        q=p->next; 
        while(q!=NULL) 
        { 
            if(q->data.msv==p->data.msv) 
            {  
                Remove_MSV(p->data.msv);
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
//tìm theo msv======================================================
int DSSV::Search_MSV(int mssv)
{
	Node*p=head;
	int i=1;
	while(p!=NULL&&p->data.msv!=mssv)
	{
		p=p->next;
		i++;
	}
	if(p!=NULL) 
		return i;
	else 
		return 0;
} 
//tim theo ten======================================================
int DSSV::Search_Ten(string ten_tk)
{
	
	Node*p=head;
	int i=1;
	while(p!=NULL&&p->data.hoten!=ten_tk)
	{
		p=p->next;
		i++;
	}
	if(p!=NULL) 
		return i;
	else
		return 0;	
}
//in danh sach======================================================
void DSSV::Printall()
{
	cout<<"\n  ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿"
		<<"\n  ³So SV trong DS: "<<dem<<setw(16-Count_SPT(dem))<<"³"
		<<"\n  ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ";
	int i=1;
	for(Node*p=head;p!=NULL;p=p->next)
	{
		cout<<"\n  ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿"
			<<"\n  ³Sinh Vien "<<i<<setw(22-Count_SPT(i))<<"³"
			<<"\n  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´"
			<<"\n  ³MSV: "<<p->data.msv<<setw(27-Count_SPT(p->data.msv))<<"³"
			<<"\n  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´"
			<<"\n  ³Ho Ten: "<<p->data.hoten<<setw(24-(p->data.hoten.size()))<<"³"
			<<"\n  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´"
			<<"\n  ³Ngay Sinh: "<<p->data.ngaysinh<<setw(21-(p->data.ngaysinh.size()))<<"³"
			<<"\n  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´"
			<<"\n  ³Gioi Tinh: "<<p->data.gioitinh<<setw(21-(p->data.gioitinh.size()))<<"³"
			<<"\n  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´"
			<<"\n  ³Lop: "<<p->data.tenlop<<setw(27-(p->data.tenlop.size()))<<"³"
			<<"\n  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´"
			<<"\n  ³Khoa: "<<p->data.khoa<<setw(26-Count_SPT(p->data.khoa))<<"³"
			<<"\n  ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ";
		i++;
	}
}
//luu file===========================================================
void DSSV::Save_File()
{
	ofstream fout1("sinhvien.txt");
	fout1<<dem<<endl;
	int i=1;
	for(Node*p=head;p!=NULL;p=p->next)
	{
		fout1<<i<<endl
			 <<p->data.msv<<endl
			 <<p->data.hoten<<endl
			 <<p->data.ngaysinh<<endl
			 <<p->data.gioitinh<<endl
			 <<p->data.tenlop<<endl
			 <<p->data.khoa<<endl;
		i++;
	}
	fout1.close();
}
//cap nhat file=====================================================
void DSSV::Load_File()
{
	ifstream fin1("sinhvien.txt");
	fin1>>dem;
	cout<<"\n  ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿"
		<<"\n  ³So SV trong DS: "<<dem<<setw(16-Count_SPT(dem)+1)<<"³"
		<<"\n  ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ";
	int i;
	for(Node*p=head;p!=NULL;p=p->next)
	{
		fin1>>i;
		cout<<"\n  ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿"
			<<"\n  ³Sinh Vien "<<i<<setw(22-Count_SPT(i))<<"³"
			<<"\n  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´";
		fin1>>p->data.msv;
		cout<<"\n  ³MSV: "<<p->data.msv<<setw(27-Count_SPT(p->data.msv))<<"³"
			<<"\n  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´";
		fin1.ignore();
		getline(fin1, p->data.hoten);
		cout<<"\n  ³Ho Ten: "<<p->data.hoten<<setw(24-(p->data.hoten.size()))<<"³"
			<<"\n  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´";
		getline(fin1,p->data.ngaysinh);
		cout<<"\n  ³Ngay Sinh: "<<p->data.ngaysinh<<setw(21-(p->data.ngaysinh.size()))<<"³"
			<<"\n  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´";
		getline(fin1,p->data.gioitinh);
		cout<<"\n  ³Gioi Tinh: "<<p->data.gioitinh<<setw(21-(p->data.gioitinh.size()))<<"³"
			<<"\n  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´";
		getline(fin1,p->data.tenlop);
		cout<<"\n  ³Lop: "<<p->data.tenlop<<setw(27-(p->data.tenlop.size()))<<"³"
			<<"\n  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´";
		fin1>>p->data.khoa;
		cout<<"\n  ³Khoa: "<<p->data.khoa<<setw(26-Count_SPT(p->data.khoa))<<"³"
			<<"\n  ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ";
	}
	fin1.close();
}
//kiem tra phan tu co ton tai trong ds khong=======================
int DSSV::empty()const
{
return ((dem==0))?1:0;
}
//sap xep theo kiêu(id, ten)=======================================
void DSSV::Sort(string type)
{
	Node*p=head, *q;
	for(p;p!=NULL;p=p->next)
		for(q=p->next;q!=NULL;q=q->next)
		{
			if((type=="ID"||type=="id")&&p->data.msv>q->data.msv)
			{
				SV temp=p->data;
				p->data=q->data;
				q->data=temp;
			}
			else if((type=="NAME"||type=="name")&&p->data.hoten>q->data.hoten)
			{
				SV temp=p->data;
				p->data=q->data;
				q->data=temp;
			}
		}
}
//==================================================================

main()
{
SV a;
	DSSV L;
	int lua_chon;
	cout<<"1: Them 1 SV vao vi tri p bat ky trong DSSV (p=0: them vao cuoi DSSV)"<<endl
		<<"2: Loai bo 1 SV voi MSV cho truoc trong DSSV"<<endl
		<<"3: Loai bo 1 SV o vi tri p bat ky trong DSSV"<<endl
		<<"4: Tim kiem SV trong DSSV theo MSV hoac theo HOTEN"<<endl
		<<"5: In ra noi dung cua DSSV"<<endl
		<<"6: Luu noi dung cua DSSV vao file sinhvien.txt"<<endl
		<<"7: Load noi dung DSSV tu file sinhvien.txt"<<endl
		<<"8: Sap xep danh sach"<<endl
		<<"9: Thoat chuong trinh"<<endl;
	int n;
	cout<<"NHAP DSSV BAN DAU\n"<<endl;;
	cout<<"Nhap so SV ban dau cua DSSV: ";
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cout<<"\nNhap SV thu "<<i<<": \n\n";
		L.Input_SV(a);
		L.Add_Head(a);
	}
	cout<<"\nDANH SACH SINH VIEN BAN DAU\n";
	L.Remove_Same();
	L.Printall();
	do{
		cout<<"\nBan chon: ";
		cin>>lua_chon;
		switch (lua_chon)
		{
			case 1:
				int p;
				cout<<"Nhap vi tri can chen vao DSSV: ";
				cin>>p;
				L.Input_SV(a);
				L.Add_VT(a, p);
				break;
			case 2:
			{
				int k;
				cout<<"Nhap MSV can xoa khoi DSSV: ";
				cin>>k;
				L.Remove_MSV(k); 
				break;
			}
			case 3:
			{
				int vtri;
				cout<<"Nhap vi tri SV can xoa khoi DSSV: ";
				cin>>vtri;
				L.Remove_VT(vtri);
				break;
			}
			case 4:
			{
				int mssv;
				cout<<"Nhap MSV can tim: ";
				cin>>mssv;
				if(L.Search_MSV(mssv)!=0)
					cout<<"Tim thay SV co ma "<<mssv<<" tai vi tri "<<L.Search_MSV(mssv) << " trong DS"<<endl;
				else
				{
					string ten;
					cout<<"Nhap ten can tim kiem: ";
					cin.ignore();
					getline(cin, ten);
					if(L.Search_Ten(ten)!=0)
						cout<<"Tim thay SV co ten "<<ten<<" tai vi tri "<< L.Search_Ten(ten)<<" trong DS"<<endl;
					else
						cout<<"Khong tim thay SV co ten "<<ten<<" trong DS"<<endl;
				}
				break;
			}
			case 5:
			{
				if(L.empty()==0)
				{
					cout<<"\nDANH SACH SINH VIEN HIEN TAI\n";
					L.Remove_Same();
					L.Printall();
				}
				else
					cout<<"DSSV rong!";
				break;
			}
		
			case 6:
			{
				L.Save_File();
				break;
			}
		
			case 7:
			{	
				cout<<"\nDSSV LOAD RA TU FILE sinhvien.txt la: \n";
				L.Load_File();
				break;
			}
			case 8:
			{
				string type;
				cout<<"Nhap kieu muon sap xep: ";
				cin.ignore();
				getline(cin, type);
				L.Sort(type);
				L.Printall();
				break;
			}
			case 9:break;
		}
	}while(lua_chon>0&&lua_chon<10);
}


