#include<iostream>
using namespace std;
class sophuc{
	int real,img;
	public:
		sophuc(int i,int r){
			real = r;
			img = i;
		}
	friend int sosanh(sophuc &p,sophuc &q);
};
int sosanh(sophuc &p,sophuc &q){
	return (p.real == q.real && p.img == q.img);
}
int main(){
	sophuc p(-2,1),q(-2,1);
	int r = sosanh(p,q);
	if (r == 1)
		cout << "p = q" << endl;
	else
		cout << "p # q" << endl;
	return 0;
}
