//BAI KIEM TRA SO 1 - MR. DAT RAPPER ! 
#include<iostream>//Khai bao thu vien vao ra 
#include<fstream>//Khai bao thu vien nhap xuat file
using namespace std;
int main(){
	char ch;
	ofstream ofs ("text1.txt");
	/* ofstream: Mo file de ghi du lieu (ifstream: Mo file de doc du lieu)
	ofs: Ten con tro (Giong *fp trong C, cai nay dat tuy y, cai gi cung duoc)
	"text1.txt" : Ten file muon ghi (Dat tuy y)*/
	ofs << "Nhom hoc phan : N05" << endl;
	ofs << "HP: Lap trinh huong doi tuong" <<endl;
	ofs << "MR.DAT is handsome boyyyy !! "<< endl;
	/*Binh thuong khi xuat ra man hinh thi dung cout, nhung de xuat ra file thi khong, luc nay cout duoc thay the bang
	ten con tro file ma minh da dat (chinh la ofs da dat o dong 6 luc mo file de ghi), kem voi dau <<, dau << la in ra,
	dau >> la nhap vao
	Sau do viet noi dung nhu khi viet voi cout 
	endl: Giong \n trong C*/
	ofs.close(); // Dong file co ten con tro la ofs, bat buoc phai co
	ifstream ifs("text1.txt");
	while(ifs.get(ch)) cout<<ch;
	ifs.close();
	return 0;
}
