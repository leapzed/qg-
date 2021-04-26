#include<stdio.h>
#include<stdlib.h>
#include"./binary_sort_tree.c"
#include"../inc/binary_sort_tree.h"

void menu(){
	printf("					|---      **********      ---|\n");
	printf("					 1.��ʼ����\n"); 
	printf("					 2.��������\n");
	printf("					 3.��������\n");
	printf("					 4.�����������\n");
	printf("					 5.�ݹ��������\n");
	printf("					 6.�����������\n");
	printf("					 7.�ݹ��������\n");
	printf("					 8.�����������\n");
	printf("					 9.�ݹ�������\n");
	printf("					 10.�������\n");
	printf("					 11.�˳�\n");
	printf("					|---      **********      ---|\n");
	printf("					 ��ֱ���������ֽ��ж�Ӧ������");
}

void main(){
	BinarySortTree tree;
	int number;
	int flag=0;
	menu();
	while(1){
		int i;
	scanf("%d",&number);                //������ѡ������� 
    while(number<1||number>11){          //�����û���� 
    printf("					 �����������������蹦�ܶ�Ӧ����ţ�"); 
    fflush(stdin);
    scanf("%d",&number);
    }
    
    if(number==1){
    	if(flag==1) printf("					 �����Ѿ���ʼ����~\n");
    	else{
    		int a;
    		tree.root=NULL;
    		a=BST_init(&tree);
    		if(a==1){
    			flag=1;
    		tree.root->left=NULL;
    		tree.root->right=NULL;
    		tree.root->value=9999;	
    		printf("					 ��ʼ���ɹ���~\n");
			}
			else printf("					 ��ʼ��ʧ����~\n");
    		
		}
	}
	
	if(number==2){
		if(flag==1){
		int a,b;
		printf("					 ������������е����ݣ�");
		scanf("%d",&b);
		while(b<0||b>1000){          //�����û���� 
		printf("\n");
     	printf("					 ���������ޣ���������һ�ΰɣ�"); 
    	fflush(stdin);
    	scanf("%d",&b);
   		 }
		a=BST_insert(&tree, b )	;
		if(a==1) printf("					 ����ɹ���!\n");
		else printf("					 ����ʧ����~\n");
		}
		else{
			printf("					 ����Ҫ�ȳ�ʼ��ѽ~\n");
		}
	}
	
	if(number==3){
		if(flag==1){
		int a,b;
		printf("					 ������Ҫ���ҵ����ݣ�");
		scanf("%d",&b);
		while(b<0||b>10000){          //�����û���� 
		printf("\n");
     	printf("					 ���������ޣ���������һ�ΰɣ�"); 
    	fflush(stdin);
    	scanf("%d",&b);
   		 }
		a=BST_search(&tree,b);
		if(a==1) printf("					 ���������!�����������������\n");
		else printf("					 ������ݲ�������ѽ~\n");	
		}
		else printf("					 ����Ҫ���г�ʼ��ѽ~\n");
	} 
	
	if(number==4){
		if(flag==1){
			int a;
		a=BST_preorderI(&tree, &print)	;
		if(a==1) printf("					 ���������~\n");
		else printf("					 ����ʧ����~\n");
		}
		else printf("					 ����Ҫ���г�ʼ��ѽ~\n");
	}
	
	if(number==5){
		if(flag==1){
			int a;
		a=BST_preorderR(&tree, &print);
		if(a==1) printf("					 ���������~\n");
		else printf("					 ����ʧ����~\n");
		}
		else printf("					 ����Ҫ���г�ʼ��ѽ~\n");	
	} 
	
	if(number==6){
		if(flag==1){
			int a;
		a=BST_inorderI(&tree, &print); 
		if(a==1) printf("					 ���������~\n");
		else printf("					 ����ʧ����~\n");
		}
		else printf("					 ����Ҫ���г�ʼ��ѽ~\n");	
	}
	
	if(number==7){
		if(flag==1){
			int a;
		a=BST_inorderR(&tree, &print); 
		if(a==1) printf("					 ���������~\n");
		else printf("					 ����ʧ����~\n");
		}
		else printf("					 ����Ҫ���г�ʼ��ѽ~\n");	
	}
	
	if(number==8){
		if(flag==1){
			int a;
		a=BST_postorderI(&tree, &print);
		if(a==1) printf("					 ���������~\n");
		else printf("					 ����ʧ����~\n");
		}
		else printf("					 ����Ҫ���г�ʼ��ѽ~\n");	
	}
	
	if(number==9){
		if(flag==1){
			int a;
		a=BST_postorderR(&tree, &print);
		if(a==1) printf("					 ���������~\n");
		else printf("					 ����ʧ����~\n");
		}
		else printf("					 ����Ҫ���г�ʼ��ѽ~\n");
	}
	
	if(number==10){
		if(flag==1){
			int a;
		a=BST_levelOrder(&tree, &print);
		if(a==1) printf("					 ���������~\n");
		else printf("					 ����ʧ����~\n");
		}
		else printf("					 ����Ҫ���г�ʼ��ѽ~\n");
	}
	
	if(number==11) break;
	
	printf("					 ����س�����ִ�й��ܡ�"); 
	getchar();
	getchar();
	system("CLS");
	menu(); 	
	
} 
}
