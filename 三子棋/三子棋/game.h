#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 3
#define COL 3

//��ӭ
void Welcome();
//��Ϸ
void PlayGame();
//��ʼ������
void InitBoard(char arr[ROW][COL],int row,int col);
//��ӡ����
void DisplayBoard(char arr[ROW][COL], int row, int col);
//�����
void PlayerMove(char arr[ROW][COL], int row, int col);
//������
void AiMove(char arr[ROW][COL], int row, int col);
//�ж�
char Consder(char arr[ROW][COL], int row, int col);