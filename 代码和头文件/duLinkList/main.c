#include<stdio.h>
#include<stdlib.h>
#include "./duLinkedList.h"
void main(){
	DuLinkedNode *head;
	int i,n,a=1;
	head=(DuLinkedNode) 
	scanf("%d",&n);
	head=p1=p2=(DuLNode*)malloc(sizeof(DuLNode));
	head->prior=NULL;
	head->data=a++;
	p1=head;
	p2->prior=head;
	p1->next=p2; 
	p1=p2;
	for(i=2;i<=n;i++)
    {
	 p1->data=a++;
     p2=(DuLNode*)malloc(sizeof(DuLNode));
	 p2->prior=p1;
	 p1->next=p2;
	 p1=p2;	
	}
	p1->data=a;
	p1->next=NULL;
	printf("创建成功!\n"); 
}

