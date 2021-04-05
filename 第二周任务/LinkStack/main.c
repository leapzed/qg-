#include <stdio.h>
#include <stdlib.h>
#include "./LinkStack.h"
#include "./LinkStack.c"

void menu(){
	printf("*********************************\n");
	printf("1.初始化栈\n2.判断栈是否为空\n3.得到栈顶元素\n4.清空栈\n5.销毁栈\n6.检测栈的长度\n7.入栈\n8.出栈\n9.退出\n");
	printf("*********************************\n");
	printf("输入你想实现的功能的序号:");
}

void main(){
	LinkStack p;
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
    	ElemType a;
    	a=initLStack(&p);
    	if(a==1) printf("初始化成功！\n");
    	else printf("初始化失败！\n"); 
	}
	
	if(number==2){
		ElemType a;
		if(p.count>1000||p.count<0)
		printf("该栈还没有被初始化哟！\n");
		else{
		a=isEmptyLStack(&p);
		if(a==1) printf("该栈为空栈！\n");
    	else printf("该栈不为空栈！\n");
    }
	}
	
	if(number==3){
		ElemType a,b;
		a=getTopLStack(&p,&b);
		if(a==1) {
			printf("栈顶元素为：%d\n",b);
		}
		else printf("获取失败！\n");
	}
	
	if(number==4){
		ElemType a;
		a=clearLStack(&p);
		if(a==1) printf("清空成功！\n");
		else printf("清空失败！\n");
	}
	
	if(number==5){
		ElemType a;
		a=destroyLStack(&p);
		if(a==1) printf("销毁成功！\n");
		else printf("销毁失败！\n");
	}
	
	if(number==6){
		ElemType a,b;
		a=LStackLength(&p,&b);
		if(a==1) printf("栈的长度为：%d\n",b);
		else printf("获取栈的长度失败！\n"); 
	}
	
	if(number==7){
		ElemType a,b;
	printf("请输入需要入栈的数据：");
	scanf("%d",&b);
	while(b<1||b>1000){                                      //进行用户检测 
	printf("输入数据应为不大于1000的正数，请重新输入数据："); 
	fflush(stdin);
	scanf("%d",&b) ;
	}  
	if(p.count>1000||p.count<0)
	printf("请先初始化栈哟！\n");
	else{
	a=pushLStack(&p,b);
	if(a==1) printf("入栈成功！\n");
	else printf("入栈失败！\n");
	}
	}
	
	if(number==8){
		ElemType a,b;
		if(p.count>1000||p.count<0)
	printf("请先初始化栈哟！\n");
	a=popLStack(&p,&b);
	if(a==1) printf("出栈成功，出栈数据为：%d\n",b);
	else printf("出栈失败！\n");
	} 
	
	if(number==9){
		break;
	}
	
	printf("\n");
	printf("\n");
	printf("\n");
	menu(); 
	
	
}
}
