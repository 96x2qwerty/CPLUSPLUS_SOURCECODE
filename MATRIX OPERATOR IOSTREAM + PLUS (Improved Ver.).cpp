#include<iostream>
#define MAXSIZE 100
using namespace std;
class Matrix{
private:
	int a[MAXSIZE][MAXSIZE];
	int Cap;
public:
	Matrix(){
		Cap= 0;
	}
	Matrix(int n){
		Cap= n;
	}
	~Matrix(){
	}
	friend istream&operator>>(istream &is, Matrix &q);
	friend ostream&operator<<(ostream &os, Matrix &q);
	Matrix&operator+ (Matrix &q){
		Matrix c=q;
		for(int i=0; i<q.Cap; i++){
			for(int j=0; j<q.Cap; j++){
				c.a[i][j]=a[i][j]+q.a[i][j];
			}
		}
	}
};
	istream&operator>>(istream &is, Matrix &q){
		for(int i=0; i<q.Cap; i++){
			for(int j=0; j<q.Cap; j++){
				cout<<"Nhap a["<<i<<"]["<<j<<"]: ";
				is>>q.a[i][j];
			}
		}
		return is;
	}	
	ostream&operator<<(ostream &os, Matrix &q){
		for(int i=0; i<q.Cap; i++){
			for(int j=0; j<q.Cap; j++){
				cout<<q.a[i][j]<<" ";
			}
			cout<<"\n";
		}
		return os;
	}
int main(){
	int n;
	cout<<"Nhap cap cua ma tran: ";
	cin>>n;
	Matrix a(n), b(n);
	cout<<"Nhap ma tran a:\n";
	cin >> a;
	cout<<"Nhap ma tran b:\n";
	cin >> b;
	cout<<"Ma tran vua nhap la: \n";
	cout<< a;
	cout<<endl;
	cout << b;
	cout<<endl;
	cout<<"Tong hai ma tran la:\n";
	Matrix c(n);
	c=a+b;
	cout << c;
	return 0;
}
