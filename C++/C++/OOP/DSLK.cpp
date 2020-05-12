#include<iostream>

using namespace std;

class DSLK;
class Node{
	int data;
	Node*next;
	public:
		Node(int dt, Node*next1){
			data=dt;
			next=next1;
		}
		friend class DSLK;
};

class DSLK{
	Node *head;
	Node *tail;
	int dem;
	public:
		DSLK(){
			head=tail=NULL;
			dem=0;
		}
		~DSLK();
		void Insert_Head(int d);
		void Delete_Head();
		void Insert_Tail(int d);
		void Delete_Tail();
		int empty();
		void printall();
};

DSLK::~DSLK(){
	Node*p=head;
	while(p!=NULL)
	{
		head=head->next;
		delete p;
		p=head;
	}
}

void DSLK::Insert_Head(int d)
{
	head=new Node(d, head);
	dem++;
}

void DSLK::Insert_Tail(int d)
{
	Node*p=head;
	Node*q=new Node(d, head);
	if(head==NULL)
	{
		head=q;
	}
	else {
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=q;
		q->next=NULL;
	}
	dem++;
}

void DSLK::printall()
{
	for(Node*p=head; p!=NULL; p=p->next)
	{
		cout<<p->data<<" ";
	}
	cout<<endl;
}

void DSLK::Delete_Tail()
{
	Node*p=head;
	Node*q=tail;
	if(head=NULL)
		cout<<"empty list"<<endl;
	else if(head==tail)
	{
		delete head;
		head=tail=NULL;
	}
	else
	{
		Node*tam=head;
		while(tam->next!=tail)
		tam=tam->next;
		delete tail;
		tail=tam;
	}
		
}

int DSLK::empty(DSLK*L)
{
	return (L=NULL);
	}

main()
{
	DSLK L;
	int key;
	int key2;
	int n, i;
	if(L.empty()==0) cout<<"Ds Rong~!"<<endl;
	cout<<"Nhap n: "<<endl;
	cin>>n;
	for(i=0; i<n; i++)
	{
	cout<<"Nhap phan tu can chen dau: ";
	cin>>key;
	L.Insert_Head(key);
	L.printall();
	}
//	cout<<"Nhap phan tu can chen cuoi: ";
//	cin>>key2;
//	L.Insert_Tail(key2);
//	L.printall();
//	L.Delete_Tail();
//	L.printall();
}
