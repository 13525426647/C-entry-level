#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3
//初始化函数声明
void initboard(char board[ROW][COL], int row, int col);
//打印棋盘函数声明
void displayboard(char board[ROW][COL], int row, int col);
//玩家下棋函数声明
void Player(char board[ROW][COL], int row, int col);
//电脑下棋函数声明
void Comper(char board[ROW][COL], int row, int col);
//判断输赢的函数声明
char Win(char board[ROW][COL], int row, int col);

