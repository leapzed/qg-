#include<stdio.h>
#include<stdlib.h>
#include"./LQueue.h"
#include"./LQueue.c"


void menu(){
	printf("*********************************\n");
	printf("1.初始化队列\n2.销毁队列\n3.检查队列是否为空\n4.查看队头元素\n5.确定队列长度\n6.入队\n7.出队\n8.清空队列\n9.遍历队列\n10.退出\n");
	printf("*********************************\n");
	printf("输入你想实现的功能的序号:"); 
}

void main(){
	LQueue p;
	int number;
	int flag=0;
	menu();
	
	while(1){                              
    scanf("%d",&number);                //输入所选功能序号 
    while(number<1||number>11){          //进行用户检测 
    printf("输入有误，请输入所需功能对应的序号："); 
    fflush(stdin);
    scanf("%d",&number);
    }
    
    if(number==1){
    	if(flag==0){
		p.front=p.rear=(Node*)malloc(sizeof(Node));
		InitLQueue(&p);
    	if(p.length==0) {
    	printf("初始化成功！\n");	
    	flag=1;
		}
    	else printf("初始化失败！\n");
		}
		else	printf("再次初始化前请先销毁原队列哟！\n");
    
	}
	
	if(number==2){
		if(flag==1){
		DestoryLQueue(&p);
		if(p.length==10000) {
		printf("销毁成功！\n");	
		flag=0;
		}
		
		else printf("销毁失败！\n");	
		}
		else printf("队列还没有被初始化哟~\n");
		
	}
	
	if(number==3){
		int a;
		if(flag==1){
			a=IsEmptyLQueue(&p);
		if(a==1) printf("该队列为空队列~\n");
		else printf("该队列不为空队列~\n");
		}
		else printf("队列还没有被初始化哟~\n");
		
	}
	
	if(number==4){
		int a;
		void *b;
		if(flag==1){
			a=GetHeadLQueue(&p,b);
		if(a==1) {
		printf("获取成功，队头元素为：%s\n",(char*)p.front->next->data);
		}	
		else printf("获取失败！\n");	
		}
		else printf("队列还没有被初始化哟~\n");
	
	}
    
    if(number==5){
    	int a;
    	if(flag==1){
    	a=LengthLQueue(&p);
    	if(a==0) printf("获取队列长度失败！\n");
		else printf("队列长度为：%d\n",a); 	
		}
		else printf("队列还没有被初始化哟~\n");
    	
	}
	
	if(number==6){
		int a;
		char* b;
		b=(char*)malloc(sizeof(char));
		if(flag==1){
		printf("请输入需要入队的数据：");
		scanf("%s",b);
		a=EnLQueue(&p,b);
		if(a==1) printf("入队成功！\n");
		else printf("入队失败！\n");	
		}
		else printf("队列还没有被初始化哟~\n");
		
	}
	
	if(number==7){
		int a;
		if(flag==1){
		a=DeLQueue(&p);
		if(a==1) printf("出队成功！\n");
		else printf("出队失败！\n"); 
		}
		else  printf("队列还没有被初始化哟~\n");
		
	}
	
	if(number==8){
		if(flag==1){
		ClearLQueue(&p);
		if(p.length==0) printf("清空成功！\n");
		else printf("清空失败！\n");	
		}
		else  printf("队列还没有被初始化哟~\n");
	}
	
	if(number==9){
		int a;
		if(flag==1){
			a=TraverseLQueue(&p,&LPrint);
			if(a==1) printf("遍历完成！\n");
			else printf("遍历失败！\n");
		}
		else  printf("队列还没有被初始化哟~\n");
	}
    
    
    if(number==10) break;
	
	printf("输入回车继续执行功能。"); 
	getchar();
	getchar();
	system("CLS");

	menu();
    
	}
}
