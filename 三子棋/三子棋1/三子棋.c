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
	//����һ�����飬���������Ϣ
	char board[ROW][COL] = { 0 };
	//��ʼ������
	initboard(board, ROW, COL);
	//��ӡ����
	displayboard(board, ROW, COL);
	//����
	while (1)
	{
		//�������
		Player(board, ROW, COL);
		displayboard(board, ROW, COL);
		//�ж���Ӯ�ĺ���
		char ret = Win(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//��������
		Comper(board, ROW, COL);
		displayboard(board, ROW, COL);
		//�жϵ�����Ӯ
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret = '*')
	{
		printf("��Ӯ��\n");
	}
	else if (ret = '#')
	{
		printf("����Ӯ��\n");
	}
	else
	{
		printf("ƽ��\n");
	}
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ");
			break;
		default:
			printf("ѡ�����������ѡ��");
			break;
		}
	} while (input);

}

int main()
{
	test();
	return 0;

}