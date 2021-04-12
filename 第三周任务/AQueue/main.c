#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"./AQueue.h"
#include"./AQueue.c"


void menu(){
	printf("*********************************\n");
	printf("1.初始化队列\n2.销毁队列\n3.检查队列是否已满\n4.检查队列是否为空\n5.查看队头元素\n6.确定队列长度\n7.入队\n8.出队\n9.清空队列\n10.遍历队列\n11.退出\n");
	printf("*********************************\n");
	printf("输入你想实现的功能的序号:"); 
}

void main(){
	AQueue p;
	int number;
	menu();
	
	while(1){                              
    scanf("%d",&number);                //输入所选功能序号 
    while(number<1||number>11){          //进行用户检测 
    printf("输入有误，请输入所需功能对应的序号："); 
    fflush(stdin);
    scanf("%d",&number);
    }
    
    if(number==1){
    	InitAQueue(&p);
    	if(p.length==0) printf("初始化成功！\n");
    	else printf("初始化失败！\n");
    	
	}
	
	if(number==2){
		DestoryAQueue(&p);
		if(p.data[0]==NULL&&p.data[1]==NULL) printf("销毁成功！\n");
		else printf("销毁失败！\n");
	}
	
	if(number==3){
		int a;
		a=IsFullAQueue(&p);
		if(a==1) printf("队列已经满啦~\n");
		else printf("队列未满！\n"); 
	}
	
	if(number==4){
		int a;
		a=IsEmptyAQueue(&p);
		if(a==1) printf("该队列为空队列！\n");
		if(a==0) printf("该队列不为空队列！\n");
	}
	
	
	if(number==5){
		int a;
		void *b;
		a=GetHeadAQueue(&p,b);
		if(a==1) {
		printf("获取成功，队头元素为：%s\n",p.data[p.front]);
		}	
		else printf("获取失败！\n");
	}
	
	
	if(number==6){
		int a;
		a=LengthAQueue(&p);
		if(a==10000) printf("获取队列长度失败！\n");
		else printf("获取成功，队列长度为：%d\n",a); 
	}
	
	if(number==7){
		int a;
		char *b;
		b=(char*)malloc(sizeof(char));
		printf("请输入需要入队的数据：");
		scanf("%s",b);
		a=EnAQueue(&p,b);
		if(a==1) printf("入队成功！\n");
		else printf("入队失败！\n");
	}
	
	if(number==8){
		int a;
		a=DeAQueue(&p);
		if(a==1) printf("出队成功！\n");
		else printf("出队失败！\n");
	}
	
	if(number==9){
		ClearAQueue(&p);
		if(p.front==0&&p.rear==0&&p.length==0) printf("清空成功！\n");
		else printf("清空失败！\n");
	}
	
	
	if(number==10){
		int a;
		a=TraverseAQueue(&p,&APrint);
		if(a==1) printf("遍历完成！\n");
		else printf("遍历失败！\n");
	}
	
	if(number==11) break;
	
	printf("输入回车继续执行功能。"); 
	getchar();
	getchar();
	system("CLS");

	menu();
	
	
	
}
}
