#include <stdio.h>
#include <stdlib.h>
#include "./LinkStack.h"




//初始化栈
Status initLStack(LinkStack *s){
	if(s->count>1000||s->count<0) {
		s->top=(LinkStackPtr)malloc(sizeof(StackNode));
	s->count=0;
	s->top->data=0;
	s->top->next=NULL;	
	}
	else printf("请先清空掉原有的栈再初始化哟！\n");
	if(s->count==0) return SUCCESS;
	else return ERROR;
}

//判断栈是否为空
Status isEmptyLStack(LinkStack *s){
	if(s->count!=0) return ERROR;
	else return SUCCESS;
}

//得到栈顶元素
Status getTopLStack(LinkStack *s,ElemType *e){
	ElemType a=*e;
	if(s->count>1000||s->count<0)
	printf("请先初始化链栈哟！\n");
	else {
		if(s->count==0) printf("该栈为空栈哟！\n");
	else{
	*e=s->top->data;}
	if(a!=*e) return SUCCESS;
	else return ERROR;
}}

//清空栈
Status clearLStack(LinkStack *s){
	ElemType a;
	LinkStackPtr p;
	p=s->top;
	if(s->count>1000||s->count<0){
	printf("该栈没被初始化哟！\n");
	return ERROR;
}
	else{
		if(s->count==0) {
		printf("该栈已为空栈哟！\n");
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

//销毁栈
Status destroyLStack(LinkStack *s){
	if(s->count>1000||s->count<0){
	
	printf("请先初始化链栈哟！\n");
	return ERROR;
	}
	else{
	
	if(s->count==0){
	s->top->next=NULL;
	s->top->data=0;	
	s->count=10000;
	}
	else printf("请先清空栈！\n");
	if(s->top->data==0&&s->top->next==NULL) return SUCCESS;
	else return ERROR; }
}

//检测栈长度
Status LStackLength(LinkStack *s,int *length){
	if(s->count>1000||s->count<0)
	printf("请先初始化链栈哟！\n");
	else{
		*length=s->count;
	}
	if(*length==s->count) return SUCCESS;
	else return ERROR;
}

//入栈
Status pushLStack(LinkStack *s,ElemType data){
	LinkStackPtr p;
	if(s->count>1000||s->count<0)
	printf("请先初始化链栈哟！\n");
	else {
	p=(LinkStackPtr)malloc(sizeof(StackNode));
	p->data=data;
	p->next=s->top;
	s->top=p;
	s->count++;	
	}
	printf("%d\n",s->top->data);
	if(s->top->data==data) return SUCCESS;
	else return ERROR;
}

//出栈
Status popLStack(LinkStack *s,ElemType *data){
	LinkStackPtr p;
	ElemType a=s->count;
	if(s->count>1000||s->count<0)
	printf("请先初始化链栈哟！\n");
	else{
		if(s->count==1) {
			*data=s->top->data;
			s->count--;
			free(s->top); 
			s->top->data=0;
			s->top->next=NULL; 
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
