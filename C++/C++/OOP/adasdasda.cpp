#include<iostream>
#include<conio.h>

using namespace std;

class DSLK;
class Node{
	int data;
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
void Insert_Head(int d);
void Delete_Head();
void Insert_Tail(int d);
void Delete(int d);
bool IsExist(int d);
void Delete_Tail();
void Sort();
int Search(int d);
int empty() const;
void ShowDS();
};

DSLK::~DSLK(){
Node*p=head;
while(p!=NULL){
head=head->next;
delete p;
p=head;
}
dem=0;
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

bool DSLK::IsExist(int d)
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

void DSLK::Delete(int k)
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

void DSLK::Sort(){
for(Node*p=head;p!=NULL;p=p->next)
for(Node*q=p->next;q!=NULL;q=q->next)
{
int temp=p->data;
p->data=q->data;
q->data=temp;
}
}

void DSLK::ShowDS(){
if(empty()==1)
cout<<"DS rong!\n";
else
{
for(Node*p=head; p!=NULL;p=p->next){
cout<<p->data<<" ";
}
}
cout<<endl;
}

int DSLK::Search(int d){
Node*p=head;
int i=1;
for(p;p!=NULL;p=p->next)
{
if(p->data==d)
return i;
}
return 0;
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
<<"2: Chen cuoi DS "<<endl
<<"3: Xoa dau"<<endl
<<"4: Xoa bat ky"<<endl
<<"5: Xoa cuoi"<<endl
<<"6: In DS"<<endl
<<"7: Kiem tra DS rong"<<endl
<<"8: SX danh sach"<<endl
<<"9: Tim kiem"<<endl
<<"10: Thoat"<<endl;
do{
cout<<"Ban chon: ";
cin>>lua_chon;
switch (lua_chon)
{
case 1:
{
int key;
cout<<"Nhap pt chen dau: ";
cin>>key;
L.Insert_Head(key);
break;
}
case 2:
{
int key2;
cout<<"Nhap pt chen cuoi: ";
cin>>key2;
L.Insert_Tail(key2);
break;
}
case 3:
{
L.Delete_Head();
break;
}
case 4:
{
int d;
cout<<"Nhap d= ";
cin>>d;
L.Delete(d);
break;
}
case 5:
{
L.Delete_Tail();
break;
}
case 6:
{
L.ShowDS();
break;
}
case 7:
{
if(L.empty()==1)
cout<<"DS rong!"<<endl;
else
cout<<"DS khong rong !"<<endl;
}
case 8:
{
L.Sort();
L.ShowDS();
break;
}
case 9:
{
int d;
cout<<"Nhap phan tu tim kiem: ";
cin>>d;
if(L.Search(d)!=0)
cout<<"Tim thay phan tu "<< d << " tai vi tri: "<<L.Search(d)<<endl;
else
cout<<"'Khong tim thay !";
break;
}
case 10: break;
}
}while(lua_chon!=10);
}
