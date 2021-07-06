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
		printf("\n请选择操作\n");
		printf("1. 键盘输入构建三元组表\n");
		printf("2. 二维数组构建三元组表\n");
		printf("3. 三元组表取值\n");
		printf("4. 三元组表赋值\n");
		printf("5. 三元组表转置\n");
		printf("6. 输出三元组表\n");
		printf("0. 退出\n\n");
		printf("\n请选择:");
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
			printf("\n请输入要取值的行号和列号：");
			scanf("%d %d", &r, &c);
			if (!assign(&mTable, &x, r, c))
				printf("取值失败");
			else
				printf("%d行%d列的值是%d", r, c, x);
			break;
		case 4:
			printf("\n请输入要赋值的行号、列号 和值：");
			scanf("%d %d %d", &r, &c, &x);
			if (!value(&mTable, x, r, c))
				printf("赋值失败");
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