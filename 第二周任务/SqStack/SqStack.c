#include "./SqStack.h"
#include <stdio.h>
#include<stdlib.h>

#define OVERFLOW -1


//初始化栈
Status initStack(SqStack *s,int sizes){
	if(s->size<=0||s->size>1500){
	s->size=sizes;
	s->top=OVERFLOW;
	
	if(s->size==sizes&&s->top==OVERFLOW) return SUCCESS;
	else return ERROR;
}
     else printf("请先销毁原有的栈再进行初始化！\n"); 
    
}

//判断栈是否为空
Status isEmptyStack(SqStack *s){
	if(s->top==OVERFLOW)
	return SUCCESS;
	else return ERROR;
} 

//得到栈顶元素
Status getTopStack(SqStack *s,ElemType *e){
	if(s->size<0||s->size>1500)
	printf("请先初始化栈！\n");
	else{
	if(s->top==OVERFLOW) {
		printf("该栈为空栈！\n");
		return ERROR; 
	}
	else	
	*e=*s->elem;
	if(*e==*(s->elem) )return SUCCESS;
	else return ERROR;
} }

//清空栈
Status clearStack(SqStack *s){
	if(s->size<0||s->size>1500)
	printf("请先初始化栈！\n");
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
	printf("该栈已是空栈，无需再清空！\n");
	return ERROR;}
	}
	if(s->top==OVERFLOW) return SUCCESS;
	else return ERROR;
	}
	
 
//销毁栈
Status destroyStack(SqStack *s){
	if(s->size<0||s->size>1500)
	printf("请先初始化栈！\n");
	else{
	if(s->top==OVERFLOW) {
		s->elem=NULL;
		s->size=0;
	}
	else printf("请先清空栈哟！\n");	
	}
	if(s->elem==NULL&&s->size==0) return SUCCESS;
	else return ERROR; 
} 

//检测栈的大小
Status stacklength(SqStack *s,int* length){
	if(s->size<=0||s->size>1500)
	printf("请先初始化栈！\n");
	else 
	*length=s->top+1;
	if(*length==(s->top+1)&&*length<1000&&*length>=0) 
	return 	SUCCESS;
	else return ERROR;
} 

//入栈
Status pushStack(SqStack *s,ElemType data){
	ElemType a=s->top;
	if(s->size<0||s->size>1500)
	printf("请先初始化栈！\n");
	else{
		
				
		if(s->top<s->size-1) {
			s->elem=(int*)malloc(sizeof(int));
		*s->elem=data;
		s->top++;
		}
		else {
			s->elem--;
		printf("栈已存满\n"); }
	}
	if(a==(s->top)-1) return SUCCESS;
	else return ERROR;
} 

//出栈
Status popStack(SqStack *s,ElemType *data){
	ElemType a=s->top;
	if(s->size<=0||s->size>1500)
	printf("请先初始化栈！\n");
	else{
		if(s->top!=OVERFLOW){
		if(s->size!=0){
			*data=*s->elem;			
		s->top--;
		s->elem--;
		}
		else printf("该栈为空栈！\n");
}
else printf("该栈为空栈！\n");
	}
	if(a==(s->top)+1) return SUCCESS;
	else return ERROR;
	}
 


