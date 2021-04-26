#include<stdio.h>
#include<stdlib.h>
#include"../inc/AQueue.h"

/**
 *  @name        : void InitAQueue(AQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitAQueue(AQueue *Q){
	if(Q->length>10||Q->length<0||Q->front>100||Q->front<0){
	Q->front=0;
	Q->length=0;
	Q->rear=0;
	}
	else{
		printf("�ٴγ�ʼ��ǰ��������ԭ����Ӵ��\n"); 
	} 
 		
}


/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryAQueue(AQueue *Q){
	int i; 
	if(Q->length>10||Q->length<0||Q->front>100||Q->front<0) printf("����û�г�ʼ��������Ҫ����Ӵ��\n");
	else{
		if(Q->length==0){
		for(i=0;i<=9;i++) Q->data[i]=NULL;
		Q->length=10000;
		}
		else printf("������ն���Ӵ��\n"); 
	}

}



/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : �������Ƿ�����
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue *Q){
	if(Q->length>10||Q->length<0||Q->front>100||Q->front<0) {
	printf("���ȳ�ʼ������Ӵ��\n");
	return FALSE;	
	}
	else{
		if(Q->length==10) return TRUE;
		else return FALSE;
	}
}

/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue *Q){
	if(Q->length>10||Q->length<0||Q->front>100||Q->front<0) printf("���ȳ�ʼ������Ӵ��\n");
	else{
		if(Q->length==0&&Q->front==0) return TRUE;
		else return FALSE;
	}
}



/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q ����ָ��Q�����Ԫ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadAQueue(AQueue *Q, void *e){
	if(Q->length>10||Q->length<0||Q->front>100||Q->front<0) {
		printf("���ȳ�ʼ������Ӵ��\n");
		return FALSE;
	}
	else{
		if(Q->length==0) {
		printf("�ö���Ϊ�ն��У�û��ͷԪ�أ�\n"); 
		return FALSE;	
		}
		else{
		return TRUE;
		} 
	}
}		



/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : ���г���count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q){
	if(Q->length>10||Q->length<0||Q->front>100||Q->front<0) {
		printf("���ȳ�ʼ������Ӵ��\n");
		return 10000;
	}
	else return Q->length;
}	



/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ����˻�Ϊ��
 */
Status EnAQueue(AQueue *Q, void *data){
	if(Q->length>10||Q->length<0||Q->front>100||Q->front<0) {
		printf("���ȳ�ʼ������Ӵ��\n");
		return FALSE;
	}
	else{
		int i=Q->rear;
		if(Q->rear<=9)
		Q->data[Q->rear++]=data;
		else  {
			printf("����������~\n"); return FALSE;
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
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue *Q,int *e){
	if(Q->length>10||Q->length<0||Q->front>100||Q->front<0) {
		printf("���ȳ�ʼ������Ӵ��\n");
		return FALSE;
	}
	else{
	if(Q->length==0) {
		printf("�ö���Ϊ�ն���Ӵ��\n");	
	return FALSE; 
	}
	else{
	int i=Q->front+1;
	*e=*(Q->data[Q->front]);
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
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q){
	if(Q->length>10||Q->length<0||Q->front>100||Q->front<0) {
		printf("���ȳ�ʼ������Ӵ��\n");
		
	}
	else{
		if(Q->length==0&&Q->front==0) {
			printf("�ö����Ѿ��ǿն�����~\n");
			
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
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q)){
	if(Q->length>10||Q->length<0||Q->front>100||Q->front<0) {
		printf("���ȳ�ʼ������Ӵ��\n");
		return FALSE;
	}
	else{
		if(Q->length==0) {
			printf("�ö����ǿն���Ӵ~\n");
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
 *    @description : ��������
 *    @param         q ָ��q
 *  @notice      : None
 */
void APrint(void *q){
	printf("%s\n",(char*)q);
}	

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
// AQUEUE_H_INCLUDED


