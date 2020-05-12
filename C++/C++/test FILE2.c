#include<stdio.h>
#include<conio.h>

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
	}
}
