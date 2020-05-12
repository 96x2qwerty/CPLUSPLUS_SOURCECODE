//SO PHUC CLASS 
#include<iostream>
#include<math.h>
using namespace std;
class sophuc{
	int real,img;
	public:
		sophuc();
		sophuc(int i,int r);
		sophuc(const sophuc &c);
		void in();
		~sophuc();
};
sophuc::sophuc(){
	real = img = 0;
}
sophuc::sophuc(int i,int r){
	real = r;
	img = i;
}
sophuc::sophuc(const sophuc &c){
	this -> real = c.real;
	this -> img = c.img; 
}
sophuc::~sophuc(){
	cout << "Ham huy !"<<endl;
}
void sophuc::in(){
	cout << real << ((img >=0)?"+j":"-j")<<abs(img)<<endl;
}

int main(){
	sophuc *p = new sophuc();
	sophuc q(-3,4);
	sophuc r = q;
	cout << "so phuc p: "; p->in();
	cout << "so phuc q: " ; q.in();
	cout << "so phuc r: " ; r.in();
	return 0;
	
}
