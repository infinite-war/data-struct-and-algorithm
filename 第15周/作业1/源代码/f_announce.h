#include "gloabledef.h"

//ѧ����¼
typedef struct info
{
	string number;
	string name;
}infomation;

typedef struct Student
{
	infomation  member[MAXSIZE];
	int size;
}Stu;




//��������
void Test();	//ִ�г���
int load_in(Stu* S);	 //�����ļ�
void insert_sort(Stu* S);//ֱ�Ӳ�������
void quick_sort(Stu* S,int left,int right); //��������	
void display(Stu* S);	 //��ʾ���м�¼
void reserve(Stu* S);    //��������
void save(Stu* S);       //��������