#include<iostream>
using namespace std;
class Sophuc
       {
    	int real,image; 
    	Sophuc *next;  
           public:
	void nhap(int r = 0, int i = 0)
	{
		real = r;
		image = i;
	}
	void in()
	{
		cout<<"phan thuc: "<<real<<",phan ao: "<<image<<endl;
	}
	friend class DaySophuc;
         };

         class DaySophuc
          {
	Sophuc *Head;
    	public:
	DaySophuc()
	{
		Head = 0; //NULL
	}
	void nhap(int r, int i);
	void in();
         };

         void DaySophuc::nhap(int r, int i)
         {
	Sophuc *Sp, *Temp;
	if(Head == 0)
	{
	  Head = new Sophuc;
	  Head->nhap(r, i);
	  Head->next = 0;
	}
	else
	{
               Sp = Head;
	    while(Sp != 0) //NULL
	    {
		  Temp = Sp;
		  Sp = Sp->next;
	    }
	  
	   Temp->next = new Sophuc;
	   Temp->next->nhap(r, i);
	   Temp->next->next = 0;
	 }
          }

          void DaySophuc::in()
          {
	Sophuc *Sp;
	Sp = Head;
	while(Sp != 0)
	{
	  Sp->in();
	  Sp = Sp->next;
	}
          }

          int main()
          {
	 DaySophuc   Daysophuc;
	 int  r,i;
	 while(true)
	 {
	  cout<<"phan thuc: "; cin>>r;
	  cout<<"phan ao: "; cin>>i;
	  if(r == 0 && i == 0) break; 
	  Daysophuc.nhap(r, i);
	 }
	 Daysophuc.in();
	 return 0;
          }

