#include<stdio.h>
#include<iostream>
#include<conio.h>

using namespace std;



int n[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};



class date{
	int d,m,y;
	public:
		date(){ d=1;
				m=1;
				y=2000;
				}
		date(int d1,int m1,int y1)
		{
			d=d1;
			m=m1;
			y=y1;
		}
		long dateday();
		
		
		date operator ++();
        date operator ++(int);
        date operator + ( );
        date operator + (int );
        
        date operator + ( date b);
		
		 friend istream& operator >>(istream &i, date &p);
         friend ostream& operator <<(ostream &o, date &p);
		
		friend date operator + (int ,date );
		friend int operator - (date , date );
};


	// bool
		bool ktra(int y)
{
     return (y%4==0);
     
}
		
	// >> <<	
		istream& operator >>(istream &i, date &p)
		{
			cout<<"Nhap ngay";
			i>>p.d;
			cout<<"\nNhap thang: ";
			i>>p.m;
			cout<<"\nNhap nam: ";
			i>>p.y;
		}
		ostream& operator <<(ostream &o, date &p)
		{
			o<<"\nNgay"<<p.d
			  <<"/"<<p.m
			  <<"/"<<p.y<<endl;
			}
	//H�m tra lai so ng�y cua mot th�ng bat ki. Neu nam nhuan v� l� th�ng hai so
     //ng�y cua th�ng hai (28) duoc cong th�m 1.

	int songay(int m, int y)
{
  return  n[m]+((m==2) ? ktra(y): 0);
}

			
	//date-day H�m tra lai so ng�y t�nh tu ng�y 1 th�ng 1 n�m 1 bang c�ch cong don so ng�y
    //cua tung nam tu  nam 1 den nam hien tai, tiep theo cong don so ng�y tung
    //th�ng cua n�m hien tai cho den th�ng hien tai v� cuoi c�ng cong th�m so ng�y
    //hien tai.  

			
		long date::dateday()
{
    long day=d;
    for(int i=1; i<y; i++)
    day+=365 + ktra(i);
    for(int i=1; i<m; i++)
    day+=songay(i,y);
    return day;
}	
	
	
	// ham chuyen day->date
 date daydate(long day)
{
     int d=0,m=1,y=1;
     while(  day>=365&&!ktra(y) || day>365&&ktra(y))
     {
            day-=365 +ktra(y);
            y ++;
     }
     while( day>n[m] + ((m==2)?ktra(y):0) )
     {
            day-=n[m] + ((m==2)?ktra(y):0);
            m++;
     }
     d=day;
     return date(d,m,y);
}		
	
	
	// toan tu ++
date date::operator ++() // ++Date
{
     *this=daydate(dateday()+1);
}

date date::operator ++(int n) // Date++
{
     *this=daydate(dateday()+1);
}



// toan tu + 
date date::operator + ( date b) // Date = Date + Date
{
     return daydate(dateday() + b.dateday());
}

date date:: operator + (int n) // Date = Date + day
{
     return daydate(dateday()+n);
}



date operator +(  int n, date a ) // Date = day + Date
{
     return daydate(a.dateday()+n);
}




		
			
			int main()
			{
				int d;
				date ngancute;
			
     		    cin>>ngancute;
                cout<<"\nNgay/thang/nam vua nhap: ";
      			cout<<ngancute;
      			ngancute++;
      			cout<<"\nTang len 1 ngay: ";
      			cout<<ngancute;
     
      			cout<<"\nTang date len bao nhieu day: ";
      			cin>>d;
      			date kq =ngancute + d;
      			cout<<"\nNgay/thang/nam sau khi tang: "
				  	<<kq;
      			
				
				
				
				
				
				getch();
			}
