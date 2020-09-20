#include <stdio.h>
#include <conio.h>
#include <graphics.h>		//easyX 库 头文件
#include <math.h>
#include<stdlib.h>
#include<time.h>
#include <Windows.h>
#include <mmsystem.h>			//播放音乐
#pragma comment(lib,"winmm.lib")		//播放音乐

#define PI 3.1415926535897932384626
#define MaxStar 1024
#define MaxMeteor 300

//欢迎
void printscreen()
{
	for (int i = 0; i < 60; i++)
	{
		cleardevice();		//清屏
		settextcolor(RGB(254, 15, 100));
		//圆心坐标（450,305），半径为150
		int x = 400 + 150 * cos(2 * PI * i / 60);
		int y = 305 + 150 * sin(2 * PI * i / 60);
		settextstyle(i + 10, 0, "华文行楷");
		outtextxy(x, y, "╰情人节快乐つ");
		Sleep(50);		//休眠，减慢每次循环之间速度
	}
}
//播放音乐
void playmusic()
{
	//加载音乐
	mciSendString("open picture//浪漫空气.mp3", 0, 0, 0);
	//播放音乐
	mciSendString("play picture//浪漫空气.mp3 repeat", 0, 0, 0);
}
//星星
struct star
{
	int x, y;
	int speed;
	int color;
}star[MaxStar];
//流星
struct meteor
{
	int x, y;
	int speed;
	int style;
}meteor[MaxMeteor];
//头像移动
struct shmily
{
	int x;
	int speed;
}love;
//初始化星星
void InitStar(int i)
{
	star[i].x = rand() % 1200;
	star[i].y = rand() % 700;
	star[i].speed = rand() % 6;
	star[i].color = RGB(rand() % 256, rand() % 256, rand() % 256);
}
//画星星并移动
void DrawMoveStar(int i)
{
	//画像素点
	putpixel(star[i].x, star[i].y, star[i].color);
	star[i].x += star[i].speed;
	//如果移动到窗口外面
	if (star[i].x > 1200)
	{
		InitStar(i);
		putpixel(star[i].x, star[i].y, star[i].color);
	}
}
//初始化流星
void InitMeteor(int i)
{
	meteor[i].x = rand() % 2200 - 1200;     //[-1200,1199]
	meteor[i].y = -400;
	meteor[i].speed = rand() % 38;
	meteor[i].style = rand() % 2;		//流星种类
}
//画流星：显示图片
void DrawMeteor()
{
	//定义图片变量
	IMAGE img1, img2;
	//加载图片
	loadimage(&img1, "picture//3.jpg", 50, 50);
	loadimage(&img2, "picture//2.jpg", 50, 50);
	//贴图
	for (int i = 0; i < MaxMeteor; i++)
	{
		if (0 == meteor[i].style)
		{
			putimage(meteor[i].x, meteor[i].y, &img1, SRCPAINT);			//取背景图
		}
		if (1 == meteor[i].style)
		{
			putimage(meteor[i].x, meteor[i].y, &img2, SRCPAINT);
		}
	}
}
//移动流星
void MoveMeteor()
{
	for (int i = 0; i < MaxMeteor; i++)
	{
		meteor[i].x += meteor[i].speed;
		meteor[i].y += meteor[i].speed;
		//流星移到窗口外面
		if (meteor[i].x > 1200 || meteor[i].y > 700)
		{
			InitMeteor(i);
		}
	}
}
//流星雨
void show()
{
	for (int i = 1; i < 81; i++)
	{
		Sleep(62);
	}
	for (int i = 0; i < MaxMeteor; i++)
	{
		InitMeteor(i);
	}
	for (int i = 0; i < MaxStar; i++)
	{
		InitStar(i);
	}
	int i = 0;
	while (1)
	{
		if (100 == i++)
		{
			break;
		}
		BeginBatchDraw();		//防止闪屏
		cleardevice();

		for (int i = 0; i < MaxStar; i++)
		{
			DrawMoveStar(i);
		}
		DrawMeteor();
		MoveMeteor();

		Sleep(100);
		EndBatchDraw();		//防止闪屏
	}
	cleardevice();
	IMAGE img;
	loadimage(&img, "picture//白图.jpg", 1200, 700);
	putimage(0, 0, &img);
}
//初始化人物
void InitPeople()
{
	love.x = 0;
	love.speed = 4;
}
//画并移动人物
void MovePeople()
{
	IMAGE img1;
	loadimage(&img1, "picture//男.jpg", 200, 200);
	putimage(love.x, 450, &img1);
	love.x += love.speed;
}
//结尾
void endprint()
{
	IMAGE img,img2;
	loadimage(&img, "picture//白图.jpg", 1200, 700);
	loadimage(&img2, "picture//女.jpg", 200, 200);

	putimage(0, 0, &img);
	putimage(1000, 450, &img2);
	
	InitPeople();

	settextcolor(RGB(254, 15, 100));
	settextstyle(25, 0, "楷体");
	TCHAR s[] = "If there is a distance of 100 steps between us, I will be brave to take 99";
	TCHAR a[] = "steps to you, as long as you take the last step to me, I will use all my strength to";
	TCHAR b[] = "care for you";
	for (int i = 0; i < 74; i++)
	{
		BeginBatchDraw();
		MovePeople();
		outtextxy(65 + 15 * i, 330, s[i]);
		EndBatchDraw();
		Sleep(160);
	}
	for (int i = 0; i < 84; i++)
	{
		BeginBatchDraw();
		MovePeople();
		outtextxy(0 + 14 * i, 370, a[i]);
		EndBatchDraw();
		Sleep(160);
	}
	for (int i = 0; i < 13; i++)
	{
		BeginBatchDraw();
		MovePeople();
		outtextxy(0 + 14 * i, 410, b[i]);
		EndBatchDraw();
		Sleep(160);
	}
	Sleep(1500);

	settextcolor(RGB(254, 15, 100));
	settextstyle(33, 0, "华文行楷");
	outtextxy(885, 480, "你");
	Sleep(400);
	outtextxy(925, 480, "愿");
	Sleep(400);
	outtextxy(965, 480, "意");
	Sleep(400);
	outtextxy(905, 520, "向");
	Sleep(400);
	outtextxy(945, 520, "我");
	Sleep(400);
	outtextxy(885, 560, "走");
	Sleep(400);
	outtextxy(925, 560, "最");
	Sleep(400);
	outtextxy(965, 560, "后");
	Sleep(400);
	outtextxy(885, 600, "一");
	Sleep(400);
	outtextxy(925, 600, "步");
	Sleep(400);
	outtextxy(965, 600, "吗");
}
//主函数
void main()
{
	srand((unsigned int)time(NULL));
	//创建一个图形窗口
	initgraph(1200, 700);
	//获取窗口句柄
	HWND hwnd = GetHWnd();
	//移动窗口
	MoveWindow(hwnd, 160, 65,1200,700,TRUE);
	//设置字体背景模式
	setbkmode(0);
	//播放音乐
	playmusic();	
	//欢迎
	printscreen();		
	//流星雨
	show();
	//结尾
	endprint();

	Sleep(1500);		
	int ret = MessageBox(hwnd, "愿意走这一步吗？", "询问", MB_YESNO);		//弹窗消息
	if (ret == IDYES)
	{
		//IMAGE img_left, img_right;
		//loadimage(&img_left, "picture//左手.jpg", 100, 100);
		//loadimage(&img_right, "picture//右手.jpg", 100, 100);
		
		int ret2 = MessageBox(hwnd, "需要去感谢我们的红娘吗？", "兴奋", MB_YESNO);
		if (ret2 == IDYES)
		{
			int ret3 = MessageBox(hwnd, "haha,红娘就是我，勇哥，快来感谢我", "Emmm",MB_OK);
		}
		else
		{
			int ret4 = MessageBox(hwnd, "我这么辛苦你不来感谢是不是不太好?", "Emmm", MB_OK);
		}
	}
	else
	{
		int ret5 = MessageBox(hwnd, "那我就再继续努力走出最后一步\n\n我一定要追到你!", "加油", MB_OK);
	}

	closegraph();  //关闭图形窗口
}