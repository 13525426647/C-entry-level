#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3
//��ʼ����������
void initboard(char board[ROW][COL], int row, int col);
//��ӡ���̺�������
void displayboard(char board[ROW][COL], int row, int col);
//������庯������
void Player(char board[ROW][COL], int row, int col);
//�������庯������
void Comper(char board[ROW][COL], int row, int col);
//�ж���Ӯ�ĺ�������
char Win(char board[ROW][COL], int row, int col);

