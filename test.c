#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void game() 
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };//提示雷数量的数组为什么不是9*9而是11*11呢？因为这样方便两个数组做对应
	InitBoard(mine, ROWS, COLS,'0');//初始化棋盘
	InitBoard(show, ROWS, COLS,'*');
	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);//打印棋盘
	SetMine(mine, ROW, COL);//埋雷
	//DisplayBoard(mine, ROW, COL);
	FindMine(mine, show, ROW, COL);//扫雷
}

void menu()
{
	printf("************扫雷************\n");
	printf("****** 1.play  0.exit ******\n");
	printf("****************************\n");
}
void test()
{
	int input = 0; 
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		srand((unsigned int)time(NULL));
		switch (input)
		{
		case 1:
			game();
			break;
		case 2:
			printf("退出游戏。");
			break;
		default:
			printf("输入错误，请输入0或1。");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}
