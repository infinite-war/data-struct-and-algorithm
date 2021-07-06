#include "gloabledef.h"

//学生记录
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




//函数声明
void Test();	//执行程序
int load_in(Stu* S);	 //导入文件
void insert_sort(Stu* S);//直接插入排序
void quick_sort(Stu* S,int left,int right); //快速排序	
void display(Stu* S);	 //显示所有记录
void reserve(Stu* S);    //倒置内容
void save(Stu* S);       //保存内容