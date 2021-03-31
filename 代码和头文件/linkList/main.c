#include<stdio.h>
#include<stdlib.h>
#include "./linkedList.c"
#include "./linkedList.h"

void menu(){
	printf("******************************\n");
	printf("1.创建单链表\n2.销毁链表\n3.插入一个结点\n4.删除某结点\n5.遍历并输出链表\n6.反转链表\n7.判断链表是否成环\n8.调换奇偶顺序\n9.找中间结点\n10.退出\n");
	printf("******************************\n");
	printf("输入你想实现的功能的序号:"); 
}

 
void main(){                        
	LinkedList head;                          //定义结构体指针 
	int number;                                //number用来存储用户所需功能的序号    
	head=(LinkedList)malloc(sizeof(LNode));  //开拓内存 
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
		if(head->data>0&&head->data<1000) printf("再创建指针前先销毁链表哟！\n");
		else{
    	a=InitList(&head);
    	if(a==1) printf("创建成功！\n");
		else printf("创建失败！\n"); 
	} }
	
	if(number==2){
		if(head->data>1000||head->data<1) printf("该指针并没有指向链表！\n");
		else{
	DestroyList(&head);
	if(head->data>1000||head->data<1)
	printf("销毁成功！\n");
	else printf("销毁失败！\n");
	}}
	
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
	if(c==1) printf("只支持插入到头结点之后哟！\n");
	else{
	if(SearchList(head,c-1)){
	storage=head;
	for(d=1;d<c-1;d++) storage=storage->next;	
	a=InsertList(storage,i); 
	if(a==1) printf("插入成功！\n");
	else printf("插入失败！\n"); 
	}
	else printf("插入失败！没有这么多的结点！\n"); 
    }}
    
    if(number==4){
    ElemType a,b,c,e;
    LNode *d;
    d=(LinkedList)malloc(sizeof(LNode));
    d=head;
    printf("请输入要删除结点的位置：");
	scanf("%d",&b);
	while(b<1||b>1000){                                      //进行用户检测 
	printf("输入数据应为不大于1000的正数，请重新输入数据："); 
	fflush(stdin);
	scanf("%d",&b) ;
	} 
	if(SearchList(head,b)){
	for(c=1;c<b-1;c++) d=d->next;
	a=DeleteList(d,&e);
	if(a==1) printf("删除成功！\n");
	else printf("删除失败！\n"); 
	}
	else printf("删除失败！没有那么多的结点！\n");
	}
	
	if(number==5){
	if(head->data>0&&head->data<1000){
		TraverseList(head,&print);
	}
	else printf("该指针并没有指向链表！\n"); 
	}
	
	
	if(number==6){
		ElemType a;
		if(head->data>0&&head->data<1000){
	a=ReverseList(&head);
	if(a==1) {
	 printf("反转成功！\n");
	 TraverseList(head,&print);}
	else printf("反转失败！\n");
}
	else printf("该指针没有指向链表！\n");
	} 
	
	if(number==7){
		ElemType a;
		if(head->data>0&&head->data<1000){
		a=IsLoopList(head);
		if(a==1) printf("链表循环！\n");
		else printf("链表不循环！\n"); 
	}
	else printf("该指针并没有指向链表！\n");
	}
	
    if(number==8){
    	if(head->data>0&&head->data<1000){
    head=ReverseEvenList(&head);
    if(head->next!=NULL) TraverseList(head,&print);
}     
else printf("该指针并没有指向链表！\n");
	} 
	
	if(number==9){
		LNode* p;
		p=(LinkedList)malloc(sizeof(LNode));
		if(head->data>0&&head->data<1000){
			if(head->next==NULL) printf("链表中只有一个结点，即");
			p=head;
		p=FindMidNode(&p);	
		if(p->data!=head->data||head->next==NULL)	
		printf("中间结点的数据为:%d\n",p->data);
		else printf("查找失败！\n"); 
	}
	else printf("该指针并没有指向链表！\n") ; 
	}
	
	if(number==10) break;
	printf("\n");
	printf("\n");
	printf("\n");
	menu();
}
}



