#include<iostream>
#include<conio.h>
using namespace std;

class matrix
{
      int h,c;
      float *a;
      public:
             matrix()
             {
                     h=c=5;
                     a=new float[h*c];
                     for(int i=0;i<h;i++)
                     for(int j=0;j<c;j++)
                     a[i*c+j]=1.1;
             }
             
             ~matrix()
             {
                      if(h!=0&&c!=0)
                      delete[] a;
             }
             
             friend istream &operator >>(istream &is,matrix &m);
             
             friend ostream &operator <<(ostream &os,matrix &m);
             
             void maxmt()
             {
             	   float max;
                   cout<<"\n";
                   for(int i=0;i<h;i++)
                     {
                     	   max = a[i*c];
                     	   cout<<max;
                           for(int j=0;j<c;j++)
                           {if(max<a[i*c+j])
                           max=a[i*c+j];}
                           cout<<"Max cua hang thu "<<i+1<<" la: "<<max<<endl;
                     }
                   
             }
            
             void yenngua()
             {
                  float m;
                  int htam,ctam,i,j;
                  float *b;
                  b=new float[h*c];
                  for(i=0;i<h;i++)
                  for(j=0;j<c;j++)
                  b[i*c+j]=0;
                  
                  //max hang
	              for(i=0;i<h;i++)
	              {m=a[i*c];
	              htam=i;
	              ctam=0;
	                     for(j=0;j<c;j++)
	                     {
		                  if(m<a[i*c+j])
		                  {m=a[i*c+j];
		                  htam=i;
		                  ctam=j;}
	                      }
                          b[htam*c+ctam]++;
                   }
	
	                   //min cot
	              for(j=0;j<c;j++)
	              {m=a[j];
		           htam=0;
		           ctam=j;
		                for(i=0;i<h;i++)
	    	            {
			             if(m>a[i*c+j])
			             {m=a[i*c+j];
			             htam=i;
			             ctam=j;
			             }}
			             b[htam*c+ctam]++;
			
        }
    
         for(i=0;i<h;i++)
         {for(j=0;j<c;j++)
                          {
                          if(b[i*c+j]==2)
                          cout<<"\nDiem yen ngua: "<<a[i*c+j];
         }
    }}
};

istream &operator >>(istream &is,matrix &m)
{
        cout<<"Nhap so hang,cot: ";
        cin>>m.h>>m.c;
        m.a=new float[m.h*m.c];
        cout<<"Nhap so phan tu ma tran: ";
        for(int i=0;i<m.h;i++)
        for(int j=0;j<m.c;j++)
        cin>>m.a[i*m.c+j];
}
             
ostream &operator <<(ostream &os,matrix &m)
{
        cout<<"Ma tran vua nhap la:\n";
        for(int i=0;i<m.h;i++)
        {
                for(int j=0;j<m.c;j++)
                {cout<<m.a[i*m.c+j]<<" ";}
                cout<<"\n";
        }
}

main()
{
      matrix a;
      cin>>a;
      cout<<a;
      a.maxmt();
      a.yenngua();
      getch();
}
