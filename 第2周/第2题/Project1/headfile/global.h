#pragma once
#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status; //Status �Ǻ�������ֵ���ͣ���ֵ�Ǻ������״̬���롣
typedef int ElemType; //ElemType Ϊ�ɶ�����������ͣ�����Ϊint����

#define MAXSIZE 100			//˳�����ܴﵽ����󳤶�
typedef struct Book {
	char id[14];//ISBN
	char name[30];//����
	int price;//����
}Book;
typedef struct SqList {
	Book* elem; //�洢�ռ�Ļ���ַ
	int length; //��ǰ����
} SqList;

Status InitList_Sq(SqList* L) { //�㷨2.1 ˳���ĳ�ʼ��
	//����һ���յ�˳���L
	L->elem = (Book*)malloc(sizeof(Book) * MAXSIZE); //Ϊ˳������һ����СΪMAXSIZE������ռ�
	if (!L->elem)
		exit(OVERFLOW); //�洢����ʧ���˳�
	L->length = 0; //�ձ���Ϊ0
	return OK;
}

Status GetElem(SqList L, int i, Book* e) {//�㷨2.2��˳����ȡֵ
	if (i < 1 || i > L.length)
		return ERROR; //�ж�iֵ�Ƿ����������������ERROR
	*e = L.elem[i - 1]; //elem[i-1]��Ԫ�洢��i������Ԫ��
	return OK;
}

int LocateElem_Sq(SqList L, int e) { //�㷨2.3 ˳���Ĳ���
	//˳���Ĳ���
	int i;
	for (i = 0; i < L.length; i++)
		if (L.elem[i].price == e)
			return i + 1;//���ҳɹ����������i+1
	return 0;//����ʧ�ܣ�����0
}

Status ListInsert_Sq(SqList* L, int i, Book e) { //�㷨2.4 ˳���Ĳ���
	//��˳���L�е�i��λ��֮ǰ�����µ�Ԫ��e
	//iֵ�ĺϷ���Χ��1<=i<=L.length+1
	int j;
	if ((i < 1) || (i > L->length + 1))
		return ERROR; //iֵ���Ϸ�
	if (L->length == MAXSIZE)
		return ERROR; //��ǰ�洢�ռ�����

	for (j = L->length - 1; j >= i - 1; j--)
		L->elem[j + 1] = L->elem[j]; //����λ�ü�֮���Ԫ�غ���
	L->elem[i - 1] = e; //����Ԫ��e�����i��λ��
	++L->length; //����1
	return OK;
}

Status ListDelete_Sq(SqList* L, int i) { //�㷨2.5 ˳����ɾ��
	//��˳���L��ɾ����i��Ԫ�أ�����e������ֵ
	//iֵ�ĺϷ���Χ��1<=i<=L.length
	int j;
	if ((i < 1) || (i > L->length))
		return ERROR; //iֵ���Ϸ�

	for (j = i; j <= L->length; j++)
		L->elem[j - 1] = L->elem[j]; //��ɾ��Ԫ��֮���Ԫ��ǰ��
	--L->length; //����1
	return OK;
}
