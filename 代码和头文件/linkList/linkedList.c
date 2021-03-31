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
	LNode *p1,*p2;                         //定义两个指向结构体的指针 
	p1=p2=(LinkedList)malloc(sizeof(LNode));
	p1=*L;
	p2=*L;
	while(p1->next!=NULL){                   //在p1->next不为空时执行循环 
	p1=p1->next;
	free(p2);                                //释放p2指向节点内存 
	p2=p1;
	}
	free(p1);                                //当p1->next为空指针时，p1指向结点仍未释放，这里释放p1指向结点的内存 
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
	  	q->next=p->next;                             //将p->next原本指向的结点赋给q->next 
	  	p->next=q;                                   //p->next指向q结点 
	  	if(p->next->data==q->data) return SUCCESS;   //判断p->next->data内容是否和q->data一致，是的话返回1 
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
	LinkedList p1;                         //定义一个指向结构体的指针并开拓空间 
	p1=(LinkedList)malloc(sizeof(LNode));
	p1=p;
	if(p->next==NULL){                     //判断p->next是否为空指针 
	*e=p1->data;
    free(p);
	p=NULL;
	if (p==NULL) {
	printf("所删除结点的数据为%d\n",*e);
	return SUCCESS; }
	else return ERROR;
	}
	else{
	p1=p->next;                            //将p1指向p后的第一个结点 
	*e=p1->data;                           //将要删除结点的数据给*e 
	p->next=p1->next;                      //将p->next指向p1->next 
	free(p1);}
	
	if(p->next==NULL||p->next->data!=(*e)) //通过对p->next及p->next->data判断是否删除成功 
	{ printf("所删除结点的数据为%d\n",*e);
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
	if(L->next==NULL) printf("遍历完成！\n");
	else printf("遍历失败！\n");
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
	ElemType i=1;                              //定义一个整型变量用于进行后续循环 
	if(e==1){
		if(L->data>0&&L->data<1000) return SUCCESS;
		else return ERROR;
	} 
	if(e==0){
		return SUCCESS;
	}
	for(;i<e&&L!=NULL&&L->next!=NULL;i++){         //通过循环判断L能否指向第e个结点 
	L=L->next;	                        
	}
	if(i==e){                                //如果经过了e-1次循环，则说明该结点存在 
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
	LinkedList p1,p2;                           //定义两个指向结构体的指针 
	ElemType m,n;                               //定义两个整型变量用来存储原来第一第二结点的数据 
	if((*L)->next!=NULL){
	m=(*L)->data;
	n=(*L)->next->data; 
	p1=p2=(LinkedList)malloc(sizeof(LNode));    
	p1=*L;                                      //p1指向头结点 
	p2=(*L)->next;                              //p2指向头结点的后一个结点 
	*L=(*L)->next;                              //头结点位置改变 
	p1->next=NULL;                              //原头结点的next赋值为空指针 
	for(;p2->next!=NULL;){                      //若p2->next不为空指针，则进行循环 
		*L=(*L)->next;                          //头结点位置继续后移 
		p2->next=p1;                            //将后面的结点和前面的结点通过p2重新连接起来 
		p1=p2;                                  //使p1仍然固定在p2前面的一个结点，方便连接 
		p2=*L;                                  //重新将p2与L指向同一个位置 
	}
	(*L)->next=p1;                              //将反转后链表的第一和第二个结点连接起来 
	for(;p1->next!=NULL;){                      //通过遍历，使得p1，p2分别指向原链表的第一和第二个结点  
		p1=p1->next;
		p2=p2->next;
	}
	if((p1->data)==m&&(p2->data)==n) return SUCCESS;  //用m，n与原链表的第一第二结点进行比较，如果相同，说明反转完成 
	else return ERROR;}
	else printf("该链表只有一个结点！\n"); 
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
	LinkedList p1,p2;                    //定义两个指针变量，p1走一步，p2走两步 
	ElemType a=0,k=999;                      //k用来存储两个指针数据相同时的数据，便于判断指针数据相同时对应的数都是k 
	if(L->next==NULL) return ERROR;
	else{
	p1=p2=(LinkedList)malloc(sizeof(LNode));     //开拓空间 
	p1=L;
	p2=L->next;
	while(1){
	p1=p1->next;
	if(p2!=NULL&&p2->next!=NULL) {if(p2->next->next==NULL)  return ERROR;
	else p2=p2->next->next;   //在走两步之前判断能不能走两步 
	}
	else return ERROR;
	if(p2->data==k&&p1->data==k) return SUCCESS;  //若每次指针指向数据相同时，数据都是k，则说明链表循环 
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
	LNode *p1,*p2;                          //定义两个指向结构体的指针 
	if((*L)->next!=NULL){                   //判断链表是否只有一个结点 
	p1=p2=(LNode*)malloc(sizeof(LNode));    
	p1=(*L);                                //将头结点和第二个结点先特殊处理 
	p2=(*L)->next;
 	*L=p2;
	p1->next=p2->next;
	p2->next=p1;                                          
	while(p1->next!=NULL){                   
		p2=p1->next->next;                  //先把p2是偶数结点位置找出来 
		if(p2==NULL) break;                 //判断p1->next->next是否为空指针 
		p1->next->next=p2->next;            //将奇数结点的next连到偶数结点的下一个结点上 
		p2->next=p1->next;                  //将偶数结点的next连到奇数结点上 
		p1->next=p2;                        //将本次循环的偶数结点连到上一次循环的奇数节点上 
		p1=p2->next;                        //p1重新指向在每次循环后的奇数结点 
	}}
	    else printf("该链表只有一个结点！\n"); 
	
	if((*L)->data!=1) printf("奇偶反转成功！\n");
	else printf("奇偶反转失败！\n"); 
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
	LinkedList p1,p2;                         //定义两个指向结构体的指针 
	if
	p1=p2=(LinkedList)malloc(sizeof(LNode));
	p1=p2=*L;                                 //将两个指针指向在同一起点头结点上 
	while(p2!=NULL&&p2->next!=NULL)           //只要p2和p2->next不为空指针，执行循环   
	{             
	p1=p1->next;                              //p2移动的速度是p1的两倍 
	p2=p2->next->next;
	}
	return p1;                                 //p2遇到空指针时，跳出，此时的p1正好处于中间结点的位置 
}

