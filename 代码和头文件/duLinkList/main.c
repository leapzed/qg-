#include<stdio.h>
#include<stdlib.h>
#include "./duLinkedList.h"
#include "./duLinkedList.c"

void menu(){
	printf("******************************\n");
	printf("1.创建双向链表\n2.销毁链表\n3.在某结点前插入结点\n4.在某结点后插入结点\n5.删除结点\n6.遍历链表\n7.退出\n"); 
	printf("******************************\n");
	printf("输入你想实现的功能的序号:");
}

void main(){
	ElemType number,flag;
	 DuLinkedList head;
	 head=(DuLinkedList)malloc(sizeof(DuLNode));
	menu();
	while(1){
	scanf("%d",&number);                //输入所选功能序号 
    while(number<1||number>11){          //进行用户检测 
    printf("输入有误，请输入所需功能对应的序号："); 
    fflush(stdin);
    scanf("%d",&number);
    }
    
    if(number==1){
    	int a;
		if(head->data>0&&head->data<1000) printf("再创建指针前先销毁链表哟！\n");
		else{
    	a=InitList_DuL(&head);
    	if(a==1) {flag=1;
		printf("创建成功！\n");}
		else printf("创建失败！\n");
	}
	}
	
	if(number==2){
	if(head->data>1000||head->data<1) printf("该指针并没有指向链表！\n");
	else{
	DestroyList_DuL(&head);
	if(head->data>1000||head->data<1)
	{
	printf("销毁成功！\n");
	flag=0;}
	else printf("销毁失败！\n");
	}
	}
	
	if(number==3){
	DuLNode *i,*storage;
	ElemType a,c,d;
	i=storage=(DuLinkedList)malloc(sizeof(DuLNode));
	printf("请输入数据：");	
	scanf("%d",&(i->data));
	while(i->data<1||i->data>1000){                                      //进行用户检测 
	printf("输入数据应为不大于1000的正数，请重新输入数据："); 
	fflush(stdin);
	scanf("%d",&(i->data)) ;
	} 
	printf("请输入插入在第几个结点前：");
	scanf("%d",&c);
	while(c<1||c>1000){                                      //进行用户检测 
	printf("输入数据应为不大于1000的正数，请重新输入数据："); 
	fflush(stdin);
	scanf("%d",&c) ;
	} 
	if(c>flag) printf("插入失败！没有这么多的结点！\n");
	else{
	storage=head;
	for(d=1;d<c;d++) storage=storage->next;	
	a=InsertBeforeList_DuL(storage,i); 
	if(a==1) {if(flag++==1) head=i; 
	printf("插入成功！\n");}
	else printf("插入失败！\n"); 
	} 
	}
	
	if(number==4){
	DuLNode *i,*storage;
	ElemType a,c,d;
	i=storage=(DuLinkedList)malloc(sizeof(DuLNode));
	printf("请输入数据：");	
	scanf("%d",&(i->data));
	while(i->data<1||i->data>1000){                                      //进行用户检测 
	printf("输入数据应为不大于1000的正数，请重新输入数据："); 
	fflush(stdin);
	scanf("%d",&(i->data)) ;
	} 
	printf("请输入插入第几个结点后：");
	scanf("%d",&c);
	while(c<1||c>1000){                                      //进行用户检测 
	printf("输入数据应为不大于1000的正数，请重新输入数据："); 
	fflush(stdin);
	scanf("%d",&c) ;
	} 
	if(c>flag) printf("插入失败！没有这么多的结点！\n");
	else{
	storage=head;
	for(d=1;d<c;d++) storage=storage->next;	
	a=InsertAfterList_DuL(storage,i); 
	if(a==1) {flag++;
	printf("插入成功！\n");}
	else printf("插入失败！\n"); 
	} 	
	}
	
	if(number==5){
	ElemType a,b,c,e;
    DuLNode *d;
    d=(DuLinkedList)malloc(sizeof(DuLNode));
    d=head;
    printf("请输入要删除结点的位置：");
	scanf("%d",&b);
	while(b<1||b>1000){                                      //进行用户检测 
	printf("输入数据应为不大于1000的正数，请重新输入数据："); 
	fflush(stdin);
	scanf("%d",&b) ;
	}
	if(b>flag) printf("删除失败！没有那么多的结点！\n");
	else {
		if(b==1) head=head->next;
	for(c=1;c<b;c++) d=d->next;
	a=DeleteList_DuL(d,&e);
	if(a==1) printf("删除成功！\n");
	else printf("删除失败！\n"); 
	}
	}
	
	if(number==6){
		if(head->data>0&&head->data<1000){
		TraverseList_DuL(head,&print);
	}
	else printf("该指针并没有指向链表！\n");
	}
	
	if(number==7) break;
	
	printf("\n");
	printf("\n");
	printf("\n");
	menu();
}
}

