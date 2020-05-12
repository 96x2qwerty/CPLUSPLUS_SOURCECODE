#include<stdio.h>

/*
int main()
{
	FILE *f;
	int x,n,i;
	f=fopen("data.inp","wt");
	printf("Nhap n: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("Nhap so thu %d: ",i);
		scanf("%d",&x);
		fprintf(f,"%d ",x);
	}
	fclose(f);
}
*/

int main()
{
	FILE *f;
	int x,i;
	f=fopen("data.inp","rt");

//	for(i=1;i<=4;i++)   //truong hop da biet so luong trong file
//	{
//		fscanf(f,"%d",&x);
//		printf("%d ",x);
//	}
//	fclose(f);

	while(!feof(f))
	{
		fscanf(f,"%d ",&x);
		printf("%d ",x);
	}
	fclose(f);

}
