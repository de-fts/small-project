#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 3
#define COL 3

//欢迎
void Welcome();
//游戏
void PlayGame();
//初始化棋盘
void InitBoard(char arr[ROW][COL],int row,int col);
//打印棋盘
void DisplayBoard(char arr[ROW][COL], int row, int col);
//玩家走
void PlayerMove(char arr[ROW][COL], int row, int col);
//电脑走
void AiMove(char arr[ROW][COL], int row, int col);
//判断
char Consder(char arr[ROW][COL], int row, int col);