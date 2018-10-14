#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
typedef struct node{
	int data, key, num;
	struct node *next, *prior; 
} LNode, *LinkList;
int n;

LinkList creat_LinklistL(){
	LinkList H = (LinkList)malloc(sizeof(LNode));
	H->next = NULL;
	LNode *s, *r = H;
	int x, i;
	srand((unsigned)time(NULL));
	printf("������Բ����Χ�˵ĸ���\n");
	scanf("%d", &n);
	for(i = 1; i <= n; i++){
		x = rand() % n + 1;
		s = (LinkList)malloc(sizeof(LNode));
		s->data = x;
		s->num = i;
		r->next = s;
		s->prior = r;
		r = s;
	} 
	r->next = H->next;
	H->next->prior = r;
	return H;
}

int main(){
	int m, first, i, count = 1;
	char c;
	LNode *pHead, *pTemp;
	pTemp = pHead = creat_LinklistL();
	printf("�������ʼ���ֵ\n");
	scanf("%d", &m);
	getchar();
	printf("������ѭ������˳ʱ������S����ʱ������N��\n");
	scanf("%c", &c);
	srand((unsigned)time(NULL));
	first = rand() % n + 1;
	printf("������ɵĵ�һ�����������ǵ�%d����\n", first);
	if(c == 'S'){
		for(i = 0; i < first; i++){
			pTemp = pTemp->next;
		}
		while(pTemp->next != pTemp){
			for(i = 1; i < m; i++){
				pTemp = pTemp->next;
			}
			m = pTemp->data;
			printf("��%d�����е����ǵ�%d���ˣ������е�����ֵΪ%d\n", count, pTemp->num, m);
			pTemp->prior->next = pTemp->next;
			pTemp->next->prior = pTemp->prior;
			pTemp = pTemp->next;
			count++;
		}
		printf("���һ�����е����ǵ�%d���ˣ������е�����ֵΪ%d\n", pTemp->num, pTemp->data);
	} else if(c == 'N'){
		for(i = 0; i < first; i++){
			pTemp = pTemp->next;
		}
		while(pTemp->next != pTemp){
			for(i = 1; i < m; i++){
				pTemp = pTemp->prior;
			}
			m = pTemp->data;
			printf("��%d�����е����ǵ�%d���ˣ������е�����ֵΪ%d\n", count, pTemp->num, m);
			pTemp->prior->next = pTemp->next;
			pTemp->next->prior = pTemp->prior;
			pTemp = pTemp->prior;
			count++;
		}
		printf("���һ�����е����ǵ�%d���ˣ������е�����ֵΪ%d\n", pTemp->num, pTemp->data);
	} else{
		printf("����ѭ��������Ϣ����\n");
		exit(1);
	}
	return 0;
}
