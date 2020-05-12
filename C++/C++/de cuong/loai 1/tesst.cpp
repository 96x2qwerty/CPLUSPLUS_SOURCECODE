#include<iostream>
using namespace std;
 
 class cong{
       
       public:
              int a,b;
              cong()
              {a=b=0;}
              
              cong( int t,int m)
              { a=t; b=m;}
              
              cong operator + (cong &p)
              { cong q;
                q.a= a + p.a;
                  q.b= b + p.b;
                   return q;
              }
        
        };
       int main()
      { cong A (7,8);
        cong B (9,6);
        cong tong;
        tong = A+B;
          cout<<tong.a<<","<<tong.b;
          system("pause");
          }
