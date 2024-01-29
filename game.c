#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;	
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;	
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)//打印一行的数据
		{
			printf(" %c ",board[i][j]);
			if (j < (col - 1))
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < (row - 1))
		{
			for (j = 0; j < col; j++)//打印分割行
			{
				printf("---");
				if (j < (col - 1))
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("请输入棋子坐标>:");
	while (1)
	{		
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= ROW && y >= 1 && y <= COL)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该坐标已有棋子，请重新输入>:");
			}			
		}
		else
		{
			printf("输入错误，棋子横纵坐标的范围分别应为1到%d和1到%d,请重新输入>:", ROW, COL);
		}
	}
}
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑落子:>\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}	
}
char IsWin(char board[ROW][COL], int row, int col)//告诉我们四种游戏的状态：
{                                                 //玩家赢，电脑赢，平局，继续游戏
	int i = 0;
	for (i = 0; i < row; i++)//横三行
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	for (i = 0; i < col; i++)//竖三列
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];//两个对角线
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];//两个对角线
	}
	if (1 == IsFull(board, ROW, COL))//判断是否平局
	{
		return 'Q';
	}
	return 'C';
}
int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < row; j++)
		{
			if (board[i][j] == ' ')
				return 0;//棋盘满了
		}
	}
	return 1;//棋盘没满
}
