#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
//��ʼ����ʵ��
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

////��ӡ���̺�����ʵ��(row=a,col=3ʱ)
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

//��ӡ���̺�����ʵ��(row=a,col=bʱ)
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
//������庯����ʵ��
{
	int x = 0;
	int y = 0;
	printf("�������:>\n");
	while (1)
	{
		printf("���������꣺>");
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
				printf("���걻ռ��\n");
			}
		}
		else
		{
			printf("����Ƿ�������������\n");
		}
	}
}




//�������庯��ʵ��
void Comper(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("������\n");
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

int Full(char board[ROW][COL], int row, int col)//����0û��������1����
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
//�ж���Ӯ������ʵ��
char Win(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//������
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	//������
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	//�����Խ���
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	//����0û��������1����
	if (Full(board, ROW, COL) == 1)
	{
		return 'Q';
	}
	return 'C';


}



