#include<iostream>
#include<string>
#include<conio.h>
using namespace std;
class email {
             string nd;
             public:
                    email(string s) { nd=s; }
                    virtual void gui()
                    {
                     cout<<nd;        
                    }
            };

class nhansu:public email {
                           public:
                                  nhansu(string nd):email(nd){}
                                  void gui(){ cout<<"\nPhong nhan su: Can tuyen them nguoi !"; }
                          };
class taivu:public email {
                           public:
                                  taivu(string nd):email(nd){}
                                  void gui(){ cout<<"\nPhong tai vu: Tang luong cho cac nhan vien !"; }
                          };
class hanhchinh:public email {
                           public:
                                  hanhchinh(string nd):email(nd){}
                                  void gui(){ cout<<"\nPhong hanh chinh: Chuan bi don khach nuoc ngoai !"; }
                          };

int main()
{
    int n;
    cout<<"\nGui email bao nhieu lan ?";
    cin>>n;
    email *a[n];   
 
    for(int i=0;i<n;i++)
    {
            int t;
            cout<<"\nNhap 1 de bat dau gui: ";
            cin>>t;
            if(t==1)
            {
                    a[i]=new nhansu(" ");
                    a[i]->gui();
                    a[i]=new taivu(" ");
                    a[i]->gui();
                    a[i]=new hanhchinh(" ");
                    a[i]->gui();        
            }        
    }     
    getch();
}
