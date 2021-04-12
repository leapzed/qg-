#include<stdio.h>
#include<stdlib.h>
#include"./LQueue.h"
#include"./LQueue.c"


void menu(){
	printf("*********************************\n");
	printf("1.��ʼ������\n2.���ٶ���\n3.�������Ƿ�Ϊ��\n4.�鿴��ͷԪ��\n5.ȷ�����г���\n6.���\n7.����\n8.��ն���\n9.��������\n10.�˳�\n");
	printf("*********************************\n");
	printf("��������ʵ�ֵĹ��ܵ����:"); 
}

void main(){
	LQueue p;
	int number;
	int flag=0;
	menu();
	
	while(1){                              
    scanf("%d",&number);                //������ѡ������� 
    while(number<1||number>11){          //�����û���� 
    printf("�����������������蹦�ܶ�Ӧ����ţ�"); 
    fflush(stdin);
    scanf("%d",&number);
    }
    
    if(number==1){
    	if(flag==0){
		p.front=p.rear=(Node*)malloc(sizeof(Node));
		InitLQueue(&p);
    	if(p.length==0) {
    	printf("��ʼ���ɹ���\n");	
    	flag=1;
		}
    	else printf("��ʼ��ʧ�ܣ�\n");
		}
		else	printf("�ٴγ�ʼ��ǰ��������ԭ����Ӵ��\n");
    
	}
	
	if(number==2){
		if(flag==1){
		DestoryLQueue(&p);
		if(p.length==10000) {
		printf("���ٳɹ���\n");	
		flag=0;
		}
		
		else printf("����ʧ�ܣ�\n");	
		}
		else printf("���л�û�б���ʼ��Ӵ~\n");
		
	}
	
	if(number==3){
		int a;
		if(flag==1){
			a=IsEmptyLQueue(&p);
		if(a==1) printf("�ö���Ϊ�ն���~\n");
		else printf("�ö��в�Ϊ�ն���~\n");
		}
		else printf("���л�û�б���ʼ��Ӵ~\n");
		
	}
	
	if(number==4){
		int a;
		void *b;
		if(flag==1){
			a=GetHeadLQueue(&p,b);
		if(a==1) {
		printf("��ȡ�ɹ�����ͷԪ��Ϊ��%s\n",(char*)p.front->next->data);
		}	
		else printf("��ȡʧ�ܣ�\n");	
		}
		else printf("���л�û�б���ʼ��Ӵ~\n");
	
	}
    
    if(number==5){
    	int a;
    	if(flag==1){
    	a=LengthLQueue(&p);
    	if(a==0) printf("��ȡ���г���ʧ�ܣ�\n");
		else printf("���г���Ϊ��%d\n",a); 	
		}
		else printf("���л�û�б���ʼ��Ӵ~\n");
    	
	}
	
	if(number==6){
		int a;
		char* b;
		b=(char*)malloc(sizeof(char));
		if(flag==1){
		printf("��������Ҫ��ӵ����ݣ�");
		scanf("%s",b);
		a=EnLQueue(&p,b);
		if(a==1) printf("��ӳɹ���\n");
		else printf("���ʧ�ܣ�\n");	
		}
		else printf("���л�û�б���ʼ��Ӵ~\n");
		
	}
	
	if(number==7){
		int a;
		if(flag==1){
		a=DeLQueue(&p);
		if(a==1) printf("���ӳɹ���\n");
		else printf("����ʧ�ܣ�\n"); 
		}
		else  printf("���л�û�б���ʼ��Ӵ~\n");
		
	}
	
	if(number==8){
		if(flag==1){
		ClearLQueue(&p);
		if(p.length==0) printf("��ճɹ���\n");
		else printf("���ʧ�ܣ�\n");	
		}
		else  printf("���л�û�б���ʼ��Ӵ~\n");
	}
	
	if(number==9){
		int a;
		if(flag==1){
			a=TraverseLQueue(&p,&LPrint);
			if(a==1) printf("������ɣ�\n");
			else printf("����ʧ�ܣ�\n");
		}
		else  printf("���л�û�б���ʼ��Ӵ~\n");
	}
    
    
    if(number==10) break;
	
	printf("����س�����ִ�й��ܡ�"); 
	getchar();
	getchar();
	system("CLS");

	menu();
    
	}
}
