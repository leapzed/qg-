#include <stdio.h>
#include <stdlib.h>
#include ".\SqStack.h"
#include ".\SqStack.c"

#define OVERFLOW -1

void menu(){
	printf("*********************************\n");
	printf("1.��ʼ��ջ\n2.�ж�ջ�Ƿ�Ϊ��\n3.�õ�ջ��Ԫ��\n4.���ջ\n5.����ջ\n6.���ջ�Ĵ�С\n7.��ջ\n8.��ջ\n9.�˳�\n");
	printf("*********************************\n");
	printf("��������ʵ�ֵĹ��ܵ����:");
}

void main(){
	SqStack p;
	ElemType number;
	menu();
	while(1){
	scanf("%d",&number);                //������ѡ������� 
    while(number<1||number>10){          //�����û���� 
    printf("�����������������蹦�ܶ�Ӧ����ţ�"); 
    fflush(stdin);
    scanf("%d",&number);
    }
    
    if(number==1){
    ElemType a,b;
    printf("�����������ʼ��ջ�Ĵ�С��");
	scanf("%d",&b);
	while(b<1||b>1500){                                      //�����û���� 
	printf("��������ӦΪ������1500���������������������ݣ�"); 
	fflush(stdin);
	scanf("%d",&b) ;
	}  
	
    a=initStack(&p,b);
    if(a==1) printf("��ʼ���ɹ���\n");
    else printf("��ʼ��ʧ�ܣ�\n"); 
	}
	
	if(number==2){
	ElemType a;
	
	if(p.size<=0||p.size>1500)
	printf("ջ��û�б���ʼ����\n");
	else{
		a=isEmptyStack(&p);
	if(a==1) printf("��ջΪ��ջ��\n");
    else printf("��ջ��Ϊ��ջ��\n"); 
	}
	
	
	
	} 
	
	if(number==3){
	ElemType a,b;
	a=getTopStack(&p,&b);
	if(a==1) printf("ջ��Ԫ�����ݴ�СΪ��%d\n");
	else printf("��ȡʧ�ܣ�\n");	
	}
	
	if(number==4){
		ElemType a;
		a=clearStack(&p);
		if(a==1) printf("��ճɹ���\n");
		else printf("���ʧ�ܣ�\n");
	}
	
	if(number==5){
	ElemType a;
	a=destroyStack(&p);
	if(a==1) printf("���ٳɹ���\n");
	else printf("����ʧ�ܣ�\n");	
	}
	
	if(number==6){
		ElemType a,b;
		a=stacklength(&p,&b);
		if(a==1) printf("ջ�Ĵ�СΪ��%d\n",b);
		else printf("��ȡջ�Ĵ�Сʧ�ܣ�\n"); 
	}
	
	if(number==7){
	ElemType a,b,i;
	printf("��������Ҫ��ջ�����ݣ�");
	scanf("%d",&b);
	while(b<1||b>1000){                                      //�����û���� 
	printf("��������ӦΪ������1000���������������������ݣ�"); 
	fflush(stdin);
	scanf("%d",&b);
	}  
	if(p.size<0||p.size>1500)
	printf("���ȳ�ʼ��ջ��\n");
	else{
	for(i=0;i<=p.top;i++)
	p.elem++;
	a=pushStack(&p,b);
	if(a==1) printf("��ջ�ɹ���\n");
	else printf("��ջʧ�ܣ�\n");
	}}
	
	if(number==8){
	ElemType a,b;
	a=popStack(&p,&b);
	if(a==1) printf("��ջ�ɹ�����ջ����Ϊ��%d\n",b);
	else printf("��ջʧ�ܣ�\n"); 
	}
	
	if(number==9){
	break; 
	}

	printf("\n");
	printf("\n");
	printf("\n");
	menu();
} 
}
