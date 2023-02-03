#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
//初始化的实现
void initboard(char board[ROW][COL], int row, int col)
{
	int a = 0;
	int b = 0;
	for (a = 0; a < row; a++)
	{
		for (b = 0; b < col; b++)
		{
			board[a][b] = ' ';
		}
	}
}

////打印棋盘函数的实现(row=a,col=3时)
//void displayboard(char board[ROW][COL], int row, int col)
//{
//	int a = 0;
//	for (a = 0; a < row; a++)
//	{
//		printf(" %c | %c | %c \n", board[a][0], board[a][1], board[a][2]);
//		if(a<row-1)
//		{
//			printf("---|---|---\n");
//		}
//	}
//}

//打印棋盘函数的实现(row=a,col=b时)
void displayboard(char board[ROW][COL], int row, int col)
{
	int a = 0;
	for (a = 0; a < row; a++)
	{
		int b = 0;
		for (b = 0; b < col; b++)
		{
			printf(" %c ", board[a][b]);
			if (b < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (a < row - 1)
		{
			for (b = 0; b < col; b++)
			{
				printf("---");
				if (b < col - 1)
				{
					printf("|");

				}
			}
		}
		printf("\n");
	}
}


void Player(char board[ROW][COL], int row, int col)
//玩家下棋函数的实现
{
	int x = 0;
	int y = 0;
	printf("玩家下棋:>\n");
	while (1)
	{
		printf("请输入坐标：>");
		scanf("%d%d", &x, &y);
		if (x > 0 && x <= row && y > 0 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("坐标被占用\n");
			}
		}
		else
		{
			printf("坐标非法，请重新输入\n");
		}
	}
}




//电脑下棋函数实现
void Comper(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑走\n");
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

int Full(char board[ROW][COL], int row, int col)//返回0没满，返回1满了
{
	int x = 0;
	int y = 0;
	for (x = 0;x < row;x++)
	{
		for (y = 0; y < col; y++)
		{
			if (board[x][y == ' '])
				return 0;
		}
	}
	return 1;
}
//判断输赢函数的实现
char Win(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//横三列
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	//竖三列
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	//两个对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	//返回0没满，返回1满了
	if (Full(board, ROW, COL) == 1)
	{
		return 'Q';
	}
	return 'C';


}



