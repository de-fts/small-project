#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

//欢迎
void Welcome()
{
	printf("*******************\n");
	printf("******1、play******\n");
	printf("******0、exit******\n");
	printf("*******************\n");
}

//游戏
void PlayGame()
{
	char ret = 0;
	//定义棋盘大小
	char board[ROW][COL] = { 0 };
	//初始化棋盘
	InitBoard(board, ROW, COL);
	//打印棋盘
	DisplayBoard(board, ROW, COL);
	do
	{
		//玩家走
		PlayerMove(board, ROW, COL);
		//判断
		ret = Consder(board, ROW, COL);
		if (ret == '0')
		{
			DisplayBoard(board,ROW,COL);
			printf("平局!\n");
			system("pause");
			system("cls");
			return main();
		}
		//电脑走
		AiMove(board, ROW, COL);
		//打印棋盘
		DisplayBoard(board, ROW, COL);
		//判断
		ret = Consder(board, ROW, COL);
		if (ret == '0')
		{
			DisplayBoard(board, ROW, COL);
			printf("平局!\n");
			system("pause");
			system("cls");
			return main();
		}
		if (ret == '*')
		{
			printf("玩家赢\n");
			break;
		}
		if (ret == '#')
		{
			printf("电脑赢\n");
			break;
		}
	} while (1);
}

//初始化棋盘
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

//打印棋盘
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
				//最后一列不打印"|"
				printf("|");
		}
		printf("\n");
		//最后一行不打印"---"
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

//玩家走
void PlayerMove(char arr[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("注:坐标用空格隔开!\n");
		printf("玩家请输入坐标:>\n");
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
				printf("该坐标已被占用，请重新输入!\n");
				DisplayBoard(arr, ROW, COL);
			}
		}
		else
		{
			//system("cls");
			printf("该坐标不合法，请重新输入!\n");
			DisplayBoard(arr, ROW, COL);
		}
	}
}

//电脑走
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

//判断
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
	//	printf("平局!\n");
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