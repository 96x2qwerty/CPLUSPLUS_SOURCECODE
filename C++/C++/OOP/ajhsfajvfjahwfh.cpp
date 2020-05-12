#include<iostream>

using namespace std;
class Taphop{
	int n;
	int *a;
	public:
		Taphop(){
			n = 0;
			a = NULL;
		}

		friend ostream &operator << (ostream &os, Taphop &r){
			for(int i=0; i<r.n; i++){
			os << r.a[i] << " ";
			}
			return os;
		}
};
int main()
{

}
