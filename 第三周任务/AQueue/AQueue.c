#include<stdio.h>
#include<stdlib.h>
#include"./AQueue.h"

/**
 *  @name        : void InitAQueue(AQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitAQueue(AQueue *Q){
	if(Q->length>10||Q->length<0||Q->front>100||Q->front<0){
	Q->front=0;
	Q->length=0;
	Q->rear=0;
	}
	else{
		printf("再次初始化前请先销毁原队列哟！\n"); 
	} 
 		
}


/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryAQueue(AQueue *Q){
	int i; 
	if(Q->length>10||Q->length<0||Q->front>100||Q->front<0) printf("队列没有初始化，不需要销毁哟！\n");
	else{
		if(Q->length==0){
		for(i=0;i<=9;i++) Q->data[i]=NULL;
		Q->length=10000;
		}
		else printf("请先清空队列哟！\n"); 
	}

}



/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : 检查队列是否已满
 *    @param         Q 队列指针Q
 *    @return         : 满-TRUE; 未满-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue *Q){
	if(Q->length>10||Q->length<0||Q->front>100||Q->front<0) {
	printf("请先初始化队列哟！\n");
	return FALSE;	
	}
	else{
		if(Q->length==10) return TRUE;
		else return FALSE;
	}
}

/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue *Q){
	if(Q->length>10||Q->length<0||Q->front>100||Q->front<0) printf("请先初始化队列哟！\n");
	else{
		if(Q->length==0&&Q->front==0) return TRUE;
		else return FALSE;
	}
}



/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q 队列指针Q，存放元素e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadAQueue(AQueue *Q, void *e){
	if(Q->length>10||Q->length<0||Q->front>100||Q->front<0) {
		printf("请先初始化队列哟！\n");
		return FALSE;
	}
	else{
		if(Q->length==0) {
		printf("该队列为空队列，没有头元素！\n"); 
		return FALSE;	
		}
		else{
		return TRUE;
		} 
	}
}		



/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 队列长度count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q){
	if(Q->length>10||Q->length<0||Q->front>100||Q->front<0) {
		printf("请先初始化队列哟！\n");
		return 10000;
	}
	else return Q->length;
}	



/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否满了或为空
 */
Status EnAQueue(AQueue *Q, void *data){
	if(Q->length>10||Q->length<0||Q->front>100||Q->front<0) {
		printf("请先初始化队列哟！\n");
		return FALSE;
	}
	else{
		int i=Q->rear;
		if(Q->rear<=9)
		Q->data[Q->rear++]=data;
		else  {
			printf("队列已满啦~\n"); return FALSE;
		}
		
		if(Q->data[i]==data){
			Q->length++;
			return TRUE;
		} 
		else return FALSE;
	}
}



/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue *Q){
	if(Q->length>10||Q->length<0||Q->front>100||Q->front<0) {
		printf("请先初始化队列哟！\n");
		return FALSE;
	}
	else{
	if(Q->length==0) {
		printf("该队列为空队列哟！\n");	
	return FALSE; 
	}
	else{
	int i=Q->front+1;
	free(Q->data[Q->front++]);
	if(Q->data[Q->front]==Q->data[i]) {
		Q->length--;
		return TRUE;
	}
	
	else return FALSE;	
	}
	}
}	



/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q){
	if(Q->length>10||Q->length<0||Q->front>100||Q->front<0) {
		printf("请先初始化队列哟！\n");
		
	}
	else{
		if(Q->length==0&&Q->front==0) {
			printf("该队列已经是空队列啦~\n");
			
		}
		else{
			int i;
			if(Q->rear>Q->front) for(i=Q->front;i<Q->rear;i++) free(Q->data[i]);
			else {
				for(i=0;i<Q->rear;i++) free(Q->data[i]);
				for(i=Q->front;i<=9;i++) free(Q->data[i]);
			}
			Q->length=0;
			Q->front=0;
			Q->rear=0;
		}	
	}
}	



/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q)){
	if(Q->length>10||Q->length<0||Q->front>100||Q->front<0) {
		printf("请先初始化队列哟！\n");
		return FALSE;
	}
	else{
		if(Q->length==0) {
			printf("该队列是空队列哟~\n");
			return FALSE;
		}
		else{
			int i=100;
			if(Q->rear>Q->front) for(i=Q->front;i<Q->rear;i++) foo(Q->data[i]);
			else {
				for(i=Q->front;i<=9;i++) foo(Q->data[i]);
				for(i=0;i<Q->rear;i++) foo(Q->data[i]);
			}
			if(i!=100) return TRUE;
		else return FALSE;
}	}
		
}



/**
 *  @name        : void APrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 *  @notice      : None
 */
void APrint(void *q){
	printf("%s\n",(char*)q);
}	

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
// AQUEUE_H_INCLUDED


