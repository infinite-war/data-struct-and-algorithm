#include "globaldef.h"
#include "matrixop.h"
int main()
{
	table mTable,TTable;
	int x, r, c;
	int mchoice;
	
	mchoice = -1;
	while (mchoice != 0)
	{
		printf("\n��ѡ�����\n");
		printf("1. �������빹����Ԫ���\n");
		printf("2. ��ά���鹹����Ԫ���\n");
		printf("3. ��Ԫ���ȡֵ\n");
		printf("4. ��Ԫ���ֵ\n");
		printf("5. ��Ԫ���ת��\n");
		printf("6. �����Ԫ���\n");
		printf("0. �˳�\n\n");
		printf("\n��ѡ��:");
		scanf("%d", &mchoice);
		switch (mchoice)
		{
		case 1:
			mTable = InitTable1();
			OutputTable(mTable);
			break;
		case 2:
			mTable = InitTable2();
			OutputTable(mTable);
			break;
		case 3:
			printf("\n������Ҫȡֵ���кź��кţ�");
			scanf("%d %d", &r, &c);
			if (!assign(&mTable, &x, r, c))
				printf("ȡֵʧ��");
			else
				printf("%d��%d�е�ֵ��%d", r, c, x);
			break;
		case 4:
			printf("\n������Ҫ��ֵ���кš��к� ��ֵ��");
			scanf("%d %d %d", &r, &c, &x);
			if (!value(&mTable, x, r, c))
				printf("��ֵʧ��");
			else
				OutputTable(mTable);
			break;
		case 5:
			fast_trans_matrix(&mTable, &TTable);
			OutputTable(TTable);
			break;

		case 6:
			OutputTable(mTable);
			break;
		}
	}
	return 0;
}