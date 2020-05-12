#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>

int a[8][8];
int hau = 4, an =10;
int width = 60;
int color = 15;

void kddh()
{
 int gdriver = DETECT, gmode, errorcode;
 initgraph(&gdriver, &gmode, "C:\\BC31\\BGI");
 errorcode = graphresult();
 if (errorcode != grOk) /* an error occurred */
 {
 printf("Graphics error: %s\n", grapherrormsg(errorcode));
 printf("Press any key to halt:");
 getch();
 return;
 }
}

void xuat1vt(int d,int c)
{
 // setcolor(4);
 if (a[d][c]==1) //ascii = 2
 {
 setfillstyle(1, 10);
 fillellipse (c*width+30, d*width+30, 15, 10);
 //settextstyle(1, HORIZ_DIR, 5);
 //outtextxy(c*width + 10, d*width + 10, "Û");
 }
 else //ascii = 1
 {
 setfillstyle(1, 4);
 bar(c*width + 10, d*width + 10, c*width+50, d*width+50);
 //settextstyle(1, HORIZ_DIR, 5);
 //outtextxy(c*width + 10, d*width + 10, "N");
 }
 delay(50);
}

void antrai(int d,int c)
{
 c--; //di qua trai
 while (c>=0) //bien trai
 if (a[d][c])
 c--;
 else
 {
 a[d][c]=1;
 xuat1vt(d,c--);
 delay(400);
 }
}

void anphai(int d,int c)
{
 c++;
 while (c<8) //bien phai
 if (a[d][c])
 c++;
 else
 {
 a[d][c]=1;
 xuat1vt(d,c++);
 delay(400);
 }
}

void anxuong(int d,int c)
{
 d++;
 while(d<8)
 if (a[d][c])
 d++;
 else
 {
 a[d][c]=1;
 xuat1vt(d++,c);
 delay(400);
 }
}

void ancheo6(int d,int c)
{
 d++;c++;
 while (d<8&&c<8) //trong khi con nam trong ban co
 if (a[d][c])
 {
 c++;
 d++;
 delay(400);
 }
 else
 {
 a[d][c]=1;
 xuat1vt(d++,c++);
 delay(400);
 }
}

void ancheo8(int d,int c)
{
 d++;
 c--;
 while (d<8&&c>=0)
 if (a[d][c])
 {
 d++;
 c--;
 }
 else
 {
 a[d][c]=1;
 xuat1vt(d++,c--);
 delay(400);
 }
}

void dat1hau(int d,int c)
{
 a[d][c]=2;
 xuat1vt(d,c);
 antrai(d,c);
 anphai(d,c);
 anxuong(d,c);
 ancheo6(d,c);
 ancheo8(d,c);
 delay(400);
}

int demcheo8(int d,int c)
{
 int dem=0;
 d++;
 c--;
 while (d<8&&c>=0)
 if (a[d++][c--]==0)
 dem++;
 return dem;
}

int demcheo6(int d,int c)
{
 int dem=0;
 d++;
 c++;
 while (d<8&&c<8)
 if (a[d++][c++]==0)
 dem++;
 return dem;
}

int demxuong(int d,int c)
{
 int dem=0;
 d++;
 while (d<8)
 if (a[d++][c]==0)
 dem++;
 return dem;
}

int dem_otrong(int d,int c)
{
 int dem=0;
 dem+=demxuong(d,c);
 dem+=demcheo6(d,c);
 dem+=demcheo8(d,c);
 return dem;
}

int tim_otrong(int d,int c)
{
 while (a[d][c]&&c<8)//bo qua nhung o da dung
 c++;
 return c; // c mang 2 gia tri 8:khong con trong ban co,
 // hoac <8:co 1 o trong tai vi tri c
}

int timmin(int d)
{
 int min=65;//khoi tao gia tri tim min ->max
 int vtc=8; //vi tri cot min
 int c=0;//vua la vi tri bat dau xet tim o trong, vua la tri tra ve
 while (c<8)
 {
 c = tim_otrong(d,c); //dong dang xet,cot bat dau
 if (c<8)//co it nhat 1 o trong
 {
 int h=dem_otrong(d,c);
 if (h<min)
 {
 min=h; //cap nhat lai gia tri min
 vtc=c; //cap nhat lai vi tri min
 }
 c++; //tim o trong ke tiep
 }
 }
 return vtc;
}

int tamhau()
{
 dat1hau(0,3);
 dat1hau(1,7);
 dat1hau(2,0);
 for (int d=3;d<8;d++) //dat 5 con hau con lai
 {
 int c=timmin(d); //tim o bang min thi chon
 if (c>=8)
 {
 getch();
 return 0;
 } //khong tim thay o trong nao ca,retrun ve that bai
 dat1hau(d,c); //dat hau vao vi tri vua tim duoc,cot thi tim min
 }
 getch();
 return 1; //thanh cong
}

void VeBC()
{
 setcolor(color);
 rectangle(0, 0, width*8-1, width*8-1);
 for (int i=0; i<8; i++)
 for (int j=0; j<8; j++)
 if ( (i%2==0 && j%2==0) || (i%2!=0 && j%2!=0) )
 {
 setfillstyle(1, color);
 bar( j*width, i*width, j*width + width, i*width + width);
 }
}

void canhan()
{
 rectangle(500,15,630,470);//Vien lon
 rectangle(497,13,633,473);//Vien nho
 rectangle(510,25,620,60);//Ten chuong trinh
 rectangle(510,70,620,240);//Mo ta chuong trinh
 rectangle(510,70,620,90);//

 rectangle(510,250,620,400);//Tac gia
 rectangle(510,410,620,460);//Ket qua
 outtextxy(520,420,"Ket qua:");
 setcolor(2);
 settextstyle(2,HORIZ_DIR,5);
 //sprintf(ng,"%d",ngay);
 outtextxy(520,260,"Tac Gia:");
 setcolor(YELLOW);
 outtextxy(520,280,"Anhsuytu");
 setcolor(2);
 //printf("\n");
 outtextxy(520,310,"Lop:");
 setcolor(YELLOW);
 outtextxy(520,330,"C2CT05");setcolor(2);
 outtextxy(520,360,"MSSV:");
 setcolor(YELLOW);
 outtextxy(520,380,"302010259");
 //Ten chuong trinh
 setcolor(RED);
 settextstyle(13,HORIZ_DIR,7);
 //sprintf(ng,"%d",ngay);
 outtextxy(525,35,"BAI TAM HAU");
 setcolor(2);
 settextstyle(13,HORIZ_DIR,3);
 outtextxy(545,80,"MO TA");
 char *s[]={ "Dat mot con","ma tai mot","vi tri bat" ,
 "ky tren ban","co, di sao ","cho het ban" ,
 "co voi dieu ","kien ko duoc","di len o da","di" };
 int x=110;
 for (int k=0;k<=9;k++)
 {
 setcolor(15);
 outtextxy(520,x,s[k]);
 x+=10;
 }
}

void main()
{
 clrscr();
 kddh();
 VeBC();
 canhan();
 int kq=tamhau();
 if (kq)
 outtextxy(520, 435, "Thanh cong"); //kq==1:thanh cong
 else
 outtextxy(520, 435, "Ko thanh cong"); //kq==0:that bai
 getch();
}
