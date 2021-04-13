#include <stdio.h>
#include <stdlib.h>
#include ".\SqStack.h"
#include ".\SqStack.c"

#define OVERFLOW -1

void menu(){
	printf("*********************************\n");
	printf("1.初始化栈\n2.判断栈是否为空\n3.得到栈顶元素\n4.清空栈\n5.销毁栈\n6.检测栈的大小\n7.入栈\n8.出栈\n9.退出\n");
	printf("*********************************\n");
	printf("输入你想实现的功能的序号:");
}

void main(){
	SqStack p;
	ElemType number;
	menu();
	while(1){
	scanf("%d",&number);                //输入所选功能序号 
    while(number<1||number>10){          //进行用户检测 
    printf("输入有误，请输入所需功能对应的序号："); 
    fflush(stdin);
    scanf("%d",&number);
    }
    
    if(number==1){
    ElemType a,b;
    printf("请输入你想初始化栈的大小：");
	scanf("%d",&b);
	while(b<1||b>1500){                                      //进行用户检测 
	printf("输入数据应为不大于1500的正数，请重新输入数据："); 
	fflush(stdin);
	scanf("%d",&b) ;
	}  
	
    a=initStack(&p,b);
    if(a==1) printf("初始化成功！\n");
    else printf("初始化失败！\n"); 
	}
	
	if(number==2){
	ElemType a;
	
	if(p.size<=0||p.size>1500)
	printf("栈还没有被初始化！\n");
	else{
		a=isEmptyStack(&p);
	if(a==1) printf("该栈为空栈！\n");
    else printf("该栈不为空栈！\n"); 
	}
	
	
	
	} 
	
	if(number==3){
	ElemType a,b;
	a=getTopStack(&p,&b);
	if(a==1) printf("栈顶元素数据大小为：%d\n",b);
	else printf("获取失败！\n");	
	}
	
	if(number==4){
		ElemType a;
		a=clearStack(&p);
		if(a==1) printf("清空成功！\n");
		else printf("清空失败！\n");
	}
	
	if(number==5){
	ElemType a;
	a=destroyStack(&p);
	if(a==1) printf("销毁成功！\n");
	else printf("销毁失败！\n");	
	}
	
	if(number==6){
		ElemType a,b;
		a=stacklength(&p,&b);
		if(a==1) printf("栈的大小为：%d\n",b);
		else printf("获取栈的大小失败！\n"); 
	}
	
	if(number==7){
	ElemType a,b,i;
	printf("请输入需要入栈的数据：");
	scanf("%d",&b);
	while(b<1||b>1000){                                      //进行用户检测 
	printf("输入数据应为不大于1000的正数，请重新输入数据："); 
	fflush(stdin);
	scanf("%d",&b);
	}  
	if(p.size<0||p.size>1500)
	printf("请先初始化栈！\n");
	else{
		p.elem++;
	a=pushStack(&p,b);
	if(a==1) printf("入栈成功！\n");
	else printf("入栈失败！\n");
	}}
	
	if(number==8){
	ElemType a,b;
	a=popStack(&p,&b);
	if(a==1) printf("出栈成功，出栈数据为：%d\n",b);
	else printf("出栈失败！\n"); 
	}
	
	if(number==9){
	break; 
	}
	printf("输入回车继续执行功能。"); 
	getchar();
	getchar();
	system("CLS");

	menu();
} 
}
