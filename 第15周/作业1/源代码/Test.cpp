#include "f_announce.h"

//===============ȫ�ֱ���=============
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
        printf("1. �����ļ�\n");
        printf("2. ֱ�Ӳ�������\n");
        printf("3. ��������\n");
        printf("4. ��ʾ���м�¼\n");
        printf("5. ����ѧ����Ϣ\n");
        printf("6. ����ѧ����Ϣ\n");
        printf("0. �˳�\n");
        printf("===========================================\n");
        printf("\n��ѡ��:");
        scanf_s("%d", &choice);

        switch (choice)
        {
        case 1://�����ļ�
            if (load_in(&record)) cout << "�ļ��Ѷ���" << endl;
            else cout << "�ļ�����ʧ��" << endl;
            break;

        case 2://ֱ�Ӳ�������
            insert_sort(&record);
            count_cmp = 0;
            count_move = 0;
            break;

        case 3://��������
            quick_sort(&record,1,record.size);
            cout << "���ݹ�ģΪ��" << record.size << "����¼" << endl;
            cout << "�Ƚϴ���Ϊ:" << count_cmp << endl;
            cout << "�ƶ�����Ϊ:" << count_move << endl;
            count_cmp = 0;
            count_move = 0;
            break;

        case 4://��ʾ���м�¼
            display(&record);
            break;

        case 5://������Ϣ
            reserve(&record);
            break;

        case 6://����ѧ����Ϣ��д�����ļ���
            save(&record);
            break;
        }
    }
}


//===============���庯��================

//completed
/*
��������load_in
���ܣ������ļ� ��stu.txt��   Stu S ����Ԫ�ز������ݣ���������
���룺�洢ѧ����Ϣ��Stu�ṹ��ָ�� S
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
��������insert_sort
���ܣ�ֱ�Ӳ������򣬲�ͳ�ƱȽϴ������ƶ�����      (���ѧ������)
���룺�洢ѧ����Ϣ��Stu�ṹ��ָ�� S
 count_cmp = 0, count_move = 0 Ϊȫ�ֱ���
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
    //        count_cmp++;      //ѭ��������˳��������жϼ�Ϊһ�αȽ�
    //    }
    //    count_cmp++;          //ѭ���˳�ʱ�ֱȽ���һ��
    //    S->member[j + 1] = S->member[0];
    //}
    for (i = 1; i <= n; i++)
    {
        S->member[0] = S->member[i];
        for (j = i - 1; S->member[0].number < S->member[j].number; j--)
        {
            S->member[j+1] = S->member[j];
            count_move++;
            count_cmp++;      //ѭ��������˳��������жϼ�Ϊһ�αȽ�
        }
        count_cmp++;          //ѭ���˳�ʱ�ֱȽ���һ��
        S->member[j + 1] = S->member[0];
    }
    cout << "���ݹ�ģΪ��" << n << "����¼" << endl;
    cout << "�Ƚϴ���Ϊ:" << count_cmp << endl;
    cout << "�ƶ�����Ϊ:" << count_move << endl;
}

/*
��������quick_sort
���ܣ��������򣬲�ͳ�ƱȽϴ������ƶ�����      (���ѧ������)
���룺�洢ѧ����Ϣ��Stu�ṹ��ָ�� S
 count_cmp = 0, count_move = 0 Ϊȫ�ֱ���
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
��������display
���ܣ���ʾ����ѧ������
���룺�洢ѧ����Ϣ��Stu�ṹ��ָ�� S
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
��������reserve
���ܣ������еļ�¼˳����
���룺�洢ѧ����Ϣ��Stu�ṹ��ָ�� S
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
    cout << "ѧ����Ϣ�ѵ���" << endl;
}

/*
��������save
���ܣ�������еļ�¼��д���µ��ı��ļ�
���룺�洢ѧ����Ϣ��Stu�ṹ��ָ�� S
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
    cout << "ѧ����Ϣ�ѱ��档" << endl;
}