#include<iostream>
#include<conio.h>
using namespace std;
class TH;
class Node
{
      float data;
      Node *link;
      public:
             Node(float dt,Node *link1)
             {
                        data=dt;
                        link=link1;
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
                 head= NULL ;
                 spt=0;
             }
             
             ~TH()
             {
                 Node *p=head;
                 while(p!=NULL)
                 {
                               head=p->link;
                               delete p;
                               p=head;
                 }
             }
             float begin();
             bool check(float x);
             void push_front(float x);
             void pop_front();
             bool empty();
             TH operator +(TH b);
             friend istream &operator >>(istream &is,TH &t);
             friend ostream &operator <<(ostream &os,TH &t);
};

bool TH:: empty()
{
     return (head== NULL && spt == 0)?true:false;
}

float TH::begin()
{
      return head->data;
}

bool TH::check(float x)
{
     Node *p=head;
     while(p!= NULL)
     {
                     if(p->data==x)
                     return true;
                     p=p->link;                     
     }
     return false;
}
//them dau-bot dau
void TH:: push_front(float x)
{
     Node *p=new Node(x,NULL);
     if(this->check(x)) return ;
     p->link=head;
     head=p;
     spt++;
}

void TH::pop_front()
{
     Node *p=head;
     if(this->empty())
     return ;
     head=p->link;
     delete p;
     spt--;
}

//Nhap xuat
istream &operator >>(istream &is,TH &t)
{
        float x;
        int n;
        cout<<"Nhap spt cua TH: ";
        is>>n;
        cout<<"Nhap phan tu TH: ";
        for(int i=0;i<n;i++)
        {
                is>>x;
                t.push_front(x);
        }
        return is;
}

ostream &operator <<(ostream &os,TH &t)
{
        os<<"{";
        while( t.spt > 1 )
        {
                    os<<t.begin();
                    os<<" , ";
                    t.pop_front();
        }
        os<<t.begin();
        os<<"}";
        return os;
}

//toan tu
/*
TH TH::operator +(TH b)
{
                TH *c;
                Node *p;
                for(p=head;p!=NULL;p=p->link)
                if(!b.check(p->data))
                c.push_front(b->data);
                return c;
}*/

main()
{
      TH a;
      cin>>a;
      cout<<a;
      getch();
} 
