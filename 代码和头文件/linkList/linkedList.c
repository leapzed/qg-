#include<stdlib.h>
#include<stdio.h> 
#include "./linkedList.h"

/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {
    int a=1;
    (*L)->data=a;
    (*L)->next=NULL;
    if((*L)->data==1&&(*L)->next==NULL) {
	return SUCCESS;}
    else return ERROR;

}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
	LNode *p1,*p2;                         //��������ָ��ṹ���ָ�� 
	p1=p2=(LinkedList)malloc(sizeof(LNode));
	p1=*L;
	p2=*L;
	while(p1->next!=NULL){                   //��p1->next��Ϊ��ʱִ��ѭ�� 
	p1=p1->next;
	free(p2);                                //�ͷ�p2ָ��ڵ��ڴ� 
	p2=p1;
	}
	free(p1);                                //��p1->nextΪ��ָ��ʱ��p1ָ������δ�ͷţ������ͷ�p1ָ������ڴ� 
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
	  	q->next=p->next;                             //��p->nextԭ��ָ��Ľ�㸳��q->next 
	  	p->next=q;                                   //p->nextָ��q��� 
	  	if(p->next->data==q->data) return SUCCESS;   //�ж�p->next->data�����Ƿ��q->dataһ�£��ǵĻ�����1 
	  	else return ERROR; 
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {
	LinkedList p1;                         //����һ��ָ��ṹ���ָ�벢���ؿռ� 
	p1=(LinkedList)malloc(sizeof(LNode));
	p1=p;
	if(p->next==NULL){                     //�ж�p->next�Ƿ�Ϊ��ָ�� 
	*e=p1->data;
    free(p);
	p=NULL;
	if (p==NULL) {
	printf("��ɾ����������Ϊ%d\n",*e);
	return SUCCESS; }
	else return ERROR;
	}
	else{
	p1=p->next;                            //��p1ָ��p��ĵ�һ����� 
	*e=p1->data;                           //��Ҫɾ���������ݸ�*e 
	p->next=p1->next;                      //��p->nextָ��p1->next 
	free(p1);}
	
	if(p->next==NULL||p->next->data!=(*e)) //ͨ����p->next��p->next->data�ж��Ƿ�ɾ���ɹ� 
	{ printf("��ɾ����������Ϊ%d\n",*e);
	return SUCCESS;}
	else return ERROR;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
 void print(ElemType e){
 	printf("%d\n",e);
 }
 
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
	visit(L->data);
	while(L->next!=NULL) 	{
	L=L->next;
	visit(L->data);
	}
	if(L->next==NULL) printf("������ɣ�\n");
	else printf("����ʧ�ܣ�\n");
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
	ElemType i=1;                              //����һ�����ͱ������ڽ��к���ѭ�� 
	if(e==1){
		if(L->data>0&&L->data<1000) return SUCCESS;
		else return ERROR;
	} 
	if(e==0){
		return SUCCESS;
	}
	for(;i<e&&L!=NULL&&L->next!=NULL;i++){         //ͨ��ѭ���ж�L�ܷ�ָ���e����� 
	L=L->next;	                        
	}
	if(i==e){                                //���������e-1��ѭ������˵���ý����� 
	return SUCCESS;
}
	else return ERROR;
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
	LinkedList p1,p2;                           //��������ָ��ṹ���ָ�� 
	ElemType m,n;                               //�����������ͱ��������洢ԭ����һ�ڶ��������� 
	if((*L)->next!=NULL){
	m=(*L)->data;
	n=(*L)->next->data; 
	p1=p2=(LinkedList)malloc(sizeof(LNode));    
	p1=*L;                                      //p1ָ��ͷ��� 
	p2=(*L)->next;                              //p2ָ��ͷ���ĺ�һ����� 
	*L=(*L)->next;                              //ͷ���λ�øı� 
	p1->next=NULL;                              //ԭͷ����next��ֵΪ��ָ�� 
	for(;p2->next!=NULL;){                      //��p2->next��Ϊ��ָ�룬�����ѭ�� 
		*L=(*L)->next;                          //ͷ���λ�ü������� 
		p2->next=p1;                            //������Ľ���ǰ��Ľ��ͨ��p2������������ 
		p1=p2;                                  //ʹp1��Ȼ�̶���p2ǰ���һ����㣬�������� 
		p2=*L;                                  //���½�p2��Lָ��ͬһ��λ�� 
	}
	(*L)->next=p1;                              //����ת������ĵ�һ�͵ڶ�������������� 
	for(;p1->next!=NULL;){                      //ͨ��������ʹ��p1��p2�ֱ�ָ��ԭ����ĵ�һ�͵ڶ������  
		p1=p1->next;
		p2=p2->next;
	}
	if((p1->data)==m&&(p2->data)==n) return SUCCESS;  //��m��n��ԭ����ĵ�һ�ڶ������бȽϣ������ͬ��˵����ת��� 
	else return ERROR;}
	else printf("������ֻ��һ����㣡\n"); 
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
	LinkedList p1,p2;                    //��������ָ�������p1��һ����p2������ 
	ElemType a=0,k=999;                      //k�����洢����ָ��������ͬʱ�����ݣ������ж�ָ��������ͬʱ��Ӧ��������k 
	if(L->next==NULL) return ERROR;
	else{
	p1=p2=(LinkedList)malloc(sizeof(LNode));     //���ؿռ� 
	p1=L;
	p2=L->next;
	while(1){
	p1=p1->next;
	if(p2!=NULL&&p2->next!=NULL) {if(p2->next->next==NULL)  return ERROR;
	else p2=p2->next->next;   //��������֮ǰ�ж��ܲ��������� 
	}
	else return ERROR;
	if(p2->data==k&&p1->data==k) return SUCCESS;  //��ÿ��ָ��ָ��������ͬʱ�����ݶ���k����˵������ѭ�� 
	if(p2->data==p1->data) k=p1->data;
	if(a++>200) return ERROR;
	}}
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L) {
	LNode *p1,*p2;                          //��������ָ��ṹ���ָ�� 
	if((*L)->next!=NULL){                   //�ж������Ƿ�ֻ��һ����� 
	p1=p2=(LNode*)malloc(sizeof(LNode));    
	p1=(*L);                                //��ͷ���͵ڶ�����������⴦�� 
	p2=(*L)->next;
 	*L=p2;
	p1->next=p2->next;
	p2->next=p1;                                          
	while(p1->next!=NULL){                   
		p2=p1->next->next;                  //�Ȱ�p2��ż�����λ���ҳ��� 
		if(p2==NULL) break;                 //�ж�p1->next->next�Ƿ�Ϊ��ָ�� 
		p1->next->next=p2->next;            //����������next����ż��������һ������� 
		p2->next=p1->next;                  //��ż������next������������� 
		p1->next=p2;                        //������ѭ����ż�����������һ��ѭ���������ڵ��� 
		p1=p2->next;                        //p1����ָ����ÿ��ѭ������������ 
	}}
	    else printf("������ֻ��һ����㣡\n"); 
	
	if((*L)->data!=1) printf("��ż��ת�ɹ���\n");
	else printf("��ż��תʧ�ܣ�\n"); 
	return *L;
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {
	LinkedList p1,p2;                         //��������ָ��ṹ���ָ�� 
	if
	p1=p2=(LinkedList)malloc(sizeof(LNode));
	p1=p2=*L;                                 //������ָ��ָ����ͬһ���ͷ����� 
	while(p2!=NULL&&p2->next!=NULL)           //ֻҪp2��p2->next��Ϊ��ָ�룬ִ��ѭ��   
	{             
	p1=p1->next;                              //p2�ƶ����ٶ���p1������ 
	p2=p2->next->next;
	}
	return p1;                                 //p2������ָ��ʱ����������ʱ��p1���ô����м����λ�� 
}

