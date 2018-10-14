#include <stdio.h>
#include <stdlib.h> 
typedef struct node{
	int data;
	struct node *next; 
} LNode, *LinkList;

LinkList creat_Linklist(){
	LNode *s, *r, *H;
	int x, i = 0;
	scanf("%d", &x);
	while(x != -1){
		if(i == 0){
			r = H = s = (LinkList)malloc(sizeof(LNode));
			s->data = x;
			r = s;
		} else{
			s = (LinkList)malloc(sizeof(LNode));
			s->data = x;
			r->next = s;
			r = s;
		}
		scanf("%d", &x);
		i++;
	} 
	r->next = NULL;
	return H;
}

void Delete(LinkList la, LinkList lb, int i, int len, int j){
	LNode *R, *T, *t;
	while(i-1){
		la = la->next;
		i--;
	}
	R = la;
	T = la->next;
	while(len){
		la = la->next;
		len--;
	}
	R->next = la->next;
	while(j-1){
		lb = lb->next;
		j--;
	}
	t = lb->next;
	lb->next = T;
	la->next = t;
}

void Print(LinkList t){
	while(t != NULL){
		printf("%d ", t->data);
		t = t->next;
	}
	printf("\n");
}
 
int main(){
	LinkList la, lb;
	int i, j, len;
	printf("��������Ŀ�е�i,j,len(�����Կո����)\n");
	scanf("%d%d%d", &i, &j, &len);
	printf("����������laԪ�أ�����-1ֹͣ����\n"); 
	la = creat_Linklist();
	printf("����������lbԪ�أ�����-1ֹͣ����\n"); 
	lb = creat_Linklist();
	Delete(la, lb, i, len, j);
	printf("�µ�la����\n");
	Print(la);
	printf("�µ�lb����\n");
	Print(lb);
	return 0;
}
