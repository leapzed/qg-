#include<stdio.h>
#include<stdlib.h>
#include "./linkedList.c"
#include "./linkedList.h"

void menu(){
	printf("******************************\n") ;
	printf("1.创建单链表\n2.销毁链表\n3.插入一个结点\n4.删除某结点\n5.遍历链表\n6.判断结点是否存在\n7.反转链表\n8.判断链表是否成环\n9.调换奇偶顺序\n10.找中间结点\n11.退出\n");
	printf("******************************\n");
	printf("输入你想实现的功能的序号:"); 
}

 
void main(){                        
	LinkedList* head;                          //定义结构体指针 
	int number;                                //number用来存储用户所需功能的序号    
	head=(LinkedList*)malloc(sizeof(LinkedList));  //开拓内存 
    menu();
    /*根据输入数据实现相应功能*/ 
    while(1){                              
    scanf("%d",&number);                //输入所选功能序号 
    while(number<1||number>11){          //进行用户检测 
    printf("输入有误，请输入所需功能对应的序号："); 
    fflush(stdin);
    scanf("%d",&number);
    }
    if(number==1){
    	int a;
    	a=InitList(head);
    	printf("%d\n",(*head)->data);
    	if(a==1) printf("创建成功！\n");
		else printf("创建失败！\n"); 
	} 
	if(number==2){
	DestroyList(head);
	printf("销毁成功！\n");
	}
	if(number==3){
	LNode *i,*storage;
	ElemType a,c,d;
	i=storage=(LinkedList)malloc(sizeof(LNode));
	printf("请输入数据：");	
	scanf("%d",&(i->data));
	while(i->data<1||i->data>1000){                                      //进行用户检测 
	printf("输入数据应为不大于1000的正数，请重新输入数据："); 
	fflush(stdin);
	scanf("%d",&(i->data)) ;
	} 
	printf("请输入插入结点的位置：");
	scanf("%d",&c);
	while(c<1||c>1000){                                      //进行用户检测 
	printf("输入数据应为不大于1000的正数，请重新输入数据："); 
	fflush(stdin);
	scanf("%d",&c) ;
	} 
	if(SearchList(*head,c)){
	storage=*head;
	for(d=1;d<c;d++) storage=storage->next;	
	a=InsertList(storage,i);
	}
	else printf("插入失败！\n"); 
    }
    if(number==4){
    ElemType a,b,c,*e;
    LNode *d;
    d=(LinkedList)malloc(sizeof(LNode));
    d=*head;
    printf("请输入要删除结点的位置：");
	scanf("%d",&b);
	while(b<1||b>1000){                                      //进行用户检测 
	printf("输入数据应为不大于1000的正数，请重新输入数据："); 
	fflush(stdin);
	scanf("%d",&b) ;
	} 
	for(c=1;c<b;c++) d=d->next;
	a=DeleteList(d,e);
	}
	menu();
}
}



