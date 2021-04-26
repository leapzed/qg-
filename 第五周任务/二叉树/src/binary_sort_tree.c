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
	if(s->root!=NULL){								//外部记得将BinarySortTreePtr初始化掉，给他开辟空间 ,并给root设置为NULL 
		printf("					 该树已经初始化啦~\n");
		return false;
	}
	else{
	s->root = (NodePtr) malloc (sizeof(Node));  //外部将left和right指针都给设置为空值！还要将value设置为9999
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
BST_Status BST_insert(BinarySortTreePtr s, ElemType data ){			//需要外部检测有没有被初始化 
		BinarySortTree p; 
		if(s->root==NULL){
			s->root=(NodePtr)malloc(sizeof(Node));
			s->root->value=data;
			s->root->left=NULL;
			s->root->right=NULL;
			return 1;
		}
		if(s->root->value==9999&&s->root->left==NULL&&s->root->right==NULL)     //解决初始化后的第一次插入，插入到根里面 
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
 * BST preorder traversal without recursion  先序的迭代 
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
 
BST_Status BST_preorderI(BinarySortTreePtr s, void (*visit)(NodePtr L)){
	if(s->root==NULL){
		printf("					 该树没有任何值呀~\n"); 
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
//		printf("该树没有任何值呀~")；
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
 * BST preorder traversal with recursion 先序的递归 
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
BST_Status BST_preorderR(BinarySortTreePtr s, void (*visit)(NodePtr L)){
	BinarySortTree p;
	if(s->root==NULL){
		printf("					 该树没有任何值呀~\n");
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
 * BST inorder traversal without recursion 中序的迭代 
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
BST_Status BST_inorderI(BinarySortTreePtr s, void (*visit)(NodePtr L)){
	if(s->root==NULL){
		printf("					 该树没有任何值呀~\n");
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
 * BST inorder traversal with recursion  中序的递归 
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
BST_Status BST_inorderR(BinarySortTreePtr s, void (*visit)(NodePtr L)){
	BinarySortTree p;
	if(s->root==NULL){
		printf("					 该树没有任何值呀~\n");
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
 * BST preorder traversal without recursion		后续的迭代 
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
BST_Status BST_postorderI(BinarySortTreePtr s, void (*visit)(NodePtr L)){
	if(s->root==NULL){
		printf("					 该树没有任何值呀~\n");
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
 * BST postorder traversal with recursion  后序递归 
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
BST_Status BST_postorderR(BinarySortTreePtr s, void (*visit)(NodePtr L)){
	BinarySortTree p;
	if(s->root==NULL){
		printf("					 该树没有任何值呀~\n");
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
 * BST level order traversal	层级遍历 
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
BST_Status BST_levelOrder(BinarySortTreePtr s, void (*visit)(NodePtr L)){
	if(s->root==NULL){
		printf("					 该树没有任何值呀~\n");
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
