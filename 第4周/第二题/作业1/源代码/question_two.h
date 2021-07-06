#pragma once
#include "Linklist.h"


int swap(int* x, int* y)
{
	*x ^= *y;
	*y ^= *x;
	*x ^= *y;
	return 0;
}


/*题(1) 
  函数名：Del_max
  功能：删除链表L中的最大元素（假设该元素唯一）
  输入：Node型指针L
  输出：删除最大元素的L  */

int Del_max(Node* L)
{
	if (IfEmpty(L) == ERROR) return ERROR;

	Node* p = L;
	Node* s = (Node*)malloc(sizeof(Node));
	Node* front = (Node*)malloc(sizeof(Node));
	if (NULL == s && NULL == front)
	{
		printf("mission failed.\n");
		return ERROR;
	}

	if (L->data == 1)  //表长为1
	{
		s = L->next;
		L->next = NULL;
		free(s);
		L->data--;
		return TRUE;
	}

	int temp = 1;
	int max = L->next->data;
	while (p->next!= NULL)
	{
		if (p->next->data > max)
		{
			max = p->next->data;
			front = p;
			s = p->next;
		}
		p = p->next;
	}
	if (s->next == NULL)  //最大值在表尾
	{
		front->next = NULL;
		free(s);
		L->data--;
		return TRUE;
	}
	front->next = front->next->next;
	free(s);
	L->data--;
	return TRUE;
}



//completed
/*题(2)    
  函数名：Upsort
  功能：将链表L升序排序
  输入：Node型指针L
  输出：将L中的元素升序排序   */

int Upsort(Node* L)
{
	if (IfEmpty(L) == ERROR) return ERROR;
	if (L->data == 1)
	{
		printf("Upsort completed.\n");
		return TRUE;
	}

	Node* p = L;
	Node* s = L->next->next;
	Node* t = s;
	L->next->next = NULL;

	
	while (s != NULL)
	{
		p = L->next;
		if (s->data <= p->data)
		{
			s = s->next;
			t->next = p;
			L->next = t;
			t = s;
			continue;
		}
		else
		{
			while (p->next != NULL)
			{
				if (s->data >= p->data && s->data <= p->next->data)
				{
					s = s->next;
					t->next = p->next;
					p->next = t;
					t = s;
					break;
				}
				p = p->next;
			}
			if (p->next == NULL)
			{
				s = s->next;
				p->next = t;
				t->next = NULL;
				t = s;
			}
		}
	}

	printf("Upsort completed.\n");
	return TRUE;
}



/*****completed******/
/*题(3) 
  函数名：reverse
  功能：将链表倒排
  输入：Node型指针L
  输出：倒排后的L   */

int reverse(Node* L)
{
	if (IfEmpty(L) == ERROR) return ERROR;
	if (L->data == 1)
	{
		printf("recerse completed!\n");
		return TRUE;
	}
	int length = L->data;
	Node* p = L;
	Node* s = L->next->next;
	Node* t = s;
	p->next->next = NULL;
	while (s!= NULL)
	{
		HeadInsert(L, s->data);
		s = s->next;
		free(t);
		t = s;
	}
	L->data = length;
	printf("reverse completed!\n");
	return TRUE;
}

/*****completed******/
/*题(4)
  函数名：Devide_a_b
  功能：将链表中第奇数位元素与第偶位元素分离
  输入：Node型指针L,带填充链表L1
  输出：分离整理后的L，L1   */


int Devide_a_b(Node* L,Node* L1)
{
	if (IfEmpty(L) == ERROR) return ERROR;
	Node* pL = L->next;
	Node* pL1 = L1;
	Node* t = pL;  
	int s = 1;
	int len = 0;
	while (pL != NULL)
	{
		if (s % 2 == 0)
		{
			//添加
			Node* w = pL;
			pL1->next = w;
			pL1=pL1->next;
            
			t->next = w->next;
			pL = t->next;

			pL1->next = NULL;
			L1->data++;
			L->data--;
			s++;
		}
		else
		{
			s++;
			t = pL;  //p记录pL的前一个结点
			pL = pL->next;
		}
	}
	return TRUE;
}

/*****completed******/
/*题(5)
  函数名：DownUnion
  功能：合并两个升序链表LA，LB，结果放在LA中
  输入：Node型指针LA，LB
  输出：合并相应元素后的LA   */

int DownUnion(Node* LA, Node* LB)
{
	if (LB->data == 0)
	{
		printf("Unoin completed.\n");
		return TRUE;
	}

	Node* p = LA;
	Node* s = LB->next;
	Node* t = s;


	while (s != NULL)
	{
		p = LA->next;
		if (s->data <= p->data)
		{
			if (s->data == p->data)//去重
			{
				s = s->next;
				//free(t);
				t = s;
				LB->data--;
				continue;
			}

			s = s->next;
			t->next = p;
			LA->next = t;
			t = s;
			LA->data++;
			LB->data--;
			continue;
		}

		else
		{
			while (p->next != NULL)
			{
				if (s->data > p->data && s->data < p->next->data)
				{
					s = s->next;
					t->next = p->next;
					p->next = t;
					t = s;
					LA->data++;
					LB->data--;
					break;
				}
				p = p->next;
			}
			if (p->next == NULL)
			{

				if (p->data < s->data)
				{
					s = s->next;
					p->next = t;
					t->next = NULL;
					t = s;
					LA->data++;
					LB->data--;
				}
				else
				{
					s = s->next;
					free(t);
					t = s;
					LB->data--;
				}
			}
		}
	}

	printf("Union completed.\n");
	return TRUE;
}