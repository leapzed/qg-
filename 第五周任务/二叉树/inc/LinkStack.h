#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef enum Status 
{
    ERROR = 0, 
	SUCCESS = 1
} Statuss;

typedef int ElemType;

typedef  struct StackNode
{
	ElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr top;
	int	count;
}LinkStack;



//��ջ
Statuss initLStack(LinkStack *s);//��ʼ��ջ
Statuss isEmptyLStack(LinkStack *s);//�ж�ջ�Ƿ�Ϊ��
Statuss getTopLStack(LinkStack *s,ElemType *e);//�õ�ջ��Ԫ��
Statuss clearLStack(LinkStack *s);//���ջ
Statuss destroyLStack(LinkStack *s);//����ջ
Statuss LStackLength(LinkStack *s,int *length);//���ջ����
Statuss pushLStack(LinkStack *s,ElemType data);//��ջ
Statuss popLStack(LinkStack *s,ElemType *data);//��ջ


#endif 
