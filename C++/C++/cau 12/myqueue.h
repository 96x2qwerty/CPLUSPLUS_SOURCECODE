#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct
{
        int dl;
}data;
typedef struct tagNode
{
        data infor;
        tagNode*link;
}Node,*queue;
void createQ(queue*Q)
{
        *Q=NULL;
}
void addQ(data x,queue*Q)
{
        Node*p=*Q;
        p=(Node*)malloc(sizeof(Node));
        p->infor=x;
        p->link=*Q;
        *Q=p;
}
void delQ(data*x,queue*Q)
{
        Node*p=*Q,*q;
       if(p->link==NULL)
        {
              *x=p->infor;
              *Q=NULL;
              free(p);
        }else
        {
             q=p->link;
             while(q->link!=NULL)
             {
                     p=p->link;
                     q=q->link;
             }
             *x=q->infor;
             p->link=NULL;
             free(q);
        }
}
int emptyQ(queue Q)
{
         if(Q==NULL)
         return 1;
            else
         return 0;
}

        
        
