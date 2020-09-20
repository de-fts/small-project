#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


//球员类结构体
typedef struct athlete
{
	char name[20];	          //姓名
	char nation[20];	      //国籍
	int age;	              //年龄
	int stature;	          //身高
	int score;	              //场均得分
	int assist;               //场均助攻
}ATH;


//定义结点
typedef struct _Node
{
	ATH ath;	           //数据域
	struct _Node* next;	   //指针域
}Node;


Node* HeadNode = NULL;       //定义头结点，0
FILE *fp;                    //文件指针
char ch;				     //键盘交互
char reg_name[15];	         //账号
char reg_lock[10];	         //密码


//欢迎界面
void Welcome();
//登录注册菜单
void Menu_1();
//注册信息
void Regist();
//登录信息
void Enter();
//录入信息
void Type_In();
//查询信息
void Search();			//调用三种查询函数
//插入信息
void Insert();
//修改信息
void Modify();
//读取信息
void Read();
//删除信息
void Delete();
//存储信息
void Save();
//遍历链表
void PrintNode();
//数据排序
void Select();
//统计数据
void Statistics();
//退出系统
void Close();
//按姓名查询
void SearchName();		
//按国籍查询
void SearchNation();
//组合查询
void SearchName_Nation();
//升序排序
void SelectUp();
//降序排序
void SelectDown();


//主函数
void main()
{
	Welcome();		//欢迎
	Menu_1();	//登录注册菜单

	while (1)
	{
		printf("\n\n\n\n\n\n\t\t\t\t\t           * 系统功能菜单 *\n");
		printf("\n\t\t\t           -----------------------------------------------\n");
		printf("\t\t\t           *  1、录入NBA球星信息  *  2、查询NBA球星信息  *\n");
		printf("\t\t\t           -----------------------------------------------\n");
		printf("\t\t\t           *  3、插入NBA球星信息  *  4、修改NBA球星信息  *\n");
		printf("\t\t\t           -----------------------------------------------\n");
		printf("\t\t\t           *  5、读取NBA球星信息  *  6、存储NBA球星信息  *\n");
		printf("\t\t\t           -----------------------------------------------\n");
		printf("\t\t\t           *  7、删除NBA球星信息  *  8、报表NBA球星信息  *\n");
		printf("\t\t\t           -----------------------------------------------\n");
		printf("\t\t\t           *  9、数据排序         *  0、数据统计         *\n");
		printf("\t\t\t           -----------------------------------------------\n");
		printf("\t\t\t           *  n、退出系统         *                       \n");
		printf("\t\t\t           ------------------------\n");

		printf("\n  *  请选择菜单编号: ");
		ch = getch();

		switch (ch)
		{
		case '1': Type_In(); break;
		case '2': Search(); break;
		case '3': Insert(); break;
		case '4': Modify(); break;
		case '5': Read(); break;
		case '6': Save(); break;
		case '7': Delete(); break;
		case '8': PrintNode(); break;
		case '9': Select(); break;
		case '0': Statistics(); break;
		case 'n':Close(); break;
		default:{
					printf("\n  *  输入有误，请重新输入.");
					break;
		}; break;
		}

		printf("\n  *  请按任意键继续.");
		getch();

		system("cls");
	}
}


//欢迎界面
void Welcome()
{
	printf("\n\n\n\n\n\n\n\n\n\n\t\t\t           * 欢 迎 使 用 N B A 球 星 管 理 系 统 *\t\n");
	printf("\n\n\t\t\t\t\t\t\t\t* 制作人:通工1910赵勇\n\n\n\n");
	printf("  *  请按任意键进入登录注册页面:");
	getch();
}


//登录注册菜单
void Menu_1()
{
	system("cls");

	printf("\n\n               ------------------\n");
	printf("                *  1、注册账号  *\n");
	printf("               ------------------\n");
	printf("                *  2、登录账号  *\n");
	printf("               ------------------\n");
	printf("                *  3、退出系统  *\n");
	printf("               ------------------\n");

loop:																				//loop
	printf("\n  *  请选择菜单编号: ");
	ch = getch();

	switch (ch)
	{
	case '1':Regist(); break;
	case '2':Enter(); break;
	case '3':Close(); break;
	default:{
				printf("\n  *  输入有误，请重新输入.");
				goto loop;
	}; break;
	}
}


//注册部分
void Regist()
{
	system("cls");

loop_1:																			//loop_1												  
	printf("\n  *  请输入用户名[不能大于10个字符]: ");
	scanf("%s", reg_name);

	if (strlen(reg_name) <= 10)		   //检测用户名长度
	{
		fp = fopen(reg_name, "r");

		if (fp != NULL)	              //如果返回值不为空指针，即能打开这个名字的文件夹，说明已经存在该名字的文件夹
		{
			printf("\n  *  该账号已经注册.\n");
			printf("\n  *  请按任意键继续.");
			getch();

			system("cls");

			printf("\n\n               ------------------\n");
			printf("                *  1、返回菜单  *\n");
			printf("               ------------------\n");
			printf("                *  2、登录账号  *\n");
			printf("               ------------------\n");

			printf("\n  *  请选择菜单编号: ");
			ch = getch();

			switch (ch)
			{
			case '1':Menu_1(); break;
			case '2':Enter(); break;
			default:{
						printf("\n  *  输入有误.");
						printf("\n  *  请按任意键继续.");
						getch();

						Menu_1();	  //如果输入不合法，直接返回Menu_1;
			}; break;
			}
			fclose(fp);		       //关闭文件夹
		}
		else	                  //返回值为空，说明没有注册
		{
		loop_2:												//loop_2	

			system("cls");

			printf("\n  *  请输入密码[密码长度为八位] : ");
			scanf("%s", reg_lock);

			if (strlen(reg_lock) == 8)	   //检测密码长度
			{
				system("cls");

				printf("\n  *  注册成功  *\n");
				printf("\n  *  您的账号是 %s  密码是 %s\n", reg_name, reg_lock);
				printf("  *  请妥善保存\n\n");

				fp = fopen(reg_name, "w");	     //以reg_name创建一个文件夹，即用户名
				fprintf(fp, "%s", reg_lock);	 //将密码进行存储
				fclose(fp);	             //关闭文件夹

				printf("\n  *  请按任意键继续.");
				getch();

				system("cls");

				printf("\n\n               ------------------\n");
				printf("                *  1、返回菜单  *\n");
				printf("               ------------------\n");
				printf("                *  2、登录账号  *\n");
				printf("               ------------------\n");

				printf("\n  *  请选择菜单编号: ");
				ch = getch();

				switch (ch)
				{
				case '1':Menu_1(); break;
				case '2':Enter(); break;
				default:{
							printf("\n  *  输入有误.");
							printf("\n  *  请按任意键继续.");
							getch();

							Menu_1();
				}; break;
				}
			}
			else	                 //密码不为八位数，返回loop_2重新输入
			{
				printf("\n  *  您的密码设置不规范,请按任意键重新设置.");
				getch();

				system("cls");

				goto loop_2;														  //loop_2
			}
		}
	}
	else	//用户名长度大于10个字符，返回loop_1重新输入
	{
		printf("\n  *  您的账号设置不规范，请按任意键重新设置.");
		getch();

		system("cls");

		goto loop_1;													          	//loop_1
	}
}


//登录部分
void Enter()
{
	system("cls");

	char t_lock[10];         //临时存储密码

	printf("\n  *  请输入用户名: ");
	scanf("%s", reg_name);

	if (strlen(reg_name) <= 10)	      //检测用户名是否合法
	{
		fp = fopen(reg_name, "r");

		if (fp == NULL)	       //若返回空指针,说明文件夹中没有这个账号
		{

			printf("\n  *  该用户名还没有注册!请前往注册.\n");
			printf("\n  *  请按任意键继续.");
			getch();

			system("cls");

			Menu_1();
			fclose(fp);
		}
		else	      //若返回值不为空，继续输人密码
		{
			printf("\n  *  请输入密码: ");

			for (int i = 0; i<8; i++)
				reg_lock[i] = getch();     //密码不回显

			fp = fopen(reg_name, "r");
			fscanf(fp, "%s", t_lock);		//将密码从文件中取出暂存到t_lock中
			fclose(fp);	       //关闭文件

			if (strcmp(reg_lock, t_lock) == 0)	     //将输入的密码与文件中取出的密码比对
			{                                        //若结果为零，说明两者相同，即密码正确
				printf("\n  *  登录成功!\n");
				printf("\n  *  请按任意键继续.");
				getch();

				system("cls");
			}
			else
			{
				printf("\n  *  账号或密码输入错误.\n");   //不为零，即密码不等
				printf("\n  *  请按任意键继续.");
				getch();

				system("cls");

				printf("\n\n               ------------------\n");
				printf("                *  1、重新登录  *\n");
				printf("               ------------------\n");
				printf("                *  2、返回菜单  *\n");
				printf("               ------------------\n");

				printf("\n  *  请选择菜单编号: ");
				ch = getch();

				switch (ch)
				{
				case '1':Enter(); break;
				case '2':Menu_1(); break;
				default:{
							printf("\n  *  输入有误.");
							printf("\n  *  请按任意键继续.");
							getch();

							Menu_1();
				}; break;
				}
			}
		}
	}
	else
	{
		printf("\n  *  用户名不合法.");
		printf("\n  *  请按任意键继续.");
		getch();

		Menu_1();
	}
}


//录入信息
void Type_In()
{
	system("cls");

	Node* pNew = (Node*)malloc(sizeof(Node));//定义一个结点，当前结点
	pNew->next = NULL;

	printf("\n  *  请输入录入球星的名字: ");
	scanf("%s", pNew->ath.name);
	printf("\n  *  请输入 %s 的国籍: ", pNew->ath.name);
	scanf("%s", pNew->ath.nation);
	printf("\n  *  请输入 %s 的年龄: ", pNew->ath.name);
	scanf("%d", &pNew->ath.age);
	printf("\n  *  请输入 %s 的身高: ", pNew->ath.name);
	scanf("%d", &pNew->ath.stature);
	printf("\n  *  请输入 %s 的场均得分: ", pNew->ath.name);
	scanf("%d", &pNew->ath.score);
	printf("\n  *  请输入 %s 的场均助攻: ", pNew->ath.name);
	scanf("%d", &pNew->ath.assist);

	if (HeadNode == NULL)		
	{
		HeadNode = pNew;			//如果头结点为NULL，pNew就当头结点
	}

	else
	{
		pNew->next = HeadNode;		//如果有头结点，那么将新结点pNew插在头结点前面
		HeadNode = pNew;			//即结点总是插在头结点前面，
	}

	printf("\n  *  信息录入成功.");
}


//查询信息
void Search()
{
	system("cls");

	printf("\n  *  请问你要按何种方式查询.");
	printf("\n  *  1、按姓名查询.");
	printf("\n  *  2、按国籍查询.");
	printf("\n  *  3、组合查询.");
	printf("\n  *  请选择编号: ");
	ch = getch();

	switch (ch)
	{
	case '1':SearchName(); break;
	case '2':SearchNation(); break;
	case '3':SearchName_Nation(); break;
	default:{
				printf("\n\n  *  输入有误.");
				break;
	}; break;
	}
}


//插入信息
void Insert()
{
	system("cls");

	char Name1[20];
	Node* pNew = NULL;
	Node* p = HeadNode;		//开辟当前结点，用来存储信息

	printf("\n  *  请问你想在哪个球星之后插入新的球员信息?\n");
	printf("\n  *  请输入前者姓名: ");
	scanf("%s", Name1);

	printf("\n  *  定位成功.");
	printf("\n  *  按任意键开始录入.");
	getch();

	system("cls");

	while (p != NULL)
	{
		if (strcmp(p->ath.name, Name1) == 0)		//输入数据的顺序和信息存储的顺序是相反的，所以在a和b中插入数据，应该寻找b的地址
		{
			pNew = (Node*)malloc(sizeof(Node));		//开辟内存，用来存放插入的信息
			pNew->next = NULL;

			printf("\n  *  请输入录入球星的名字: ");
			scanf("%s", pNew->ath.name);
			printf("\n  *  请输入 %s 的国籍: ", pNew->ath.name);
			scanf("%s", pNew->ath.nation);
			printf("\n  *  请输入 %s 的年龄: ", pNew->ath.name);
			scanf("%d", &pNew->ath.age);
			printf("\n  *  请输入 %s 的身高: ", pNew->ath.name);
			scanf("%d", &pNew->ath.stature);
			printf("\n  *  请输入 %s 的场均得分: ", pNew->ath.name);
			scanf("%d", &pNew->ath.score);
			printf("\n  *  请输入 %s 的场均助攻: ", pNew->ath.name);
			scanf("%d", &pNew->ath.assist);

			pNew->next = p->next;	 //当信息匹配时，使新结点的next指向p，而p的下一个结点指向新结点
			p->next = pNew;

			break;
		}

		p = p->next;			//往后移动
	}

	printf("\n  *  插入成功.");
}


//修改信息
void Modify()
{
	system("cls");

	char tName[20];
	Node* pTemp = HeadNode;

	printf("\n  *  输入要修改信息的姓名:");
	scanf("%s", tName);

	system("cls");

	while (pTemp != NULL)
	{
		if (strcmp(pTemp->ath.name, tName) == 0)			//直接用新数据覆盖
		{
			printf("\n  *  请输入 %s 修改后的国籍: ", pTemp->ath.name);
			scanf("%s", pTemp->ath.nation);
			printf("\n  *  请输入 %s 修改后的年龄: ", pTemp->ath.name);
			scanf("%d", &pTemp->ath.age);
			printf("\n  *  请输入 %s 修改后的身高: ", pTemp->ath.name);
			scanf("%d", &pTemp->ath.stature);
			printf("\n  *  请输入 %s 修改后的场均得分: ", pTemp->ath.name);
			scanf("%d", &pTemp->ath.score);
			printf("\n  *  请输入 %s 修改后的场均助攻: ", pTemp->ath.name);
			scanf("%d", &pTemp->ath.assist);
		}

		pTemp = pTemp->next;		//结点向后移动
	}

	printf("\n\n  *  修改成功.");
}


//读取信息
void Read()
{
	system("cls");

	fp = fopen("athlete.txt", "r");	//只读

	if (fp == NULL)
	{
		printf("\n  *  文件打开失败.");
		exit(1);//不正常退出
	}

	Node* p = NULL;//声明一个结点，

	while (!feof(fp))       //读完返回1，没读完返回0
	{
		p = (Node*)malloc(sizeof(Node));		//开辟内存，存数据

		fscanf(fp, "%s %s %d %d %d %d",
			p->ath.name,
			p->ath.nation,
			&p->ath.age,
			&p->ath.stature,
			&p->ath.score,
			&p->ath.assist
			);

		p->next = NULL;//结点就往后移动，

		if (HeadNode == NULL)			//同录入解释
		{
			HeadNode = p;
		}

		else
		{
			p->next = HeadNode;
			HeadNode = p;
		}
	}

	fclose(fp);

	printf("\n  *  读取成功");
}


//删除信息
void Delete()
{
	system("cls");

	Node* fast = HeadNode->next;
	Node* slow = HeadNode;
	Node* temp = NULL;
	char tName[20];

	printf("\n  *  输入要删除的姓名:");
	scanf("%s", tName);

	if (strcmp(HeadNode->ath.name, tName) == 0)		//如果要删除的信息就存在头结点
	{
		temp = HeadNode->next;
		free(HeadNode);
		HeadNode = temp;

		printf("\  *  信息删除成功.");
	}

	else          //要删除的信息不在头结点
	{
		while (fast != NULL)
		{
			if (strcmp(fast->ath.name, tName) == 0)
			{
				slow->next = fast->next;
				free(fast);
				fast = slow->next;

				break;
			}

			fast = fast->next;
			slow = slow->next;
		}

		printf("\n  *  信息删除成功.");
	}
}


//存储信息
void Save()
{
	system("cls");

	fp = fopen("athlete.txt", "w");

	if (fp == NULL)
	{
		printf("\n  *  文件打开失败.");
		exit(0);
	}

	Node* p = HeadNode;			//当前结点

	while (p != NULL)
	{
		fprintf(fp, "%s %s %d %d %d %d",
			p->ath.name,
			p->ath.nation,
			p->ath.age,
			p->ath.stature,
			p->ath.score,
			p->ath.assist
			);

		p = p->next;
	}

	fclose(fp);

	printf("\n  *  数据存储成功.\n");
}


//遍历链表
void PrintNode()
{
	system("cls");

	Node* p = HeadNode;

	printf("\n  *  姓 名     国 籍\t年 龄\t身 高\t场 均 得 分\t场 均 助 攻\n");

	while (p != NULL)
	{
		printf("  *  %-10s%-10s%-8d%-11d%-16d%d\n",
			p->ath.name,
			p->ath.nation,
			p->ath.age,
			p->ath.stature,
			p->ath.score,
			p->ath.assist
			);

		p = p->next;
	}
}


//数据排序
void Select()
{
	system("cls");

	printf("\n  *  1、按身高升序排列.");
	printf("\n  *  2、按身高降序排列.");
	printf("\n  *  3、返回菜单.");
	printf("\n  *  请选择编号:");
	ch = getch();

	switch (ch)
	{
	case '1':SelectUp(); break;
	case '2':SelectDown(); break;
	case '3':return;
	default:{
				printf("\n  *  输入有误.");
				break;
	}; break;
	}
}


//统计数据
void Statistics()
{
	system("cls");

	int n, t1 = 0,t2 = 0;
	Node* p = HeadNode;
	
	printf("\n  *  此程序目前仅支持简单统计[身高].");
	printf("\n  *  请按任意键继续.");
	getch();

	system("cls");

	printf("\n  *  请输入身高统计值:");
	scanf("%d", &n);

	while (p != NULL)
	{
		if (p->ath.stature >= n)
		{
			t1++;
		}

		t2++;
		p = p->next;
	}

	printf("\n  *  统计成功.");
	printf("\n  *  请按任意键查看.");
	getch();

	system("cls");

	printf("\n  *  身高在 %d CM[大于等于]以上的共有 %d 人.\n", n, t1);
	printf("\n  *  身高在 %d CM[大于等于]以下的共有 %d 人.", n, t2 - t1);
}


//退出部分
void Close()
{
	system("cls");

	printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t       谢 谢 使 用 , 再 见 !\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\n  *  请按任意键继续.\n");
	getch();

	exit(0);
}


//按姓名查询
void SearchName()
{
	system("cls");

	char tName[20];
	Node* p = HeadNode;

	printf("\n  *  请输入要查寻球星的姓名: ");
	scanf("%s", tName);

	system("cls");

	while (p != NULL)
	{
		if (strcmp(p->ath.name, tName) == 0)
		{
			printf("\n  *  查询成功!");
			printf("\n  *  请按任意键查看.");
			getch();

			system("cls");

			printf("\n  *  姓 名     国 籍\t年 龄\t身 高\t场 均 得 分\t场 均 助 攻\n");

			printf("  *  %-10s%-10s%-8d%-11d%-16d%d\n",
				p->ath.name,
				p->ath.nation,
				p->ath.age,
				p->ath.stature,
				p->ath.score,
				p->ath.assist
				);
		}

		p = p->next;
	}
}


//按国籍查询
	void SearchNation()
	{
		system("cls");

		char tNation[20];
		Node* p = HeadNode;

		printf("\n  *  请输入要查寻球星的国籍: ");
		scanf("%s", tNation);

		system("cls");

		printf("\n  *  姓 名     国 籍\t年 龄\t身 高\t场 均 得 分\t场 均 助 攻\n");

		while (p != NULL)
		{
			if (strcmp(p->ath.nation, tNation) == 0)
			{
				printf("  *  %-10s%-10s%-8d%-11d%-16d%d\n",
					p->ath.name,
					p->ath.nation,
					p->ath.age,
					p->ath.stature,
					p->ath.score,
					p->ath.assist
					);
			}

			p = p->next;
		}
	}


//组合查询
void SearchName_Nation()
{
	system("cls");

	char tName[20];
	char tNation[20];
	Node* p = HeadNode;

	printf("\n  *  请输入要查寻球星的姓名: ");
	scanf("%s", tName);
	printf("\n  *  请输入要查寻球星的国籍: ");
	scanf("%s", tNation);

	while (p != NULL)
	{
		if (strcmp(p->ath.name, tName) == 0 &&
			strcmp(p->ath.nation, tNation) == 0)
		{
			printf("\n  *  查询成功!");			      
			printf("\n  *  请按任意键查看.");
			getch();

			system("cls");

			printf("\n  *  姓 名     国 籍\t年 龄\t身 高\t场 均 得 分\t场 均 助 攻\n");
			printf("  *  %-10s%-10s%-8d%-11d%-16d%d\n",
				p->ath.name,
				p->ath.nation,
				p->ath.age,
				p->ath.stature,
				p->ath.score,
				p->ath.assist
				);
		}

		p = p->next;
	}
}


//升序排序
void SelectUp()
{
	system("cls");

	Node* cur, *tmp, *k;
	ATH temp;

	for (cur = HeadNode; cur->next != NULL; cur = cur->next)
	{
		k = cur;
		for (tmp = cur->next; tmp != NULL; tmp = tmp->next)
		{
			if (tmp->ath.stature > k->ath.stature)
			{
				k = tmp;
			}
		}

		if (k != cur)
		{
			temp = cur->ath;
			cur->ath = k->ath;
			k->ath = temp;
		}
	}

	printf("\n  *  排序成功.");
}


//降序排列
void SelectDown()
{
	system("cls");

	Node* cur, *tmp, *k;
	ATH temp;

	for (cur = HeadNode; cur->next != NULL; cur = cur->next)
	{
		k = cur;
		for (tmp = cur->next; tmp != NULL; tmp = tmp->next)
		{
			if (tmp->ath.stature < k->ath.stature)
			{
				k = tmp;
			}
		}

		if (k != cur)
		{
			temp = cur->ath;
			cur->ath = k->ath;
			k->ath = temp;
		}
	}

	printf("\n  *  排序成功.");
}