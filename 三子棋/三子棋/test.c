/*
*�ļ�����������
*���ߣ�
*������ڣ�2020��9��18��
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
		printf("��ѡ����:>\n");
		input = getch();
		
		switch (input)
		{
		case '1':PlayGame();
			break;
		case '0':printf("�˳���Ϸ\n");
			break;
		default:printf("�������\n");
			break;
		}
	} while (input);

	return 0;
}