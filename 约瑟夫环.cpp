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
	printf("请输入圆桌周围人的个数\n");
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
	printf("请输入初始最大值\n");
	scanf("%d", &m);
	getchar();
	printf("请输入循环方向（顺时针输入S，逆时针输入N）\n");
	scanf("%c", &c);
	srand((unsigned)time(NULL));
	first = rand() % n + 1;
	printf("随机生成的第一个报数的人是第%d个人\n", first);
	if(c == 'S'){
		for(i = 0; i < first; i++){
			pTemp = pTemp->next;
		}
		while(pTemp->next != pTemp){
			for(i = 1; i < m; i++){
				pTemp = pTemp->next;
			}
			m = pTemp->data;
			printf("第%d个出列的人是第%d个人，所持有的密码值为%d\n", count, pTemp->num, m);
			pTemp->prior->next = pTemp->next;
			pTemp->next->prior = pTemp->prior;
			pTemp = pTemp->next;
			count++;
		}
		printf("最后一个出列的人是第%d个人，所持有的密码值为%d\n", pTemp->num, pTemp->data);
	} else if(c == 'N'){
		for(i = 0; i < first; i++){
			pTemp = pTemp->next;
		}
		while(pTemp->next != pTemp){
			for(i = 1; i < m; i++){
				pTemp = pTemp->prior;
			}
			m = pTemp->data;
			printf("第%d个出列的人是第%d个人，所持有的密码值为%d\n", count, pTemp->num, m);
			pTemp->prior->next = pTemp->next;
			pTemp->next->prior = pTemp->prior;
			pTemp = pTemp->prior;
			count++;
		}
		printf("最后一个出列的人是第%d个人，所持有的密码值为%d\n", pTemp->num, pTemp->data);
	} else{
		printf("输入循环方向信息有误\n");
		exit(1);
	}
	return 0;
}
