#include<stdio.h>
#include<stdlib.h>
#include"../inc/binary_sort_tree.h"
#include"./LinkStack.c"
#include"../inc/LinkStack.h"
#include"./AQueue.c"
#include"../inc/AQueue.h"

/**
 * BST initialize
 * @param BinarySortTreePtr BST
 * @return is complete
 */
BST_Status BST_init(BinarySortTreePtr s){
	if(s->root!=NULL){								//�ⲿ�ǵý�BinarySortTreePtr��ʼ�������������ٿռ� ,����root����ΪNULL 
		printf("					 �����Ѿ���ʼ����~\n");
		return false;
	}
	else{
	s->root = (NodePtr) malloc (sizeof(Node));  //�ⲿ��left��rightָ�붼������Ϊ��ֵ����Ҫ��value����Ϊ9999
	if(s->root!=NULL) return 1;
	else return 0;	
	} 
}

/**
 * BST insert
 * @param BinarySortTreePtr BST
 * @param ElemType value to insert
 * @return is successful
 */
BST_Status BST_insert(BinarySortTreePtr s, ElemType data ){			//��Ҫ�ⲿ�����û�б���ʼ�� 
		BinarySortTree p; 
		if(s->root==NULL){
			s->root=(NodePtr)malloc(sizeof(Node));
			s->root->value=data;
			s->root->left=NULL;
			s->root->right=NULL;
			return 1;
		}
		if(s->root->value==9999&&s->root->left==NULL&&s->root->right==NULL)     //�����ʼ����ĵ�һ�β��룬���뵽������ 
		{
			s->root->value = data;
			return 1;
			
		}
		 
		 if(s->root->value!=9999&&s->root->left==NULL)	{
		 s->root->left=(NodePtr)malloc(sizeof(Node));
		 s->root->left->value= data;
		 s->root->left->left=NULL;
		 s->root->left->right=NULL;
		 return 1;	
		 }
		 if(s->root->value!=9999&&s->root->right==NULL) {
		 	s->root->right=(NodePtr)malloc(sizeof(Node));
		 	s->root->right->value=data;
		 	s->root->right->left=NULL;
		 	s->root->right->right=NULL;
		 	return 1;
		 }
		 if(s->root->left->left==NULL){
		 	s->root->left->left=(NodePtr)malloc(sizeof(Node));
		  s->root->left->left->value= data;
		 s->root->left->left->left=NULL;
		 s->root->left->left->right=NULL;
		 return 1;
		 }	
		 if(s->root->left->right==NULL){
		s->root->left->right=(NodePtr)malloc(sizeof(Node));
		  s->root->left->right->value= data;
		 s->root->left->right->left=NULL;
		 s->root->left->right->right=NULL;
		 return 1;
		 }
		p.root=s->root->left;
		BST_insert(&p, data );
		 return 1;	 

}

/**
 * BST delete
 * @param BinarySortTreePtr BST
 * @param ElemType the value for Node which will be deleted
 * @return is successful
 */
BST_Status BST_delete(BinarySortTreePtr s, ElemType data);

/**
 * BST search
 * @param BinarySortTreePtr BST
 * @param ElemType the value to search
 * @return is exist
 */
BST_Status BST_search(BinarySortTreePtr s, ElemType data){
	BinarySortTree p; 
	if(s->root->value==data) return 1;
	if(s->root->right!=NULL) {
		if(s->root->left->value==data||s->root->right->value==data) return 1;
		else {
			int a;
			p.root=s->root->left;
			a=BST_search(&p, data);
			if(a==1) return 1;
			else {
				int b;
				p.root=s->root->right;
				b=BST_search(&p,  data);
				if(b==1) return 1;
				else return 0;
			} 
		}
	} 
	if(s->root->left!=NULL){
	if(s->root->left->value==data) return 1;
	else{
	int a;
			p.root=s->root->left;
			a=BST_search(&p, data);
			if(a==1) return 1;
			else return 0;	
	}	
	}
	else return 0;
}


void print(NodePtr L){
	printf("					 %d\n",L->value);
}

/**
 * BST preorder traversal without recursion  ����ĵ��� 
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
 
BST_Status BST_preorderI(BinarySortTreePtr s, void (*visit)(NodePtr L)){
	if(s->root==NULL){
		printf("					 ����û���κ�ֵѽ~\n"); 
		return 0; 
	}
	else{
	NodePtr q,node;
	LinkStack p;
	node=(NodePtr)malloc(sizeof(Node));
	initLStack(&p);
	q=s->root;
//	printf("1\n"); 
	pushLStack(&p,s->root->value);
	while(isEmptyLStack(&p)!=1){
		popLStack(&p,&(node->value));
		visit(node);	
		if(q->right!=NULL) pushLStack(&p,q->right->value);
		if(q->left!=NULL) {
		pushLStack(&p,q->left->value);
		q=q->left;	
//		printf("1\n"); 
		}	
	}
	while(p.count!=0){
		popLStack(&p,&(node->value));
		visit(node);	
	}
	free(node);
	return 1;
	}}
	
	
	
	
//	NodePtr p,q;
//	if(s->root==NULL){
//		printf("����û���κ�ֵѽ~")��
//		return false; 
//	}
//	if(s->root->left!=NULL) p=s->root->left;
//	while(1){
//	visit(p);
//	if(p->left!=NULL) {
//		q=p;
//		p=p->left;	
//	}	
//	else{
//		p=q;
//		if(p->right!=NULL){
//			q=p;
//		p=p->right;
//		visit(p);	
//		}
//		else
//	}
//	if(p==s->root->left) break;
//	}
//}

/**
 * BST preorder traversal with recursion ����ĵݹ� 
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
BST_Status BST_preorderR(BinarySortTreePtr s, void (*visit)(NodePtr L)){
	BinarySortTree p;
	if(s->root==NULL){
		printf("					 ����û���κ�ֵѽ~\n");
		return 0; 
	}
	visit(s->root);
	if(s->root->left!=NULL){
		int a;
	p.root=s->root->left	;
	a=BST_preorderR(&p, &print);
	if(a==0) return 0;
	}
	if(s->root->right!=NULL){
	int b;
	p.root=s->root->right;
	b=BST_preorderR(&p, &print);
	if(b==0) return 0;	
	}
	return 1;
}

/**
 * BST inorder traversal without recursion ����ĵ��� 
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
BST_Status BST_inorderI(BinarySortTreePtr s, void (*visit)(NodePtr L)){
	if(s->root==NULL){
		printf("					 ����û���κ�ֵѽ~\n");
		return 0; 
	}
	else{
	NodePtr q,node;
	LinkStack p;
	node=(NodePtr)malloc(sizeof(Node));
	initLStack(&p);
	q=s->root;
	if(s->root->right!=NULL) pushLStack(&p,q->right->value);
	pushLStack(&p,q->value);
	while(q->left!=NULL){
	if(q->left->right!=NULL) pushLStack(&p,q->left->right->value);
	pushLStack(&p,q->left->value);
	q=q->left;
			
		
	}
	while(p.count!=0){
		popLStack(&p,&(node->value));
		visit(node);
	}	
	free(node);
	return 1;
	}
}

/**
 * BST inorder traversal with recursion  ����ĵݹ� 
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
BST_Status BST_inorderR(BinarySortTreePtr s, void (*visit)(NodePtr L)){
	BinarySortTree p;
	if(s->root==NULL){
		printf("					 ����û���κ�ֵѽ~\n");
		return 0; 
	}
	if(s->root->left!=NULL){
		int a;
	p.root=s->root->left	;
	a=BST_inorderR(&p, &print);
	if(a==0) return 0;
	}
	visit(s->root);
	if(s->root->right!=NULL){
	int b;
	p.root=s->root->right;
	b=BST_inorderR(&p, &print);
	if(b==0) return 0;	
	}
//	visit(s->root);
//	visit(s->root->right);
	return 1;
}

/**
 * BST preorder traversal without recursion		�����ĵ��� 
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
BST_Status BST_postorderI(BinarySortTreePtr s, void (*visit)(NodePtr L)){
	if(s->root==NULL){
		printf("					 ����û���κ�ֵѽ~\n");
		return 0; 
	}
	else{
	NodePtr q,node;
	LinkStack p;
	node=(NodePtr)malloc(sizeof(Node));
	initLStack(&p);
	q=s->root;
	pushLStack(&p,q->value);
	if(s->root->right!=NULL) pushLStack(&p,q->right->value);
	while(q->left!=NULL){
	pushLStack(&p,q->left->value);	
	q=q->left;
	if(q->right!=NULL) pushLStack(&p,q->right->value);
	}
	while(p.count!=0){
	popLStack(&p,&(node->value));
		visit(node);
	}	
	free(node);
	return 1;
	}
	
}

/**
 * BST postorder traversal with recursion  ����ݹ� 
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
BST_Status BST_postorderR(BinarySortTreePtr s, void (*visit)(NodePtr L)){
	BinarySortTree p;
	if(s->root==NULL){
		printf("					 ����û���κ�ֵѽ~\n");
		return 0; 
	}
	if(s->root->left!=NULL){
	int a;
	p.root=s->root->left	;
	a=BST_postorderR(&p, &print);
	if(a==0) return 0;	
	}
	if(s->root->right!=NULL){
	int b;
	p.root=s->root->right;
	b=BST_postorderR(&p, &print);
	if(b==0) return 0;	
	}
	visit(s->root);
	return 1;
}

/**
 * BST level order traversal	�㼶���� 
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
BST_Status BST_levelOrder(BinarySortTreePtr s, void (*visit)(NodePtr L)){
	if(s->root==NULL){
		printf("					 ����û���κ�ֵѽ~\n");
		return 0; 
	}
	else{
	AQueue p;
	NodePtr q,node;
	InitAQueue(&p);
	EnAQueue(&p, &(s->root->value))	;
	q=s->root;
	while(q->left!=NULL){
		DeAQueue(&p, &(node->value));
		visit(node);
		if(q->left!=NULL) EnAQueue(&p, &(q->left->value))	;
		DeAQueue(&p, &(node->value));
		visit(node);
		if(q->right!=NULL) EnAQueue(&p, &(q->right->value))	;
		if(q->left!=NULL)
		q=q->left;	
	}
	while(p.length!=0){
		DeAQueue(&p, &(node->value));
		visit(node);
	}
	free(node);
	return 1;
	}
}
