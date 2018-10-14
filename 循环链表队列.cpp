#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef int QElemType;
typedef int Status;
typedef struct QNode
{
    QElemType data;
    struct QNode * rear;
    struct QNode * next;
}QNode,*LinkQueue;

Status InitLinkQueue(LinkQueue * L)
{

    (*L)=(LinkQueue)malloc(sizeof(QNode));
    if((*L)==NULL)
    {
        printf("�ڴ治�㣬��ʼ��ʧ��\n");
        return 1;
    }
    (*L)->rear=(*L);
    return 1;
}

Status Create(LinkQueue * L,int n)
{
    srand(time(0));
    LinkQueue P;
    for(int i=0;i<n;i++)
    {
        P=(LinkQueue)malloc(sizeof(QNode));
        P->data=rand()%100+1;
        (*L)->rear->next=P;
        (*L)->rear=P;
    }
    P->next=(*L);
    return 1;
}

Status EnQueue(LinkQueue * L,QElemType e)
{
    LinkQueue P;
    P=(LinkQueue)malloc(sizeof(QNode));
    P->data=e;
    P->next=(*L);
    (*L)->rear->next=P;
    (*L)->rear=P;
    return 1;
}

Status DeQueue(LinkQueue * L,QElemType * e)
{
    LinkQueue temp;
    *e=(*L)->next->data;
    temp=(*L)->next;
    (*L)->next=(*L)->next->next;
    free(temp);
    return 1;

}

void Print(LinkQueue * L)
{
    LinkQueue P;
    P=(*L)->next;
    printf("��ǰ����:\n");
    while(P!=(*L))
    {
        printf("%d ",P->data);
        P=P->next;
    }
    printf("\n");
}


int main()
{
    LinkQueue L;
    int ElemNumber;
    QElemType EnElem,DeElem;
    InitLinkQueue(&L);
    printf("������Ԫ�ظ�����\n");
    scanf("%d",&ElemNumber);
    Create(&L,ElemNumber);
    Print(&L);
    printf("���������Ԫ�أ�\n");
    scanf("%d",&EnElem);
    EnQueue(&L,EnElem);
    DeQueue(&L,&DeElem);
    printf("����Ԫ��Ϊ��%d\n",DeElem);
    Print(&L);
    return 0;
}

