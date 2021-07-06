#include "f_announce.h"

//===============全局变量=============
int count_cmp = 0, count_move = 0;
//====================================


void Test()
{
    Stu record;
    record.size = 0;
    int choice = -1;
    int tchoice = -1;
    int tempa=0, tempb=0, tempc=0;

    while (choice != 0)
    {
        printf("=====================MENU==================\n");
        printf("1. 导入文件\n");
        printf("2. 直接插入排序\n");
        printf("3. 快速排序\n");
        printf("4. 显示所有记录\n");
        printf("5. 倒置学生信息\n");
        printf("6. 保存学生信息\n");
        printf("0. 退出\n");
        printf("===========================================\n");
        printf("\n请选择:");
        scanf_s("%d", &choice);

        switch (choice)
        {
        case 1://导入文件
            if (load_in(&record)) cout << "文件已读入" << endl;
            else cout << "文件读入失败" << endl;
            break;

        case 2://直接插入排序
            insert_sort(&record);
            count_cmp = 0;
            count_move = 0;
            break;

        case 3://快速排序
            quick_sort(&record,1,record.size);
            cout << "数据规模为：" << record.size << "条记录" << endl;
            cout << "比较次数为:" << count_cmp << endl;
            cout << "移动次数为:" << count_move << endl;
            count_cmp = 0;
            count_move = 0;
            break;

        case 4://显示所有记录
            display(&record);
            break;

        case 5://倒置信息
            reserve(&record);
            break;

        case 6://保存学生信息（写入新文件）
            save(&record);
            break;
        }
    }
}


//===============具体函数================

//completed
/*
函数名：load_in
功能：读入文件 （stu.txt）   Stu S 的首元素不存数据（用于排序）
输入：存储学生信息的Stu结构体指针 S
*/
int load_in(Stu* S)
{
    ifstream ifs;
    ifs.open("stu.txt", ios::in);
    if (!ifs.is_open()) return 0;
    
    string temp;
    int f = 1;
    int i = 1;
    info tmp;
    while (ifs>>temp)
    {
        if (f)
        {
            //cout << temp << "   ";
            S->member[i].number=temp;
        }
        else
        {
            //cout << temp << endl;
            S->member[i].name = temp;
            S->size++;
            i++;
        }
        f = 1 - f;
    }
    ifs.close();
    return 1;
}


//completed
/*
函数名：insert_sort
功能：直接插入排序，并统计比较次数、移动次数      (针对学号排序)
输入：存储学生信息的Stu结构体指针 S
 count_cmp = 0, count_move = 0 为全局变量
*/
void insert_sort(Stu* S)
{
    int i, j;
    int n = S->size;
    //for (i = 1; i <= n; i++)
    //{
    //    S->member[0] = S->member[i];
    //    for (j = i - 1; S->member[0].name < S->member[j].name; j--)
    //    {
    //        S->member[j+1] = S->member[j];
    //        count_move++;
    //        count_cmp++;      //循环语句中退出条件的判断即为一次比较
    //    }
    //    count_cmp++;          //循环退出时又比较了一次
    //    S->member[j + 1] = S->member[0];
    //}
    for (i = 1; i <= n; i++)
    {
        S->member[0] = S->member[i];
        for (j = i - 1; S->member[0].number < S->member[j].number; j--)
        {
            S->member[j+1] = S->member[j];
            count_move++;
            count_cmp++;      //循环语句中退出条件的判断即为一次比较
        }
        count_cmp++;          //循环退出时又比较了一次
        S->member[j + 1] = S->member[0];
    }
    cout << "数据规模为：" << n << "条记录" << endl;
    cout << "比较次数为:" << count_cmp << endl;
    cout << "移动次数为:" << count_move << endl;
}

/*
函数名：quick_sort
功能：快速排序，并统计比较次数、移动次数      (针对学号排序)
输入：存储学生信息的Stu结构体指针 S
 count_cmp = 0, count_move = 0 为全局变量
*/
void quick_sort(Stu* S,int left,int right)
{
    int i = left, j = right;
    info temp;
    if (left < right)
    {
        temp = S->member[left];
        while (i < j)
        {
            while (j > i && S->member[j].number >= temp.number)
            {
                j--;
                count_cmp++;
            }
            S->member[i] = S->member[j];
            count_move++;
            while (i < j && S->member[i].number <= temp.number)
            {
                i++;
                count_cmp++;
            }
            S->member[j] = S->member[i];
            count_move++;
            
        } 
        S->member[i] = temp;
        quick_sort(S, left, i - 1);
        quick_sort(S, j + 1, right);
    }
}
//completed
/*
函数名：display
功能：显示所有学生数据
输入：存储学生信息的Stu结构体指针 S
*/
void display(Stu* S)
{
    for (int i = 1; i <= S->size; i++)
    {
        cout << S->member[i].number << "   " << S->member[i].name << endl;
    }
    cout << endl;
}



/*
函数名：reserve
功能：将表中的记录顺序倒置
输入：存储学生信息的Stu结构体指针 S
*/
void reserve(Stu* S)
{
    info temp;
    int n = S->size;
    for (int i = 1; i <= n / 2; i++)
    {
        temp = S->member[i];
        S->member[i] = S->member[n - i + 1];
        S->member[n - i + 1] = temp;
    }
    cout << "学生信息已倒置" << endl;
}

/*
函数名：save
功能：保存表中的记录。写入新的文本文件
输入：存储学生信息的Stu结构体指针 S
*/
void save(Stu* S)
{
    int n = S->size;
    ofstream ofs;
    ofs.open("stu_save.txt", ios::out | ios::trunc);

    for (int i = 1; i <= n; i++)
    {
        ofs << S->member[i].number << "    " << S->member[i].name << endl;
    }
    ofs.close();
    cout << "学生信息已保存。" << endl;
}