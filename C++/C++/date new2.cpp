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
	//Hàm tra lai so ngày cua mot tháng bat ki. Neu nam nhuan và là tháng hai so
     //ngày cua tháng hai (28) duoc cong thêm 1.

	int songay(int m, int y)
{
  return  n[m]+((m==2) ? ktra(y): 0);
}

			
	//date-day Hàm tra lai so ngày tính tu ngày 1 tháng 1 nãm 1 bang cách cong don so ngày
    //cua tung nam tu  nam 1 den nam hien tai, tiep theo cong don so ngày tung
    //tháng cua nãm hien tai cho den tháng hien tai và cuoi cùng cong thêm so ngày
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
