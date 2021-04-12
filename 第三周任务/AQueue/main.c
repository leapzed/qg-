#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"./AQueue.h"
#include"./AQueue.c"


void menu(){
	printf("*********************************\n");
	printf("1.��ʼ������\n2.���ٶ���\n3.�������Ƿ�����\n4.�������Ƿ�Ϊ��\n5.�鿴��ͷԪ��\n6.ȷ�����г���\n7.���\n8.����\n9.��ն���\n10.��������\n11.�˳�\n");
	printf("*********************************\n");
	printf("��������ʵ�ֵĹ��ܵ����:"); 
}

void main(){
	AQueue p;
	int number;
	menu();
	
	while(1){                              
    scanf("%d",&number);                //������ѡ������� 
    while(number<1||number>11){          //�����û���� 
    printf("�����������������蹦�ܶ�Ӧ����ţ�"); 
    fflush(stdin);
    scanf("%d",&number);
    }
    
    if(number==1){
    	InitAQueue(&p);
    	if(p.length==0) printf("��ʼ���ɹ���\n");
    	else printf("��ʼ��ʧ�ܣ�\n");
    	
	}
	
	if(number==2){
		DestoryAQueue(&p);
		if(p.data[0]==NULL&&p.data[1]==NULL) printf("���ٳɹ���\n");
		else printf("����ʧ�ܣ�\n");
	}
	
	if(number==3){
		int a;
		a=IsFullAQueue(&p);
		if(a==1) printf("�����Ѿ�����~\n");
		else printf("����δ����\n"); 
	}
	
	if(number==4){
		int a;
		a=IsEmptyAQueue(&p);
		if(a==1) printf("�ö���Ϊ�ն��У�\n");
		if(a==0) printf("�ö��в�Ϊ�ն��У�\n");
	}
	
	
	if(number==5){
		int a;
		void *b;
		a=GetHeadAQueue(&p,b);
		if(a==1) {
		printf("��ȡ�ɹ�����ͷԪ��Ϊ��%s\n",p.data[p.front]);
		}	
		else printf("��ȡʧ�ܣ�\n");
	}
	
	
	if(number==6){
		int a;
		a=LengthAQueue(&p);
		if(a==10000) printf("��ȡ���г���ʧ�ܣ�\n");
		else printf("��ȡ�ɹ������г���Ϊ��%d\n",a); 
	}
	
	if(number==7){
		int a;
		char *b;
		b=(char*)malloc(sizeof(char));
		printf("��������Ҫ��ӵ����ݣ�");
		scanf("%s",b);
		a=EnAQueue(&p,b);
		if(a==1) printf("��ӳɹ���\n");
		else printf("���ʧ�ܣ�\n");
	}
	
	if(number==8){
		int a;
		a=DeAQueue(&p);
		if(a==1) printf("���ӳɹ���\n");
		else printf("����ʧ�ܣ�\n");
	}
	
	if(number==9){
		ClearAQueue(&p);
		if(p.front==0&&p.rear==0&&p.length==0) printf("��ճɹ���\n");
		else printf("���ʧ�ܣ�\n");
	}
	
	
	if(number==10){
		int a;
		a=TraverseAQueue(&p,&APrint);
		if(a==1) printf("������ɣ�\n");
		else printf("����ʧ�ܣ�\n");
	}
	
	if(number==11) break;
	
	printf("����س�����ִ�й��ܡ�"); 
	getchar();
	getchar();
	system("CLS");

	menu();
	
	
	
}
}
