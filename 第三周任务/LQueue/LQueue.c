#include<stdio.h>
#include<stdlib.h>
#include"./LQueue.h"


/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q){

	Q->length=0;
	Q->front->next=NULL;
	Q->rear->next=NULL;	

	
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q){
	if(Q->length>1000||Q->length<0){
		printf("���ȳ�ʼ������Ӵ~\n");
	}
	else{
		if(Q->length!=0) printf("������ն���Ӵ~\n");
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
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q){
	if(Q->length>1000||Q->length<0){
		printf("���л�û�б���ʼ��Ӵ~\n");
		return FALSE;
	}
	else{
		if(Q->length==0&&Q->rear->next==NULL) return TRUE;
		else return FALSE;
	}
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadLQueue(LQueue *Q, void *e){
	if(Q->length>1000||Q->length<0){
		printf("���л�û�б���ʼ��Ӵ~\n");
			return FALSE;
	}
		else{
			if(Q->length==0&&Q->rear->next==NULL) {
			printf("�ö����ǿն���QAQ\n");	
			return FALSE;
			}
			else return TRUE;
			
		}
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q){
	if(Q->length>1000||Q->length<0){
		printf("���л�û�б���ʼ��Ӵ~\n");
			return 0;
	}
		else{
			if(Q->length==0&&Q->rear->next==NULL) {
			printf("�ö����ǿն���QAQ\n");	
			return 0;
			}
			else return Q->length;
			}
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue *Q, void *data){
	if(Q->length>1000||Q->length<0){
		printf("���л�û�б���ʼ��Ӵ~\n");
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
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q){
	int a=Q->length;
	if(Q->length>1000||Q->length<0){
		printf("���л�û�б���ʼ��Ӵ~\n");
			return FALSE;
	}
		else{
			if(Q->length==0&&Q->rear->next==NULL) {
			printf("�ö����ǿն���QAQ\n");	
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
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q){
	if(Q->length>1000||Q->length<0){
		printf("���л�û�б���ʼ��Ӵ~\n");
	}
		else{
			if(Q->length==0&&Q->rear->next==NULL) {
			printf("�ö����Ѿ��ǿն�����~\n");	
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
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)){
	if(Q->length>1000||Q->length<0){
		printf("���л�û�б���ʼ��Ӵ~\n");
			return FALSE;
	}
		else{
			if(Q->length==0&&Q->rear->next==NULL) {
			printf("�ö����Ѿ��ǿն�����~\n");	
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
 *    @description : ��������
 *    @param         q ָ��q
 
 *  @notice      : None
 */
void LPrint(void *q){
	printf("%s\n",(char*)q);
}

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
