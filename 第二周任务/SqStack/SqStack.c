#include "./SqStack.h"
#include <stdio.h>
#include<stdlib.h>

#define OVERFLOW -1


//��ʼ��ջ
Status initStack(SqStack *s,int sizes){
	if(s->size<=0||s->size>1500){
	s->size=sizes;
	s->top=OVERFLOW;
	
	if(s->size==sizes&&s->top==OVERFLOW) return SUCCESS;
	else return ERROR;
}
     else printf("��������ԭ�е�ջ�ٽ��г�ʼ����\n"); 
    
}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyStack(SqStack *s){
	if(s->top==OVERFLOW)
	return SUCCESS;
	else return ERROR;
} 

//�õ�ջ��Ԫ��
Status getTopStack(SqStack *s,ElemType *e){
	if(s->size<0||s->size>1500)
	printf("���ȳ�ʼ��ջ��\n");
	else{
	if(s->top==OVERFLOW) {
		printf("��ջΪ��ջ��\n");
		return ERROR; 
	}
	else	
	*e=*s->elem;
	if(*e==*(s->elem) )return SUCCESS;
	else return ERROR;
} }

//���ջ
Status clearStack(SqStack *s){
	if(s->size<0||s->size>1500)
	printf("���ȳ�ʼ��ջ��\n");
	else{
	ElemType i,n;
	if(s->top!=OVERFLOW){
	n=s->top;
	for(i=0;i<=n;i++)
	{
		free(s->elem+s->top);
		s->top--;
		
	}}
	else {
	printf("��ջ���ǿ�ջ����������գ�\n");
	return ERROR;}
	}
	if(s->top==OVERFLOW) return SUCCESS;
	else return ERROR;
	}
	
 
//����ջ
Status destroyStack(SqStack *s){
	if(s->size<0||s->size>1500)
	printf("���ȳ�ʼ��ջ��\n");
	else{
	if(s->top==OVERFLOW) {
		s->elem=NULL;
		s->size=0;
	}
	else printf("�������ջӴ��\n");	
	}
	if(s->elem==NULL&&s->size==0) return SUCCESS;
	else return ERROR; 
} 

//���ջ�Ĵ�С
Status stacklength(SqStack *s,int* length){
	if(s->size<=0||s->size>1500)
	printf("���ȳ�ʼ��ջ��\n");
	else 
	*length=s->top+1;
	if(*length==(s->top+1)&&*length<1000&&*length>=0) 
	return 	SUCCESS;
	else return ERROR;
} 

//��ջ
Status pushStack(SqStack *s,ElemType data){
	ElemType a=s->top;
	if(s->size<0||s->size>1500)
	printf("���ȳ�ʼ��ջ��\n");
	else{
		
				
		if(s->top<s->size-1) {
			s->elem=(int*)malloc(sizeof(int));
		*s->elem=data;
		s->top++;
		}
		else {
			s->elem--;
		printf("ջ�Ѵ���\n"); }
	}
	if(a==(s->top)-1) return SUCCESS;
	else return ERROR;
} 

//��ջ
Status popStack(SqStack *s,ElemType *data){
	ElemType a=s->top;
	if(s->size<=0||s->size>1500)
	printf("���ȳ�ʼ��ջ��\n");
	else{
		if(s->top!=OVERFLOW){
		if(s->size!=0){
			*data=*s->elem;			
		s->top--;
		s->elem--;
		}
		else printf("��ջΪ��ջ��\n");
}
else printf("��ջΪ��ջ��\n");
	}
	if(a==(s->top)+1) return SUCCESS;
	else return ERROR;
	}
 


