#include"myqueue.h"
#include<math.h>
#include<string.h>
void doi_2_10(queue Q)
{
     char s[100];
     int i,n;
     int t=0;
     data x;
     printf("\n nhap so nhi phan:");
     fflush(stdin);
     gets(s);
     printf("\n day so nhi phan vua nhap la: %s",s);
     createQ(&Q);
     n=strlen(s);
     for(i=0;i<n;i++)
     {
          if(s[i]=='1')
          x.dl=1*pow(2,n-i-1);
          else
          x.dl=0*pow(2,n-i-1);
          addQ(x,&Q);
     }
     while(!emptyQ(Q))
     {
          delQ(&x,&Q);
          t=t+x.dl; 
     }
     printf("\n dang thap phan la:%d",t);
}
int main()
{
    queue Q;
    doi_2_10(Q);
    getch();
    return 0;
}
     
     
