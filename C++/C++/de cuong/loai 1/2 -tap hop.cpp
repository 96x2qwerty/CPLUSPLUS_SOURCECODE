#include<iostream>
#include<conio.h>

using namespace std;
class Node
{
      float data;
      Node *link;
      public:
             Node(float dt,Node *LK)
             {
                 data = dt;
                 link = LK;
             }
             
             friend class TH;
};

class TH
{
      Node *head;
      int spt;
      public:
             TH()
             {
                 head = NULL;
                 spt = 0;
             }
             
             ~TH()
             {
                  Node *p=head;
                  while(p!=NULL)
                  {
                      head = p->link;
                      delete p;
                      p = head;
                  }
             spt = 0;
            }
      
             bool empty();
             void addp(float dt);
             void delp();
             bool check(float dt);
             //friend TH operator +(TH a,TH b);
             //friend float operator [](TH p,int x);
             friend istream &operator >>(istream &is,TH &p);
             friend ostream &operator >>(ostream &os,TH &p);           

};


bool TH::empty()
{
     return (spt=0);
}
// trong danh sach phai kiem tra phan tu nhap vao da co trong danh sach chua, neu chua co thi them vao neu da co thi ket thuc.

void TH::addp(float dt)
{
     Node *p;
     p=new Node(dt,head);
     if(!check(dt))
     head = p;
     spt ++;
}


void TH::delp()
{
     Node *p=head;
     if(empty())
     return;
     else head = p->link;
     delete p;
     spt --;
}

bool TH:: check(float dt)
{
     Node *p=head;
     while(p!=NULL)
     {
          if(p->data == dt)
          return true;
          else 
          p=p->link;
     }
}

istream &operator >>(istream &is,TH &p)
{
        float t;
        cout<<"Nhap cac thanh phan: ";
        is>>t;
        while(t!=-1)
        {
        	p+t;
        	cin>>t;
        }
        return is;
}

ostream &operator <<(ostream &os,TH &p)
{
        float t;
        while(p.head!=NULL)
        {
        	p-t;
        	os<<t<<", ";
        }
        return os;
}

main()
{
      TH a;
      cin>>a;
      cout<<a;
      getch();
}
