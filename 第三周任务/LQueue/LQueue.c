#include<stdio.h>
#include<stdlib.h>
#include"./LQueue.h"


/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q){

	Q->length=0;
	Q->front->next=NULL;
	Q->rear->next=NULL;	

	
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q){
	if(Q->length>1000||Q->length<0){
		printf("请先初始化队列哟~\n");
	}
	else{
		if(Q->length!=0) printf("请先清空队列哟~\n");
		else {
		 while (Q->front->next!=NULL)
   		 {
        Q->rear = Q->front->next;
        free(Q->front);
        Q->front = Q->rear;
   		 }
        free(Q->front);
		Q->length=10000;
		}
	}
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q){
	if(Q->length>1000||Q->length<0){
		printf("队列还没有被初始化哟~\n");
		return FALSE;
	}
	else{
		if(Q->length==0&&Q->rear->next==NULL) return TRUE;
		else return FALSE;
	}
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue *Q, void *e){
	if(Q->length>1000||Q->length<0){
		printf("队列还没有被初始化哟~\n");
			return FALSE;
	}
		else{
			if(Q->length==0&&Q->rear->next==NULL) {
			printf("该队列是空队列QAQ\n");	
			return FALSE;
			}
			else return TRUE;
			
		}
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q){
	if(Q->length>1000||Q->length<0){
		printf("队列还没有被初始化哟~\n");
			return 0;
	}
		else{
			if(Q->length==0&&Q->rear->next==NULL) {
			printf("该队列是空队列QAQ\n");	
			return 0;
			}
			else return Q->length;
			}
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue *Q, void *data){
	if(Q->length>1000||Q->length<0){
		printf("队列还没有被初始化哟~\n");
			return FALSE;
	}
	else {
	Node *p;
	p=(Node*)malloc(sizeof(Node));
	p->data=data;
	p->next=NULL;
	Q->rear->next=p;
	Q->rear=p;
	if(p->data==data) {
		Q->length++;
		return TRUE;
	}
	else return FALSE;	
	}
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q){
	int a=Q->length;
	if(Q->length>1000||Q->length<0){
		printf("队列还没有被初始化哟~\n");
			return FALSE;
	}
		else{
			if(Q->length==0&&Q->rear->next==NULL) {
			printf("该队列是空队列QAQ\n");	
			return FALSE;
			}
			else{
				if(Q->front->next!=NULL){
				Node *p;
			p=Q->front;
			Q->front=Q->front->next;
			free(p);	
				}
				else 
			{
				free(Q->front->data);
				free(Q->rear->data);
				Q->length--;
			}
			}
		if(a==Q->length-1) return TRUE;
		else return FALSE;	
		}
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q){
	if(Q->length>1000||Q->length<0){
		printf("队列还没有被初始化哟~\n");
	}
		else{
			if(Q->length==0&&Q->rear->next==NULL) {
			printf("该队列已经是空队列啦~\n");	
			}
			else{
				Node *p,*q;
				q=p=Q->front;
				if(p->next!=NULL) {
				q=p->next;
				p->next=NULL;
				p=q;	
				} 
				p->next=NULL;
				Q->length=0; 
			}
//			if(Q->length==0&&Q->front->next==NULL&&Q->rear->next==NULL) return TRUE;
//			else return FALSE;	
		}
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)){
	if(Q->length>1000||Q->length<0){
		printf("队列还没有被初始化哟~\n");
			return FALSE;
	}
		else{
			if(Q->length==0&&Q->rear->next==NULL) {
			printf("该队列已经是空队列啦~\n");	
			return FALSE;
			}
			else{
				Node *p;
				p=Q->front->next;
				while(p->next!=NULL) {
					foo(p->data);
					p=p->next;
				}
				foo(p->data);
			if(p->data==Q->rear->data) return TRUE;
			else return FALSE;
			}
			
		}
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 
 *  @notice      : None
 */
void LPrint(void *q){
	printf("%s\n",(char*)q);
}

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
