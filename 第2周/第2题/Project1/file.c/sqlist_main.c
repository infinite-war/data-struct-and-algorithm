#include "../Project1/information.h"
#include "../Project1/operate.h"
#include<string.h>
int main() {
	SqList L = {NULL,0};
	int i = 0, temp, a, c, choose;
	int price;
	Book e;
	FILE *f;
	char buf[256];
	char *p;
	int  n;
	
	printf( "1. ����\n");
	printf( "2. ����\n");
	printf( "3. ȡֵ\n");
	printf( "4. ����\n");
	printf( "5. ����\n");
	printf( "6. ɾ��\n");
	printf( "7. ���\n");
	printf( "0. �˳�\n\n");

	choose = -1;
	while (choose != 0) {
		printf("��ѡ��:");
		scanf("%d", &choose);
		switch (choose) {
		case 1://����˳���
			if (InitList_Sq(&L))
				printf("�ɹ�����˳���\n\n");
			else
				printf( "˳�����ʧ��\n\n");
			break;
		case 2: {//˳�����Ϣ����
			i = 0;
			//L.elem = new Book[MAXSIZE];
			if (NULL==L.elem)
			{
				printf("��δ��ʼ����");
				
				break;
			}
			L.length = 0;
			if (NULL == (f = fopen("C:/Users/96955/Desktop/��2��/resourse/book.txt", "r")))
			{
				printf( "Can not open file : 1.txt");
				getchar();
				return 0;
			}
			i = n = 0;
			while (1)
			{
				//if (n == SIZE_view) break;
				if (NULL == fgets(buf,256, f)) break;
				if ('\n' == buf[0]) continue;     //���м���
				p = buf;
				//printf("%s\n", buf);

				sscanf(p, "%s%s%d",&L.elem[n].id,&L.elem[n].name, &L.elem[n].price);
				
				n++;
			}

			do
			{
				printf("%s %s %d\n", L.elem[i].id, L.elem[i].name, L.elem[i].price);
				i++;
			} while (i < n);
			fclose(f);
			L.length =n;
			
		}
			break;
		case 3://˳����ȡֵ
			printf("������һ��λ������ȡֵ��\n");
			scanf("%d",&i);
			temp = GetElem(L, i, &e);
			if (temp != 0) {
				printf("���ҳɹ�\n");
				printf("��%d��ͼ�����Ϣ�ǣ�\n",i);
				printf("%s %s %d\n", &e.id, &e.name, e.price);
			} else
				printf("����ʧ�ܣ�λ�ó�����Χ\n\n");
			break;
		case 4: //˳���Ĳ���
			printf("��������Ҫ���Ҽ۸�:");
			scanf("%d",&price);
			temp = LocateElem_Sq(L, price);
			if (temp != 0) {
				printf("���ҳɹ�\n");
				printf("�ü۸��Ӧ������Ϊ��%s\n\n", L.elem[temp - 1].name);
			} else
				printf( "����ʧ�ܣ�û������۸��Ӧ���鼮\n\n");
			break;
		case 5: //˳���Ĳ���
			printf("����������λ��:\n\n");
			scanf("%d",&a);
			printf("�������鱾���:\n\n");
			scanf("%s",&e.id);
			printf("����������:\n\n");
			scanf("%s",&e.name);
			printf("������۸�:\n\n");
			scanf("%d",&e.price);
			
			if (ListInsert_Sq(&L, a, e))
				printf("����ɹ�.\n\n");
			else
				printf("����ʧ��.\n\n");
			break;
		case 6: //˳����ɾ��
			printf( "��������Ҫɾ�����鼮��λ��:");
			scanf("%d",&c);
			if (ListDelete_Sq(&L, c))
				printf("ɾ���ɹ�.\n\n");
			else
				printf("ɾ��ʧ��.\n\n");
			break;
		case 7: //˳�������
			printf("��ǰͼ��ϵͳ��Ϣ��˳�������:\n");
			for (i = 0; i < L.length; i++)
				printf("%s %s %d\n", &L.elem[i].id, &L.elem[i].name, L.elem[i].price);
			break;
		}
	}
	getchar();
	return 0;
}