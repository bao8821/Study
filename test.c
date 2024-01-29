#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void game()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };//全部空格
	InitBoard(board, ROW, COL);//初始化棋盘
	DisplayBoard(board, ROW, COL);//打印棋盘
	while (1)//下棋
	{
		PlayerMove(board, ROW, COL);//玩家下棋
		DisplayBoard(board, ROW, COL);//打印棋盘
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')//判断是否继续游戏
		{
			break;
		}
		ComputerMove(board, ROW, COL);//电脑下棋
		DisplayBoard(board, ROW, COL);//打印棋盘
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')//判断是否继续游戏
		{
			break;
		}		
	}
	if (ret == '*')
	{
		printf("玩家赢。\n");
	}
	else if(ret == '#')
	{
		printf("电脑赢。\n");
	}
	else
	{
		printf("平局。\n");
	}
}
void menu()
{
	printf("***********三子棋***********\n");
	printf("****** 1.play  0.exit ******\n");
	printf("****************************\n");
}
void test()//测试三子棋游戏
{
	int input = 0;
	srand((unsigned)time(NULL));
	do
	{ 
		menu();
		printf("请选择->");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("请输入1或0\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}
