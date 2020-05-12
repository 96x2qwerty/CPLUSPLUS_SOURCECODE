#include<iostream>
#include<time.h>
#include<conio.h>
using namespace std;
main()
{
      int ngay,thang,nam ;
      tm *today ;
      time_t now;
      time( &now );
      today = localtime( &now );
      ngay=today->tm_mday;
      thang=today->tm_mon;
      nam=today->tm_year;
      cout<<"Hom nay la ngay "<<ngay<<" thang "<<thang<<" nam "<<nam;
      getch();
}
