#include<stdio.h>
#include<time.h>
#include<stdlib.h>

/*
main()
{
	FILE *f;
	int m,n,i,j,x;
	f=fopen("matran.inp","wt");
	
	printf("Nhap m,n: ");
	scanf("%d%d",&m,&n);
	srand(time(0));
	
	fprintf(f,"%d\n%d\n",m,n);
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
		x=rand()%10;
		fprintf(f,"%d ",x);	
		}
		fprintf(f,"\n");
	}
	
	fclose(f);
}
*/

main()
{
	FILE *f;
	int m,n,i,j,a[100][100];
	f=fopen("matran.inp","rt");
	
	fscanf(f,"%d",&m);
	fscanf(f,"%d",&n);

	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
		fscanf(f,"%d",&a[i][j]);
		}

	}
	fclose(f);
	
	printf("%d\n%d\n",m,n);
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}
