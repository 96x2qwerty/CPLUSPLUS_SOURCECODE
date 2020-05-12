#include <iostream>
#include <conio.h>
using namespace std;
class printer{
      protected:
      string ten;
      int sl;
      float gianhap;
      public:
             printer(){
                       ten="";
                       sl=0;
                       gianhap=0;
                       }
             printer(string t, int s, float g){
                            ten=t;
                            sl=s;
                            gianhap=g;
                            }
             virtual void nhap(){
                  cout << "Nhap ten may in: ";
                  cin >> ten;
                  cout << "So luong: ";
                  cin >> sl;
                  cout << "Gia tien:";
                  cin >> gianhap;
                  }
             virtual void xuat(){
                  cout << "\n\nTen may: " << ten << "\nSo luong: "<<sl<<"\nGia tien: "<<gianhap;
                  }
             virtual float thue(){
                   return (sl*gianhap*5/100);
                   }
};
class laserprinter : public printer{
      int dpi;
      public:
             laserprinter():printer(){
                                      dpi=0;
                                      }
             laserprinter(string t, int s, float g,int d):printer(t,s,g){
                                 dpi=d;
                                 }
             float thue(){
                   return (sl*gianhap/10);
                   }
             void nhap(){
                  cout << "Nhap ten may in: ";
                  cin >> ten;
                  cout << "So luong: ";
                  cin >> sl;
                  cout << "Gia tien:";
                  cin >> gianhap;
                  cout << "So DPI: ";
                  cin >> dpi;
                  }
             void xuat(){
                  cout << "\n\nTen may: " << ten << "\nSo luong: "<<sl<<"\nGia tien: "<<gianhap<<"\nDPI: "<<dpi;
                  }
};
class colorprinter : public printer{
      string color;
      public:
             colorprinter():printer(){
                                      color="";
                                      }
             colorprinter(string t, int s, float g,string c):printer(t,s,g){
                                 color=c;
                                 }
             float thue(){
                   return (sl*gianhap*15/100);
                   }
             void nhap(){
                  cout << "Nhap ten may in: ";
                  cin >> ten;
                  cout << "So luong: ";
                  cin >> sl;
                  cout << "Gia tien:";
                  cin >> gianhap;
                  cout << "Mau sac:";
                  cin >> color;
                  }      
             void xuat(){
                  cout << "\n\nTen may: " << ten << "\nSo luong: "<<sl<<"\nGia tien: "<<gianhap << "\nMau sac:"<< color;
                  }
};
int main()
{
    printer *a[4];
    int n=2,i;
    for (i=0;i<n;i++)
    {
        int x;
        cout << "May in loai nao(1-Laser, 2-Color): ";
        cin >> x;
        if (x==1) a[i]=new laserprinter();
        else a[i]=new colorprinter();
        a[i]->nhap();
    }
    for (i=0;i<n;i++)
    {
        a[i]->xuat();
        cout << "\nThue: "<< a[i]->thue();
        }
    getch();    
    
}
