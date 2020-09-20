/*
*文件名：三子棋
*作者：
*完成日期：2020年9月18日
*/
#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	/*char arr[ROW][COL] = { 0 };*/

	do
	{
		Welcome();
		printf("请选择编号:>\n");
		input = getch();
		
		switch (input)
		{
		case '1':PlayGame();
			break;
		case '0':printf("退出游戏\n");
			break;
		default:printf("输入错误\n");
			break;
		}
	} while (input);

	return 0;
}