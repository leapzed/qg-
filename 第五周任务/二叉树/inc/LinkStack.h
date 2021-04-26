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



//链栈
Statuss initLStack(LinkStack *s);//初始化栈
Statuss isEmptyLStack(LinkStack *s);//判断栈是否为空
Statuss getTopLStack(LinkStack *s,ElemType *e);//得到栈顶元素
Statuss clearLStack(LinkStack *s);//清空栈
Statuss destroyLStack(LinkStack *s);//销毁栈
Statuss LStackLength(LinkStack *s,int *length);//检测栈长度
Statuss pushLStack(LinkStack *s,ElemType data);//入栈
Statuss popLStack(LinkStack *s,ElemType *data);//出栈


#endif 
