#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct
{
      char ht[30];
      char ns[30];
      char dc[30];
      float hsl;
      float lcb;
}data;
typedef struct tagNode
{
      data infor;
      tagNode*link;
}Node,*pNode;
void nhap(data*x)
{
      printf("\n nhap he so luong:");
      scanf("%f",&(x->hsl));
      if(x->hsl>0)
      {
            printf("\n ho va ten:");
            fflush(stdin);
            gets(x->ht);
            printf("\n ngay sinh:");
            fflush(stdin);
            gets(x->ns);
            printf("\n dia chi:");
            fflush(stdin);
            gets(x->dc);
            printf("\n luong co ban:");
            scanf("%f",&(x->lcb));
      }
}
void xuat(data x)
{
     printf("\n he so luong la: %f,ho va ten la: %s,ngay sinh la: %s,dia chi: %s,luong co ban la: %f",x.hsl,x.ht,x.ns,x.dc,x.lcb);
}
void create(pNode*last)
{
     *last=NULL;
}
int empty(pNode last)
{
     if(last==NULL)
     return 1;
        else
     return 0;
}
int full(pNode last)
{
     return 0;
}
void them_cuoi(pNode*last,data x)
{
     Node*p;
     p=*last;
     p=(Node*)malloc(sizeof(Node));
     p->infor=x;
     p->link=*last;
     *last=p;
}
void them_dau(pNode*last,data x)
{
     Node*p,*q;
     nhap(&x);
     q=*last;
     p=(Node*)malloc(sizeof(Node));
     p->infor=x;
     p->link=NULL;
     if(q==NULL)
     *last=p;
     else
     {
         while(q->link!=NULL)
         q=q->link;
         q->link=p;
     }
}
void LIFO(pNode*last,data x)
{
     do{
           nhap(&x);
           if(x.hsl>0)
           them_cuoi(last,x);
       }while(x.hsl>0);
}
void duyet(pNode last)
{
     Node*p=last;
     while(p!=NULL)
     {
            xuat(p->infor);
            p=p->link;
     }
}
void liet_ke(pNode*last)
{
     Node*p=*last;
     data x;
     int dem=0;
     while(p!=NULL)
     {
           if(p->infor.hsl<5)
           {
               printf("\n ho va ten: %s,ngay sinh: %s,dia chi: %s,luong co ban: %f",p->infor.ht,p->infor.ns,p->infor.dc,p->infor.lcb);
               dem++;
           }
           p=p->link;
     }
     printf("\n co %d nhan vien he so luong thap",dem);
}
void sx(pNode*last)
{
     Node*p=*last;
     Node*q;
     data tg;
     while(p->link!=NULL)
     {
            q=p->link;
            while(q!=NULL)
            {
                  if(p->infor.lcb>q->infor.lcb)
                  {
                         tg=p->infor;
                         p->infor=q->infor;
                         q->infor=tg;
                  }
                  q=q->link;
            }
            p=p->link;
     }
}
Node *tim_kiem(pNode last)
{
     char s[100];
     Node*p;
     printf("\n nhap ho ten nhan vien can tim:");
     fflush(stdin);
     gets(s);
     p=last;
     while((p!=NULL)&&(p->infor.ht==s))
     p=p->link;
     return p;
}
int main()
{
    data x;
    pNode last;
    Node*kq;
    create(&last);
    LIFO(&last,x);
    printf("\n thong tin vua nhap la:");
    duyet(last);
    /*printf("\n sau khi them 1 nhan vien vao cuoi danh sach:");
    them_dau(&last,x);
    duyet(last);
    printf("\n sau khi them 1 nhan vien vao dau danh sach:");
    nhap(&x);
    them_cuoi(&last,x);
    duyet(last);*/
    printf("\n sau khi sap xep nhan vien theo so luong tang dan la:");
    sx(&last);
    duyet(last);
    /*printf("\n nhan vien co he so luong thap la:");
    liet_ke(&last);
    kq=tim_kiem(last);
    if(kq==NULL)
    printf("\n khong co nhan vien can tim");
    else
    {
          printf("\n nhan vien can tim la:");
          xuat(kq->infor);
    }*/
    getch();
    return 0;
}
     
    
