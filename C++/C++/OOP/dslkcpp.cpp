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
	
	Node*head;
	Node*tail;
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

void DSLK::Insert_Head(int d)
{
	head=new Node(d, head);
	dem++;
}

void DSLK::Insert_Tail(int d){
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

void DSLK::Delete_Head(){
	
	Node*p=head;
	if(p!=NULL)
	{
		head=head->next;
		delete p;
		dem--;
	}
}

void DSLK::Delete_Tail(){
	Node*p=head;
	Node*q=tail;	
	if(head=NULL)
		return;
	else if(head==tail){
		head=NULL;
		tail=NULL;
	}
	else{
		while(p->next!=q)
		{
			p=p->next;
			tail=p;
		}
		delete q;
		dem--;
	}
}

void DSLK::printall(){
	for(Node*p=head; p!=NULL;p=p->next){
		cout<<p->data<<" ";
	}
	cout<<endl;
}

int DSLK::empty() const{
	return 0;
}

main()
{
	DSLK L;
	int key;
	do{
		cout<<"Nhap phan tu can chen dau: ";
		cin>>key;
		if(key!=0)
			L.Insert_Head(key);
	}while(key!=0);
	L.printall();
	L.Delete_Tail();
	cout<<"DS sau khi xoa la: ";
	L.printall();
	//int k;
	//<<"Nhap pt k: ";
	//cin>>k;
	//L.Insert_Tail(k);
	//L.printall();
	//L.Delete_Head();
	//L.printall();
}
