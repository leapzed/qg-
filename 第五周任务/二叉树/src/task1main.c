#include<stdio.h>
#include<stdlib.h>
#include"./binary_sort_tree.c"
#include"../inc/binary_sort_tree.h"

void menu(){
	printf("					|---      **********      ---|\n");
	printf("					 1.初始化树\n"); 
	printf("					 2.插入数字\n");
	printf("					 3.查找数字\n");
	printf("					 4.迭代先序遍历\n");
	printf("					 5.递归先序遍历\n");
	printf("					 6.迭代中序遍历\n");
	printf("					 7.递归中序遍历\n");
	printf("					 8.迭代后序遍历\n");
	printf("					 9.递归后序遍历\n");
	printf("					 10.层序遍历\n");
	printf("					 11.退出\n");
	printf("					|---      **********      ---|\n");
	printf("					 请直接输入数字进行对应操作：");
}

void main(){
	BinarySortTree tree;
	int number;
	int flag=0;
	menu();
	while(1){
		int i;
	scanf("%d",&number);                //输入所选功能序号 
    while(number<1||number>11){          //进行用户检测 
    printf("					 输入有误，请输入所需功能对应的序号："); 
    fflush(stdin);
    scanf("%d",&number);
    }
    
    if(number==1){
    	if(flag==1) printf("					 该树已经初始化啦~\n");
    	else{
    		int a;
    		tree.root=NULL;
    		a=BST_init(&tree);
    		if(a==1){
    			flag=1;
    		tree.root->left=NULL;
    		tree.root->right=NULL;
    		tree.root->value=9999;	
    		printf("					 初始化成功啦~\n");
			}
			else printf("					 初始化失败辽~\n");
    		
		}
	}
	
	if(number==2){
		if(flag==1){
		int a,b;
		printf("					 请输入插入树中的数据：");
		scanf("%d",&b);
		while(b<0||b>1000){          //进行用户检测 
		printf("\n");
     	printf("					 数据有误噢，重新输入一次吧："); 
    	fflush(stdin);
    	scanf("%d",&b);
   		 }
		a=BST_insert(&tree, b )	;
		if(a==1) printf("					 插入成功啦!\n");
		else printf("					 插入失败辽~\n");
		}
		else{
			printf("					 该树要先初始化呀~\n");
		}
	}
	
	if(number==3){
		if(flag==1){
		int a,b;
		printf("					 请输入要查找的数据：");
		scanf("%d",&b);
		while(b<0||b>10000){          //进行用户检测 
		printf("\n");
     	printf("					 数据有误噢，重新输入一次吧："); 
    	fflush(stdin);
    	scanf("%d",&b);
   		 }
		a=BST_search(&tree,b);
		if(a==1) printf("					 查找完成啦!存在这个数据在树中\n");
		else printf("					 这个数据不在树中呀~\n");	
		}
		else printf("					 该树要进行初始化呀~\n");
	} 
	
	if(number==4){
		if(flag==1){
			int a;
		a=BST_preorderI(&tree, &print)	;
		if(a==1) printf("					 遍历完成辽~\n");
		else printf("					 遍历失败辽~\n");
		}
		else printf("					 该树要进行初始化呀~\n");
	}
	
	if(number==5){
		if(flag==1){
			int a;
		a=BST_preorderR(&tree, &print);
		if(a==1) printf("					 遍历完成辽~\n");
		else printf("					 遍历失败辽~\n");
		}
		else printf("					 该树要进行初始化呀~\n");	
	} 
	
	if(number==6){
		if(flag==1){
			int a;
		a=BST_inorderI(&tree, &print); 
		if(a==1) printf("					 遍历完成辽~\n");
		else printf("					 遍历失败辽~\n");
		}
		else printf("					 该树要进行初始化呀~\n");	
	}
	
	if(number==7){
		if(flag==1){
			int a;
		a=BST_inorderR(&tree, &print); 
		if(a==1) printf("					 遍历完成辽~\n");
		else printf("					 遍历失败辽~\n");
		}
		else printf("					 该树要进行初始化呀~\n");	
	}
	
	if(number==8){
		if(flag==1){
			int a;
		a=BST_postorderI(&tree, &print);
		if(a==1) printf("					 遍历完成辽~\n");
		else printf("					 遍历失败辽~\n");
		}
		else printf("					 该树要进行初始化呀~\n");	
	}
	
	if(number==9){
		if(flag==1){
			int a;
		a=BST_postorderR(&tree, &print);
		if(a==1) printf("					 遍历完成辽~\n");
		else printf("					 遍历失败辽~\n");
		}
		else printf("					 该树要进行初始化呀~\n");
	}
	
	if(number==10){
		if(flag==1){
			int a;
		a=BST_levelOrder(&tree, &print);
		if(a==1) printf("					 遍历完成辽~\n");
		else printf("					 遍历失败辽~\n");
		}
		else printf("					 该树要进行初始化呀~\n");
	}
	
	if(number==11) break;
	
	printf("					 输入回车继续执行功能。"); 
	getchar();
	getchar();
	system("CLS");
	menu(); 	
	
} 
}
