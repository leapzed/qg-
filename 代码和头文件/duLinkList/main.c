#include<stdio.h>
#include<stdlib.h>
#include "./duLinkedList.h"
#include "./duLinkedList.c"

void menu(){
	printf("******************************\n");
	printf("1.����˫������\n2.��������\n3.��ĳ���ǰ������\n4.��ĳ���������\n5.ɾ�����\n6.��������\n7.�˳�\n"); 
	printf("******************************\n");
	printf("��������ʵ�ֵĹ��ܵ����:");
}

void main(){
	ElemType number,flag;
	 DuLinkedList head;
	 head=(DuLinkedList)malloc(sizeof(DuLNode));
	menu();
	while(1){
	scanf("%d",&number);                //������ѡ������� 
    while(number<1||number>11){          //�����û���� 
    printf("�����������������蹦�ܶ�Ӧ����ţ�"); 
    fflush(stdin);
    scanf("%d",&number);
    }
    
    if(number==1){
    	int a;
		if(head->data>0&&head->data<1000) printf("�ٴ���ָ��ǰ����������Ӵ��\n");
		else{
    	a=InitList_DuL(&head);
    	if(a==1) {flag=1;
		printf("�����ɹ���\n");}
		else printf("����ʧ�ܣ�\n");
	}
	}
	
	if(number==2){
	if(head->data>1000||head->data<1) printf("��ָ�벢û��ָ������\n");
	else{
	DestroyList_DuL(&head);
	if(head->data>1000||head->data<1)
	{
	printf("���ٳɹ���\n");
	flag=0;}
	else printf("����ʧ�ܣ�\n");
	}
	}
	
	if(number==3){
	DuLNode *i,*storage;
	ElemType a,c,d;
	i=storage=(DuLinkedList)malloc(sizeof(DuLNode));
	printf("���������ݣ�");	
	scanf("%d",&(i->data));
	while(i->data<1||i->data>1000){                                      //�����û���� 
	printf("��������ӦΪ������1000���������������������ݣ�"); 
	fflush(stdin);
	scanf("%d",&(i->data)) ;
	} 
	printf("����������ڵڼ������ǰ��");
	scanf("%d",&c);
	while(c<1||c>1000){                                      //�����û���� 
	printf("��������ӦΪ������1000���������������������ݣ�"); 
	fflush(stdin);
	scanf("%d",&c) ;
	} 
	if(c>flag) printf("����ʧ�ܣ�û����ô��Ľ�㣡\n");
	else{
	storage=head;
	for(d=1;d<c;d++) storage=storage->next;	
	a=InsertBeforeList_DuL(storage,i); 
	if(a==1) {if(flag++==1) head=i; 
	printf("����ɹ���\n");}
	else printf("����ʧ�ܣ�\n"); 
	} 
	}
	
	if(number==4){
	DuLNode *i,*storage;
	ElemType a,c,d;
	i=storage=(DuLinkedList)malloc(sizeof(DuLNode));
	printf("���������ݣ�");	
	scanf("%d",&(i->data));
	while(i->data<1||i->data>1000){                                      //�����û���� 
	printf("��������ӦΪ������1000���������������������ݣ�"); 
	fflush(stdin);
	scanf("%d",&(i->data)) ;
	} 
	printf("���������ڼ�������");
	scanf("%d",&c);
	while(c<1||c>1000){                                      //�����û���� 
	printf("��������ӦΪ������1000���������������������ݣ�"); 
	fflush(stdin);
	scanf("%d",&c) ;
	} 
	if(c>flag) printf("����ʧ�ܣ�û����ô��Ľ�㣡\n");
	else{
	storage=head;
	for(d=1;d<c;d++) storage=storage->next;	
	a=InsertAfterList_DuL(storage,i); 
	if(a==1) {flag++;
	printf("����ɹ���\n");}
	else printf("����ʧ�ܣ�\n"); 
	} 	
	}
	
	if(number==5){
	ElemType a,b,c,e;
    DuLNode *d;
    d=(DuLinkedList)malloc(sizeof(DuLNode));
    d=head;
    printf("������Ҫɾ������λ�ã�");
	scanf("%d",&b);
	while(b<1||b>1000){                                      //�����û���� 
	printf("��������ӦΪ������1000���������������������ݣ�"); 
	fflush(stdin);
	scanf("%d",&b) ;
	}
	if(b>flag) printf("ɾ��ʧ�ܣ�û����ô��Ľ�㣡\n");
	else {
		if(b==1) head=head->next;
	for(c=1;c<b;c++) d=d->next;
	a=DeleteList_DuL(d,&e);
	if(a==1) printf("ɾ���ɹ���\n");
	else printf("ɾ��ʧ�ܣ�\n"); 
	}
	}
	
	if(number==6){
		if(head->data>0&&head->data<1000){
		TraverseList_DuL(head,&print);
	}
	else printf("��ָ�벢û��ָ������\n");
	}
	
	if(number==7) break;
	
	printf("\n");
	printf("\n");
	printf("\n");
	menu();
}
}

