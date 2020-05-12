#include<iostream>
#include<conio.h>

using namespace std;

class DSLK;
class Node{
	float data;
	Node*next;
	public:
		Node(float dt, Node*next1){
			data=dt;
			next=next1;
		}
	friend class DSLK;
};

class DSLK{
	
	Node*head;
	Node*tail;
	int dem;
	public:
		DSLK(){ 
			head=tail=NULL;
			dem=0;
		}
		~DSLK();
		void Insert_Head(float d);
		void Delete_Head();
		void Insert_Tail(float d);
		void Delete(float k);
		bool IsExist(float d);
		void Delete_Tail();
		int empty() const;
		void printall();
};

DSLK::~DSLK(){
	Node*p=head;
	while(p!=NULL){
		head=head->next;
		delete p;
		p=head;
	}
}

void DSLK::Insert_Head(float d)
{
	head=new Node(d, head);
	dem++;
}

void DSLK::Insert_Tail(float d){
	Node*p=head;
	Node*q=new Node(d, head);
	if(head==NULL)
	{
		head=q;
	}
	else{
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next = q;
		q->next=NULL;
	}
	dem++;
}

bool DSLK::IsExist(float d)
{
	for(Node*p=head; p!=NULL; p=p->next)
	{
		if(p->data==d)
			return true;
	}
	return false;
 } 
void DSLK::Delete_Head(){
	
	Node*p=head;
	if(p!=NULL)
	{
		head=head->next;
		delete p;
		dem--;
	}
}

void DSLK::Delete_Tail()
{
	Node * q = head;
	Node * p;
		if(q)
		{
			p = q;
			if(q->next==NULL)
			head = NULL;
			while(q->next!=NULL)
			{
				p = q;
				q = q->next;
			}
			p->next = NULL;
			delete q;
			dem --;
		}
}

void DSLK::Delete(float k)
{
    Node *p=head;
    Node*temp;
    if(head==NULL||IsExist(k)==false)
    {
    	cout<<"Khong tim thay !";
	}
	else{
		if(p->data==k){
			head=p->next;
			delete p;
			dem--;
		}
		else{
			while(p!=NULL&&p->data!=k){
				temp=p;
				p=p->next;
			}
			temp->next=p->next;
			delete p;
			dem--;
		}
	}
}

void DSLK::printall(){
	for(Node*p=head; p!=NULL;p=p->next){
		cout<<p->data<<" ";
	}
	cout<<endl;
}

int DSLK::empty()const
{
return (dem==0)?1:0;
}


main()
{
	DSLK L;
	int lua_chon;
	cout<<"1: Chen dau DS"<<endl
	<<"2: Chen cuoi"<<endl
	<<"3: Xoa dau"<<endl
	<<"4: Xoa bat ky"<<endl
	<<"5: Xoa cuoi"<<endl
	<<"6: In DS"<<endl
	<<"7: Kiem tra DS rong"<<endl
	<<"8: Thoat"<<endl;
	do{
		cout<<"Ban chon: ";
		cin>>lua_chon;
	switch (lua_chon)
	{
		case 1:
		{
			float key;
			do{
				cout<<"Nhap pt chen dau: ";
				cin>>key;
				if(key!=0)
					L.Insert_Head(key);
			}while(key!=0);
			break;
		}
		case 2:
		{
			float key2;
			do{
				cout<<"Nhap pt chen cuoi: ";
				cin>>key2;
				if(key2!=0)
					L.Insert_Tail(key2);
			}while(key2!=0);
			break;
		}
		case 3:
		{
			L.Delete_Head();
			break;
		}
		case 4:
		{
			float k;
			cout<<"Nhap k= ";
			cin>>k;
			L.Delete(k); 
			break;
		}
		case 5:
		{
			L.Delete_Tail();
			break;
		}
		case 6:
		{
			L.printall();
			break;
		}
		case 7:
		{
			if(L.empty()==1)
				cout<<"DS rong!"<<endl;
			else
				cout<<"DS khong rong !"<<endl;
		}
		case 8: break;
	}
	}while(lua_chon!=8);
}
