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
	printf("请输入题目中的i,j,len(数字以空格隔开)\n");
	scanf("%d%d%d", &i, &j, &len);
	printf("请输入链表la元素，输入-1停止输入\n"); 
	la = creat_Linklist();
	printf("请输入链表lb元素，输入-1停止输入\n"); 
	lb = creat_Linklist();
	Delete(la, lb, i, len, j);
	printf("新的la链表：\n");
	Print(la);
	printf("新的lb链表：\n");
	Print(lb);
	return 0;
}
