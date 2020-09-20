#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

//��ӭ
void Welcome()
{
	printf("*******************\n");
	printf("******1��play******\n");
	printf("******0��exit******\n");
	printf("*******************\n");
}

//��Ϸ
void PlayGame()
{
	char ret = 0;
	//�������̴�С
	char board[ROW][COL] = { 0 };
	//��ʼ������
	InitBoard(board, ROW, COL);
	//��ӡ����
	DisplayBoard(board, ROW, COL);
	do
	{
		//�����
		PlayerMove(board, ROW, COL);
		//�ж�
		ret = Consder(board, ROW, COL);
		if (ret == '0')
		{
			DisplayBoard(board,ROW,COL);
			printf("ƽ��!\n");
			system("pause");
			system("cls");
			return main();
		}
		//������
		AiMove(board, ROW, COL);
		//��ӡ����
		DisplayBoard(board, ROW, COL);
		//�ж�
		ret = Consder(board, ROW, COL);
		if (ret == '0')
		{
			DisplayBoard(board, ROW, COL);
			printf("ƽ��!\n");
			system("pause");
			system("cls");
			return main();
		}
		if (ret == '*')
		{
			printf("���Ӯ\n");
			break;
		}
		if (ret == '#')
		{
			printf("����Ӯ\n");
			break;
		}
	} while (1);
}

//��ʼ������
void InitBoard(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			arr[i][j] = ' ';
		}
	}
}

//��ӡ����
void DisplayBoard(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", arr[i][j]);
			if (j < col - 1)
				//���һ�в���ӡ"|"
				printf("|");
		}
		printf("\n");
		//���һ�в���ӡ"---"
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
		}
		printf("\n");
	}
}

//�����
void PlayerMove(char arr[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("ע:�����ÿո����!\n");
		printf("�������������:>\n");
		scanf("%d %d", &x, &y);

		if (x <= row && x >= 1 && y <= col && y >= 1)
		{
			if (arr[x - 1][y - 1] == ' ')
			{
				arr[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				//system("cls");
				printf("�������ѱ�ռ�ã�����������!\n");
				DisplayBoard(arr, ROW, COL);
			}
		}
		else
		{
			//system("cls");
			printf("�����겻�Ϸ�������������!\n");
			DisplayBoard(arr, ROW, COL);
		}
	}
}

//������
void AiMove(char arr[ROW][COL], int row, int col)
{	
	int i = 0;
	int j = 0;
	int x = 0;
	int y = 0;

	while (1)
	{
		x = rand() % row + 1;
		y = rand() % col + 1;
		if (x <= row&&x >= 1 && y <= col&&y >= 1)
		{
			if (arr[x - 1][y - 1] == ' ')
			{
				arr[x - 1][y - 1] = '#';
				break;
			}
		}
	}
}

//�ж�
char Consder(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	int flag = 0;
	char ch = '1';

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (arr[i][j] != ' ')
				flag++;
		}
	}

	//if (flag == row*col)
	//{
	//	DisplayBoard(arr, row, col);
	//	printf("ƽ��!\n");
	//	system("pause");
	//	system("cls");
	//	return main();
	//}

	//if (flag == row*col)
	//	return '0';
	//for (i = 0; i < row; i++)
	//{
	//	if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2]  &&  arr[i][0] != ' ')
	//		return arr[i][0];
	//}
	//for (j = 0; j < col; j++)
	//{
	//	if (arr[0][j] == arr[1][j] && arr[1][j] == arr[2][j]  &&  arr[0][j] != ' ')
	//		return arr[0][j];
	//}
	//if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] != ' ')
	//	return arr[0][0];
	//if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[0][2] != ' ')
	//	return arr[0][2];

	if (flag == row*col)
		ch = '0';
	for (i = 0; i < row; i++)
	{
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] != ' ')
			//		return arr[i][0];
			ch = arr[i][0];
	}
	for (j = 0; j < col; j++)
	{
		if (arr[0][j] == arr[1][j] && arr[1][j] == arr[2][j] && arr[0][j] != ' ')
			ch = arr[0][j];
	}
	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] != ' ')
		ch = arr[0][0];
	if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[0][2] != ' ')
		ch = arr[0][2];
	return ch;
}