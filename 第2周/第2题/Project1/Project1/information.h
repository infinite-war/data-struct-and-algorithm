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