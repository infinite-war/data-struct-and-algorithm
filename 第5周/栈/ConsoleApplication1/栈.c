#include "函数声明.h"


void againMalloc(SqStack* S) 
{
	/*空间扩展为原来的2倍，并由p指针所指向，原内容自动拷贝到p所指向的存储空间*/
	ElemType* p = (ElemType*)realloc((S->data), 2 * S->size * (sizeof(ElemType)));
	if (!p)
	{ 
		printf("存储空间分配失败！");
		exit(1);
	}
	S->data = p; /*使list指向新线性表空间*/
	S->size = 2 * S->size; /*线性表空间大小修改为新的长度*/
}



/*函数名：IfEmpty
  功能：判断s是不是空栈
  输入：SqStack型指针s
  输出：判断S是不是空表栈  */
int IfEmpty(SqStack *S)
{
	if (S->length == 0)
	{
		printf("这是个空栈！\n");
		return ERROR;
	}
	return TRUE;
}

//completed
/*函数名：InitStack
  功能：初始化栈
  输入：SqStack型指针s
  输出：构造栈   */
int InitStack(SqStack *S)
{
	S->data = (ElemType*)malloc(MAXSIZE * sizeof(ElemType));
	S->length = 0;
	S->size = MAXSIZE;
	return TRUE;
}

//completed
/*函数名：SqStackLen
  功能：栈的长度
  输入：SqStack型指针s
  输出：S的长度   */
int Stacklen(SqStack *S)
{
	return  S->length;
}

//completed
/*函数名：ClearStack
  功能：清空栈
  输入：SqStack型指针s
  输出：清空栈S  */
void ClearStack(SqStack * S)
{
	free(S->data);
	S->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
	S->length = 0;   /* 长度为0 */
	S->size = MAXSIZE; /* 当前存储容量初始化 */
}

//completed
/*函数名：GetTop
  功能：返回栈顶元素
  输入：SqStack型指针s，栈顶位置e
  输出：取S的第e个位置的元素 */
int GetTop(SqStack *S, ElemType *e)
{
	if (S->length == 0)
		return ERROR;
	else
		*e = S->data[S->length-1];
	return TRUE;
}

//completed
/*函数名：Push
  功能：入栈
  输入：SqStack型指针s，待插入元素item
  输出：将item插入L的位置i   */
int Push(SqStack*S, ElemType item)
{
	if (S->length == S->size)  againMalloc(S);
	S->data[S->length++] = item;
	return TRUE;
}


/*函数名：Pop
  功能：出栈
  输入：SqStack型指针S，待出元素
  输出：删除S的栈顶元素   */
int Pop(SqStack*S, ElemType *e)
{
	if (S->length == 0)
	{
		printf("the Stack is empty\n");
		return ERROR;
	}
	*e = S->data[S->length];
	S->length--;
	return TRUE;
}



/*函数名：DisSqStack
  功能：输出栈
  输入：SqStack型指针S
  输出：输出S   */
int DisSqStack(SqStack* S)
{
	if (S->length == 0)
	{
		printf("the Stack is empty!\n");
		return ERROR;
	}
	printf("Stack: ");
	for (int i = 0; i < S->length; i++)
	{
		if (i == S->length - 1) printf("%d\n", S->data[i]);
		else printf("%d ", S->data[i]);
	}
	return TRUE;
}

void   SqStackTest()
{
	SqStack S;

	int choice =-1;
	int InputNum;
	int i, result;
	ElemType top,e,input;

	while (choice != 0)
	{
		printf("栈的顺序存储示例:\n");
		printf("1. 建立栈\n");
		printf("2. 输入栈\n");
		printf("3. 返回栈顶元素\n");
		printf("4. 入栈\n");
		printf("5. 出栈\n");
		printf("6. 输出栈的全部元素\n");
		printf("7. 火车调度问题\n");
		printf("0. 退出\n\n");
		printf("\n请选择:");
		scanf_s("%d", &choice);

		switch (choice)
		{
		case 1://建立栈
			if (!InitStack(&S))
			{
				printf("建立失败!\n");
				break;
			}
			printf("建立成功!\n");
			break;

		case 2://输入栈
			ClearStack(&S);
			printf("请输入要放入几个元素：");
			scanf_s("%d", &InputNum);
			printf("按次序输入元素：");
			for (int i = 1; i <= InputNum; i++)
			{
				scanf_s("%d", &e);
				Push(&S, e);
			}
			DisSqStack(&S);
			break;

		case 3: //输出栈顶
			GetTop(&S, &top);
			printf("get top element %d\n", top);
			break;

		case 4://入栈
			printf("请输入要插入的值input：");
			scanf_s("%d", &input);
			Push(&S, input);
			break;

		case 5://出栈
			Pop(&S, &e);
			printf("已出栈");
			break;

		case 6://输出
			DisSqStack(&S);
			break;

		case 7:
			printf("分支选项\n");
			int o=-1; 
			while(1)
			{
				printf("1. 输入测试样例。\n");
				printf("0. 退出该分支。\n\n");
				printf("请选择：");
				scanf("%d", &o);
				if (o == 0) break;
				else if (o != 1)
				{
					printf("error input!\n");
					continue;
				}
				printf("输入原字符a：");
				int a[1000];
				char t[1000];
				int l = 0;
				scanf("%s", t);
				for (int i = 0; i < strlen(t); i++)
				{
					if (t[i] == 'A')  a[l++] = 1;
					else if (t[i] == 'B') a[l++] = 2;
					else if (t[i] == 'C')  a[l++] = 3;
					else a[l++] = 4;
				}
				SqStack S1;
				SqStack S2;
				InitStack(&S1);
				InitStack(&S2);
				for (int i = 0; i < l; i++)
				{
					if (a[i] == 1) Push(&S2, 'A');
					else if (a[i] == 2) Push(&S1, 'B');
					else if (a[i] == 3) printf("C");
					else continue;
				}
				if (S1.length > 0)
				{
					for (int i = 0; i < S1.length; i++)  printf("B");
				}
				if (S2.length > 0)
				{
					for (int i = 0; i < S2.length; i++)  printf("A");
				}
				printf("\n");
			}
		case 0:
			exit(0);
		}
	}

}