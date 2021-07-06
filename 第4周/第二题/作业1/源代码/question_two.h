#pragma once
#include "Linklist.h"


int swap(int* x, int* y)
{
	*x ^= *y;
	*y ^= *x;
	*x ^= *y;
	return 0;
}


/*��(1) 
  ��������Del_max
  ���ܣ�ɾ������L�е����Ԫ�أ������Ԫ��Ψһ��
  ���룺Node��ָ��L
  �����ɾ�����Ԫ�ص�L  */

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

	if (L->data == 1)  //��Ϊ1
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
	if (s->next == NULL)  //���ֵ�ڱ�β
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
/*��(2)    
  ��������Upsort
  ���ܣ�������L��������
  ���룺Node��ָ��L
  �������L�е�Ԫ����������   */

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
/*��(3) 
  ��������reverse
  ���ܣ���������
  ���룺Node��ָ��L
  ��������ź��L   */

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
/*��(4)
  ��������Devide_a_b
  ���ܣ��������е�����λԪ�����żλԪ�ط���
  ���룺Node��ָ��L,���������L1
  ���������������L��L1   */


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
			//���
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
			t = pL;  //p��¼pL��ǰһ�����
			pL = pL->next;
		}
	}
	return TRUE;
}

/*****completed******/
/*��(5)
  ��������DownUnion
  ���ܣ��ϲ�������������LA��LB���������LA��
  ���룺Node��ָ��LA��LB
  ������ϲ���ӦԪ�غ��LA   */

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
			if (s->data == p->data)//ȥ��
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