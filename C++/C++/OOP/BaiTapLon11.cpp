#include<iostream>
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
		void Add_Head(SV d);
		void Remove_Head();
		void Add_Tail(SV d);
		void Add_VT(SV d, int vt);
		void Remove_VT(int vt);
		bool IsExist(int d);
		void Remove_MSV(int k);
		void Remove_MSVSame(int vt);
		void Remove_Same();
		int Search_MSV(int mssv);
		int Search_Ten(string ten);
		int empty()const;
		void Printall();
		void Save_File();
		void Load_File();
		void Sort(string type);
};

DSSV::~DSSV() // Hàm huy Destructor
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

void DSSV::Input_SV(SV&d) // Nhâp thông tin cho 1 SV
{
	cout<<"Nhap MSV:       ";
	cin>>d.msv;
	cout<<"Nhap ho ten:    ";
	cin.ignore();
	getline(cin, d.hoten);
	cout<<"Nhap ngay sinh: ";
	getline(cin, d.ngaysinh);
	cout<<"Nhap gioi tinh: ";
	getline(cin, d.gioitinh);
	cout<<"Nhap ten lop:   ";
	getline(cin, d.tenlop);
	cout<<"Nhap khoa:      ";
	cin>>d.khoa;
}


void DSSV::Add_Head(SV d) // Chèn 1 SV vào dâu DS
{
	head=new Node(d, head);
	dem++;
}

void DSSV::Add_Tail(SV d) // Chèn 1 SV vào cuôi DS 
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
bool DSSV::IsExist(int d) // Kiem tra SV có mã SV d có ton tai trong DS hay không ?
{
	for(Node*p=head; p!=NULL; p=p->next)
	{
		if(p->data.msv==d)
			return true;
	}
	return false;
} 

void DSSV::Add_VT(SV d, int vt) // Chèn 1 SV vào vi trí bât ky trong DS
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

void DSSV::Remove_Head() // Xoa 1 SV o dau DS
{
	
	Node*p=head;
	if(p!=NULL)
	{
		head=head->next;
		delete p;
		dem--;
	}
}

void DSSV::Remove_MSV(int k) // Xoa 1 SV theo ma SV
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
void DSSV::Remove_VT(int vt) // Xoa 1 SV o vi tri bat ky vt
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
            dem--;
        }
    }
}



void DSSV::Remove_Same() // xóa các phân tu giông MSV trong DSSV -> Dam bao khong co 2 SV trung MSV;
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

int DSSV::Search_MSV(int mssv)// Tim kiem SV theo ma va tra ve VT cua Sv trong DS
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



void DSSV::Printall()//In ra DSSV hien tai
{
	cout<<"\nSo SV trong DS: "<<dem<<endl;
	for(Node*p=head;p!=NULL;p=p->next)
	{
		cout<<"MSV:            "<<p->data.msv<<endl
			<<"Ho Ten:         "<<p->data.hoten<<endl
			<<"Ngay Sinh:      "<<p->data.ngaysinh<<endl
			<<"Gioi Tinh:      "<<p->data.gioitinh<<endl
			<<"Ten Lop:        "<<p->data.tenlop<<endl
			<<"Khoa:           "<<p->data.khoa<<endl<<endl;
	}
}

void DSSV::Save_File()
{
	Node*p=head;
	ofstream fout1("filename.txt");
	fout1<<dem<<endl;
	for(p;p!=NULL;p=p->next)
	{
		fout1<<p->data.msv<<endl
			 <<p->data.hoten<<endl
			 <<p->data.ngaysinh<<endl
			 <<p->data.gioitinh<<endl
			 <<p->data.tenlop<<endl
			 <<p->data.khoa<<endl;
	}
	fout1.close();
}

void DSSV::Load_File()
{
Node*p=head;
	ifstream fin1("filename.txt");
	fin1>>dem;
	cout<<"\nSo SV trong DS: "<<dem<<endl;
	for(p;p!=NULL;p=p->next)
	{
		fin1>>p->data.msv;
		cout<<"MSV:            "<<p->data.msv<<endl;
		fin1.ignore();
		getline(fin1, p->data.hoten);
		cout<<"Ho Ten:         "<<p->data.hoten<<endl;
		getline(fin1,p->data.ngaysinh);
		cout<<"Ngay Sinh:      "<<p->data.ngaysinh<<endl;
		getline(fin1,p->data.gioitinh);
		cout<<"Gioi Tinh:      "<<p->data.gioitinh<<endl;
		getline(fin1,p->data.tenlop);
		cout<<"Ten Lop:        "<<p->data.tenlop<<endl;
		fin1>>p->data.khoa;
		cout<<"Khoa:           "<<p->data.khoa<<endl<<endl;	
	}
	fin1.close();
}

int DSSV::empty()const //Kiem tra DS rong !
{
return ((dem==0))?1:0; // su dung toan tu 3 ngoi ?:
}

void DSSV::Sort(string type)
{
	Node*p=head, *q;
	for(p;p->next!=NULL;p=p->next)
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
		<<"8: Thoat chuong trinh!"<<endl;
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
	}while(lua_chon!=9);
}


