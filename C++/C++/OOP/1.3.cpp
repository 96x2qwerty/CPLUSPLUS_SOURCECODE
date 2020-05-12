#include<iostream>
using namespace std;
template <class T> class Dayso
{
	
	public: 
	int spt;
	T *a;
	public:
		Dayso(int spt=0, T *a=NULL);
		~Dayso(){
		}
		friend istream &operator>>(istream &is, Dayso<T> &p){
			cout<<"Nhap so phan tu cua day so: ";
			is>>p.spt;
			p.a=new T[p.spt];
			for(int i=0; i<p.spt; i++)
			{
				cout<<"Nhap PT: ";
				is>>p.a[i];
			}
			return is;
		}
		friend ostream &operator<<(ostream &os, Dayso<T> &p){
			for(int i=0; i<p.spt; i++)
			{
				os<<p.a[i]<<" ";
			}
			return os;
		}
		int max();
};
template <class T>
Dayso<T>::Dayso(int n1, T *a1)
{
	spt=n1;
	a=new T[spt];
	for(int i=0; i<spt; i++)
	{
		a[i]=a1[i];
	}
}
template <class T>
int Dayso<T>::max()
 {
 	int vt;
 	for(int i=0; i<spt; i++)
 	{
 		if (a[i]>a[vt])
 		vt=i;
	 }
	 return vt+1;
 }
main()
{
	Dayso<int> k;
	cin >> k;
	cout<<k;
	cout<<"\nMax la: "<<k.a[k.max()-1]<<" "<<k.max();
}

