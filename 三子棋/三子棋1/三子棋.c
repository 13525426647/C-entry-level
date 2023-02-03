#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
#include <stdio.h>

void menu()
{
	printf("********************\n");
	printf("***1.play  0.exit***\n");
	printf("********************\n");
}
void game()
{
	int ret = 0;
	//定义一个数组，存放棋盘信息
	char board[ROW][COL] = { 0 };
	//初始化数组
	initboard(board, ROW, COL);
	//打印棋盘
	displayboard(board, ROW, COL);
	//下棋
	while (1)
	{
		//玩家下棋
		Player(board, ROW, COL);
		displayboard(board, ROW, COL);
		//判断输赢的函数
		char ret = Win(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//电脑下棋
		Comper(board, ROW, COL);
		displayboard(board, ROW, COL);
		//判断电脑输赢
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret = '*')
	{
		printf("你赢了\n");
	}
	else if (ret = '#')
	{
		printf("电脑赢了\n");
	}
	else
	{
		printf("平局\n");
	}
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏");
			break;
		default:
			printf("选择错误，请重新选择");
			break;
		}
	} while (input);

}

int main()
{
	test();
	return 0;

}