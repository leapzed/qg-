#include<stdio.h>
#include<stdlib.h>
#include "./linkedList.c"
#include "./linkedList.h"

void menu(){
	printf("******************************\n") ;
	printf("1.����������\n2.��������\n3.����һ�����\n4.ɾ��ĳ���\n5.��������\n6.�жϽ���Ƿ����\n7.��ת����\n8.�ж������Ƿ�ɻ�\n9.������ż˳��\n10.���м���\n11.�˳�\n");
	printf("******************************\n");
	printf("��������ʵ�ֵĹ��ܵ����:"); 
}

 
void main(){                        
	LinkedList* head;                          //����ṹ��ָ�� 
	int number;                                //number�����洢�û����蹦�ܵ����    
	head=(LinkedList*)malloc(sizeof(LinkedList));  //�����ڴ� 
    menu();
    /*������������ʵ����Ӧ����*/ 
    while(1){                              
    scanf("%d",&number);                //������ѡ������� 
    while(number<1||number>11){          //�����û���� 
    printf("�����������������蹦�ܶ�Ӧ����ţ�"); 
    fflush(stdin);
    scanf("%d",&number);
    }
    if(number==1){
    	int a;
    	a=InitList(head);
    	printf("%d\n",(*head)->data);
    	if(a==1) printf("�����ɹ���\n");
		else printf("����ʧ�ܣ�\n"); 
	} 
	if(number==2){
	DestroyList(head);
	printf("���ٳɹ���\n");
	}
	if(number==3){
	LNode *i,*storage;
	ElemType a,c,d;
	i=storage=(LinkedList)malloc(sizeof(LNode));
	printf("���������ݣ�");	
	scanf("%d",&(i->data));
	while(i->data<1||i->data>1000){                                      //�����û���� 
	printf("��������ӦΪ������1000���������������������ݣ�"); 
	fflush(stdin);
	scanf("%d",&(i->data)) ;
	} 
	printf("������������λ�ã�");
	scanf("%d",&c);
	while(c<1||c>1000){                                      //�����û���� 
	printf("��������ӦΪ������1000���������������������ݣ�"); 
	fflush(stdin);
	scanf("%d",&c) ;
	} 
	if(SearchList(*head,c)){
	storage=*head;
	for(d=1;d<c;d++) storage=storage->next;	
	a=InsertList(storage,i);
	}
	else printf("����ʧ�ܣ�\n"); 
    }
    if(number==4){
    ElemType a,b,c,*e;
    LNode *d;
    d=(LinkedList)malloc(sizeof(LNode));
    d=*head;
    printf("������Ҫɾ������λ�ã�");
	scanf("%d",&b);
	while(b<1||b>1000){                                      //�����û���� 
	printf("��������ӦΪ������1000���������������������ݣ�"); 
	fflush(stdin);
	scanf("%d",&b) ;
	} 
	for(c=1;c<b;c++) d=d->next;
	a=DeleteList(d,e);
	}
	menu();
}
}



