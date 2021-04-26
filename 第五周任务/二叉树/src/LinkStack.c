#include <stdio.h>
#include <stdlib.h>
#include "../inc/LinkStack.h"




//��ʼ��ջ
Statuss initLStack(LinkStack *s){
//	if(s->count>1000||s->count<0) {
		s->top=(LinkStackPtr)malloc(sizeof(StackNode));
	s->count=0;
	s->top->data=0;
	s->top->next=NULL;	
//	}
//	else printf("������յ�ԭ�е�ջ�ٳ�ʼ��Ӵ��\n");
//	if(s->count==0) return SUCCESS;
//	else return ERROR;
}

//�ж�ջ�Ƿ�Ϊ��
Statuss isEmptyLStack(LinkStack *s){
	if(s->count!=0) return ERROR;
	else return SUCCESS;
}

//�õ�ջ��Ԫ��
Statuss getTopLStack(LinkStack *s,ElemType *e){
	ElemType a=*e;
	if(s->count>1000||s->count<0)
	printf("���ȳ�ʼ����ջӴ��\n");
	else {
		if(s->count==0) printf("��ջΪ��ջӴ��\n");
	else{
	*e=s->top->data;}
	if(a!=*e) return SUCCESS;
	else return ERROR;
}}

//���ջ
Statuss clearLStack(LinkStack *s){
	ElemType a;
	LinkStackPtr p;
	p=s->top;
	if(s->count>1000||s->count<0){
	printf("��ջû����ʼ��Ӵ��\n");
	return ERROR;
}
	else{
		if(s->count==0) {
		printf("��ջ��Ϊ��ջӴ��\n");
	 	return ERROR; 
	}
	while(p->next!=NULL){
		s->top=s->top->next;
		free(p);
		p=s->top;
		s->count=0;
	}
	free(p);
	if(s->count==1) s->count=0;
	if(s->count==0) return SUCCESS;
	else return ERROR;
	}
}

//����ջ
Statuss destroyLStack(LinkStack *s){
	if(s->count>1000||s->count<0){
	
	printf("���ȳ�ʼ����ջӴ��\n");
	return ERROR;
	}
	else{
	
	if(s->count==0){
	s->top->next=NULL;
	s->top->data=0;	
	s->count=10000;
	}
	else printf("�������ջ��\n");
	if(s->top->data==0&&s->top->next==NULL) return SUCCESS;
	else return ERROR; }
}

//���ջ����
Statuss LStackLength(LinkStack *s,int *length){
	if(s->count>1000||s->count<0)
	printf("���ȳ�ʼ����ջӴ��\n");
	else{
		*length=s->count;
	}
	if(*length==s->count) return SUCCESS;
	else return ERROR;
}

//��ջ
Statuss pushLStack(LinkStack *s,ElemType data){
	LinkStackPtr p;
	if(s->count>1000||s->count<0)
	printf("���ȳ�ʼ����ջӴ��\n");
	else {
	p=(LinkStackPtr)malloc(sizeof(StackNode));
	p->data=data;
	p->next=s->top;
	s->top=p;
	s->count++;	
	}
	if(s->top->data==data) return SUCCESS;
	else return ERROR;
}

//��ջ
Statuss popLStack(LinkStack *s,ElemType *data){
	LinkStackPtr p;
	ElemType a=s->count;
	if(s->count>1000||s->count<0)
	printf("���ȳ�ʼ����ջӴ��\n");
	else{
		if(s->count==1) {
			*data=s->top->data;
			s->count--;
			free(s->top); 
			s->top->data=0; 
		}
		else if(s->top->next!=NULL){
			p=s->top;
			s->top=s->top->next;
			*data=p->data;
			s->count--;
			free(p);
		}
	}
	if(a==s->count+1) return SUCCESS;
	else return ERROR;
}
