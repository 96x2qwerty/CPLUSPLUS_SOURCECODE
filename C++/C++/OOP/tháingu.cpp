#include <stdio.h>
main()
{
      int n,i,a,x;
      float s1,s2;
      printf(" nhap so n: ");
      scanf("%d",&n);
     	x=1;s2=0;
      for(i=1;i <= n;i++) 
	  {
		for(a=1;a<=i;a++)
        {
                      s1=s1*a;
                      s2=s2+x/s1;
                      x=x*-1;
					  }
    printf(" tong can tim là: %f",s2 );
					  }
					  }


