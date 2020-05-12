#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class sophuc{
	int real, img;
	sophuc*next; //doi tuong ke
	public:
	void nhap(int r=0, int i=0){
		real = r;
		img = i;
	}	
	void in(){
		cout<<"Phan thuc: "<<real<<" Phan ao: "<<img<<endl;
	}
	friend class Daysophuc;
};
class Daysophuc{
	sophuc *Head;
	public:
		Daysophuc(){
			Head=0;
		}
		void nhap(int r, int i);
		void in();
};
void Daysophuc::nhap(int r, int i){
	sophuc *sp, *temp;
	if(Head ==0){
		Head = new sophuc;
		Head->nhap(r,i);
		Head->next;
	}
	else{
		sp =Head;
		while(sp!=0) //NULL
		{
			temp= sp;
			sp =sp->next;
		}
		temp->next= new sophuc;
		temp->next->nhap(r,i);
		temp->next->next=0;
	}
}
void Daysophuc::in(){
	sophuc*sp;
	sp= Head;
	while(sp!=0){
		sp->in();
		sp= sp->next;
	}
}
int main() {
	Daysophuc Daysp;
	int r,i;
	while(true){
		cout<<"phan thuc: "; cin>>r;
		cout<<"phan ao: ";cin>>i;
		if(r==0 && i==0) break;
		Daysp.nhap(r,i);
	} 
	Daysp.in();
	return 0;
}
