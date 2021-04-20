#include<stdio.h>
#include<stdlib.h>
#include"../inc/qgsort.h"
#include"./qgsort.c"

void menu(){
	printf("					|---      **********      ---|\n");
	printf("					 1.插入排序\n");
	printf("					 2.归并排序\n");
	printf("					 3.快速排序\n");
	printf("					 4.计数排序\n");
	printf("					 5.基数计数排序\n");
	printf("					 6.颜色排序(只支持数据0、1、2~)\n");
	printf("					 7.找数组中第n大/小的数据\n");
	printf("					 8.退出\n");
	printf("					|---      **********      ---|\n");
	printf("					 请输入数组的排列方法：");
}

void main(){
	int *p,t,number;
	char *c;
	p=(int*)malloc(sizeof(int));
	c=(char*)malloc(sizeof(char));
	menu();
	while(1){
		int i;
	scanf("%d",&number);                //输入所选功能序号 
    while(number<1||number>10){          //进行用户检测 
    printf("					 输入有误，请输入所需功能对应的序号："); 
    fflush(stdin);
    scanf("%d",&number);
    }
    if(number==8) break;
    printf("					 请输入数组的长度：");
    scanf("%d",&t); 
    while(t<1||t>1000){          //进行用户检测 
    printf("					 PS：数据长度会影响最后的排序结果噢~");
   
    printf("\n");
     printf("					 数据有误，请重新输入数组的长度："); 
    fflush(stdin);
    scanf("%d",&t);
    }
        printf("					 数据之间用空格隔开哟~\n");
    printf("					 请输入数组的数据：");

    while(1){
    	for(i=0;i<t;i++){
    	scanf("%d",p+i);	
    	if(*(p+i)<0) break;
		}
		if(i<t) {
			printf("					 输入错误，不能输入数字外的其他数据哟~\n");
			printf("					 请重新输入:");	
		}
		else break;
	}
	
	if(number==1){
		
	insertSort(p,t);
	}
	
	if(number==2){
		int *q;
//		q=(int*)malloc(sizeof(int));
		q=p;
		MergeSort(p,0,t-1,q);
	}
	
	if(number==3){
		QuickSort_Recursion(p, 0, t-1);
	}
	
	
	if(number==4){
		int max=0;
		for(i=0;i<t;i++) {
			if(*(p+i)>max) max=*(p+i);
		} 
		CountSort(p, t , max);
	} 
	
	if(number==5){
		RadixCountSort(p,t);
	}
	
	if(number==6){
		ColorSort(p,t);
	}
	
	if(number==7){
		int k;
		char c;
		printf("					 a.找第n大的数据\n");
		printf("					 b.找第n小的数据\n");
		printf("					 请输入需要实现的功能：");
		fflush(stdin);
		scanf("%c",&c); 
		
    while(c!='a'&&c!='b'){          //进行用户检测 
    printf("					 输入有误，输入前请不要加空格或其它字母噢，请重新输入：");  
    scanf("%c",&c);
    }
    printf("					 请输入n的值："); 
		scanf("%d",&k);                //输入所选功能序号 
    while(k<1||k>t){          //进行用户检测 
    printf("					 输入有误，请输入在长度范围内的数据："); 
    fflush(stdin);
    scanf("%d",&k);
    }
    	Findnthnumber(p, t);
    	if(c=='b') 
    printf("					 第n小的值为：%d\n",*(p+k-1));
	if(c=='a') printf("					 第n大的值为：%d\n",*(p+t-k));
	} 
    
	
	if(number!=7){
	for(i=0;i<t;i++){
	if(i==0) 
    	printf("					 %d ",*(p+i));	
    	if(i<t-1&&i>0) printf("%d ",*(p+i));
    	if(i==t-1) printf("%d\n",*(p+i));
	}	
	} 
	
	
	printf("					 输入回车继续执行功能。"); 
	getchar();
	getchar();
	getchar();
	system("CLS");
	menu(); 
	 }
    
    
    
    
   	
    

}


