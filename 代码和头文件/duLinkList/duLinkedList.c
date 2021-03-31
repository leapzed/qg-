#include "./duLinkedList.h"
#include<stdio.h>
#include<stdlib.h>
/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) {
	ElemType a=1;
     (*L)->prior=NULL; 
     (*L)->data=a;
     (*L)->next=NULL;
     if((*L)->data==1&&(*L)->prior==NULL&&(*L)->next==NULL) return SUCCESS;
     else return ERROR;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {
	DuLinkedList p1,p2;
	p1=p2=(DuLinkedList)malloc(sizeof(DuLNode));
	if((*L)->next==NULL) free(*L);
	else{
	p1=*L;
	p2=(*L)->next;
	free(p1); 
	while(p2->next!=NULL)
	{
		p2->prior=NULL;
		p1=p2;
		p2=p2->next;
		free(p1);
	}
	free(p2);}
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
	ElemType a;
	if(p->prior==NULL){
	q->prior=NULL;
	q->next=p;
	p->prior=q;	
	if(p->prior!=NULL) {
	return SUCCESS;}
	else return ERROR;
	}
	else{
		
		a=p->prior->data;
		q->prior=p->prior;
		p->prior->next=q;
		q->next=p;
		p->prior=q;
	}
	if(p->prior->data==a) return ERROR;
	else return SUCCESS;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
	ElemType a;
	if(p->next==NULL) {
		p->next=q;
		q->next=NULL;
		q->prior=p;
		if(p->next!=NULL) return SUCCESS;
		else return ERROR; 
	}
	else{
	a=p->next->data;
	p->next->prior=q;
	q->next=p->next;
	p->next=q;
	q->prior=p;
}
	if(p->next->data==a) return ERROR;
	else return SUCCESS;	
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
	*e=p->data;
	if(p->prior==NULL);
	else{
	if(p->next==NULL) p->prior->next=NULL;
	else{
	p->next->prior=p->prior;
	p->prior->next=p->next;
	}}
	free(p);
	if(p->data!=*e) {printf("所删除结点的数据为%d\n",*e);
	return SUCCESS;}
	else return ERROR;
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
 
  void print(ElemType e){
 	printf("%d\n",e);
 }
 
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
	visit(L->data);
	while(L->next!=NULL) 	{
	L=L->next;
	visit(L->data);
	}
	if(L->next==NULL) printf("遍历完成！\n");
	else printf("遍历失败！\n");
}
