#include<stdio.h>
#include<stdlib.h>
#include "./linkedList.c"
#include "./linkedList.h"

void menu(){
	printf("******************************\n");
	printf("1.����������\n2.��������\n3.����һ�����\n4.ɾ��ĳ���\n5.�������������\n6.��ת����\n7.�ж������Ƿ�ɻ�\n8.������ż˳��\n9.���м���\n10.�˳�\n");
	printf("******************************\n");
	printf("��������ʵ�ֵĹ��ܵ����:"); 
}

 
void main(){                        
	LinkedList head;                          //����ṹ��ָ�� 
	int number;                                //number�����洢�û����蹦�ܵ����    
	head=(LinkedList)malloc(sizeof(LNode));  //�����ڴ� 
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
		if(head->data>0&&head->data<1000) printf("�ٴ���ָ��ǰ����������Ӵ��\n");
		else{
    	a=InitList(&head);
    	if(a==1) printf("�����ɹ���\n");
		else printf("����ʧ�ܣ�\n"); 
	} }
	
	if(number==2){
		if(head->data>1000||head->data<1) printf("��ָ�벢û��ָ������\n");
		else{
	DestroyList(&head);
	if(head->data>1000||head->data<1)
	printf("���ٳɹ���\n");
	else printf("����ʧ�ܣ�\n");
	}}
	
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
	if(c==1) printf("ֻ֧�ֲ��뵽ͷ���֮��Ӵ��\n");
	else{
	if(SearchList(head,c-1)){
	storage=head;
	for(d=1;d<c-1;d++) storage=storage->next;	
	a=InsertList(storage,i); 
	if(a==1) printf("����ɹ���\n");
	else printf("����ʧ�ܣ�\n"); 
	}
	else printf("����ʧ�ܣ�û����ô��Ľ�㣡\n"); 
    }}
    
    if(number==4){
    ElemType a,b,c,e;
    LNode *d;
    d=(LinkedList)malloc(sizeof(LNode));
    d=head;
    printf("������Ҫɾ������λ�ã�");
	scanf("%d",&b);
	while(b<1||b>1000){                                      //�����û���� 
	printf("��������ӦΪ������1000���������������������ݣ�"); 
	fflush(stdin);
	scanf("%d",&b) ;
	} 
	if(SearchList(head,b)){
	for(c=1;c<b-1;c++) d=d->next;
	a=DeleteList(d,&e);
	if(a==1) printf("ɾ���ɹ���\n");
	else printf("ɾ��ʧ�ܣ�\n"); 
	}
	else printf("ɾ��ʧ�ܣ�û����ô��Ľ�㣡\n");
	}
	
	if(number==5){
	if(head->data>0&&head->data<1000){
		TraverseList(head,&print);
	}
	else printf("��ָ�벢û��ָ������\n"); 
	}
	
	
	if(number==6){
		ElemType a;
		if(head->data>0&&head->data<1000){
	a=ReverseList(&head);
	if(a==1) {
	 printf("��ת�ɹ���\n");
	 TraverseList(head,&print);}
	else printf("��תʧ�ܣ�\n");
}
	else printf("��ָ��û��ָ������\n");
	} 
	
	if(number==7){
		ElemType a;
		if(head->data>0&&head->data<1000){
		a=IsLoopList(head);
		if(a==1) printf("����ѭ����\n");
		else printf("����ѭ����\n"); 
	}
	else printf("��ָ�벢û��ָ������\n");
	}
	
    if(number==8){
    	if(head->data>0&&head->data<1000){
    head=ReverseEvenList(&head);
    if(head->next!=NULL) TraverseList(head,&print);
}     
else printf("��ָ�벢û��ָ������\n");
	} 
	
	if(number==9){
		LNode* p;
		p=(LinkedList)malloc(sizeof(LNode));
		if(head->data>0&&head->data<1000){
			if(head->next==NULL) printf("������ֻ��һ����㣬��");
			p=head;
		p=FindMidNode(&p);	
		if(p->data!=head->data||head->next==NULL)	
		printf("�м��������Ϊ:%d\n",p->data);
		else printf("����ʧ�ܣ�\n"); 
	}
	else printf("��ָ�벢û��ָ������\n") ; 
	}
	
	if(number==10) break;
	printf("\n");
	printf("\n");
	printf("\n");
	menu();
}
}



