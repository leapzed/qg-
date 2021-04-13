#include <stdio.h>
#include <stdlib.h>
#include "./LinkStack.h"
#include "./LinkStack.c"

void menu(){
	printf("*********************************\n");
	printf("1.��ʼ��ջ\n2.�ж�ջ�Ƿ�Ϊ��\n3.�õ�ջ��Ԫ��\n4.���ջ\n5.����ջ\n6.���ջ�ĳ���\n7.��ջ\n8.��ջ\n9.�˳�\n");
	printf("*********************************\n");
	printf("��������ʵ�ֵĹ��ܵ����:");
}

void main(){
	LinkStack p;
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
    	ElemType a;
    	a=initLStack(&p);
    	if(a==1) printf("��ʼ���ɹ���\n");
    	else printf("��ʼ��ʧ�ܣ�\n"); 
	}
	
	if(number==2){
		ElemType a;
		if(p.count>1000||p.count<0)
		printf("��ջ��û�б���ʼ��Ӵ��\n");
		else{
		a=isEmptyLStack(&p);
		if(a==1) printf("��ջΪ��ջ��\n");
    	else printf("��ջ��Ϊ��ջ��\n");
    }
	}
	
	if(number==3){
		ElemType a,b;
		a=getTopLStack(&p,&b);
		if(a==1) {
			printf("ջ��Ԫ��Ϊ��%d\n",b);
		}
		else printf("��ȡʧ�ܣ�\n");
	}
	
	if(number==4){
		ElemType a;
		a=clearLStack(&p);
		if(a==1) printf("��ճɹ���\n");
		else printf("���ʧ�ܣ�\n");
	}
	
	if(number==5){
		ElemType a;
	
		a=destroyLStack(&p);
		if(a==1) printf("���ٳɹ���\n");
		else printf("����ʧ�ܣ�\n");
	}
	
	if(number==6){
		ElemType a,b;
		a=LStackLength(&p,&b);
		if(a==1) printf("ջ�ĳ���Ϊ��%d\n",b);
		else printf("��ȡջ�ĳ���ʧ�ܣ�\n"); 
	}
	
	if(number==7){
		ElemType a,b;
	printf("��������Ҫ��ջ�����ݣ�");
	scanf("%d",&b);
	while(b<1||b>1000){                                      //�����û���� 
	printf("��������ӦΪ������1000���������������������ݣ�"); 
	fflush(stdin);
	scanf("%d",&b) ;
	}  
	if(p.count>1000||p.count<0)
	printf("���ȳ�ʼ��ջӴ��\n");
	else{
	a=pushLStack(&p,b);
	if(a==1) printf("��ջ�ɹ���\n");
	else printf("��ջʧ�ܣ�\n");
	}
	}
	
	if(number==8){
		ElemType a,b;
		if(p.count>1000||p.count<0)
	printf("���ȳ�ʼ��ջӴ��\n");
	a=popLStack(&p,&b);
	if(a==1) printf("��ջ�ɹ�����ջ����Ϊ��%d\n",b);
	else printf("��ջʧ�ܣ�\n");
	} 
	
	if(number==9){
		break;
	}
	printf("����س�����ִ�й��ܡ�"); 
	getchar();
	getchar();
	system("CLS");
	menu(); 
	
	
}
}
