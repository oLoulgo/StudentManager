#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include <string.h>

#include "StudentManager.h"		//以下代码要用到头文件StudentManager.h中的menu，因此把该头文件包含进来





int main(int argc, char* arv[])
{
	//创建链表
	List list = { 0 };
	//内存设置
	memset(&list, 0, sizeof(List));
	//02 10m	//从list的地址开始，将接下来sizeof(s)个字节全部设为0，确保结构体初始化，也防止野指针出现

	bool isRunning = true;
	while (isRunning)	//实现多次功能选择，而非选择一次就退出
	{

		switch (menu())	//增加代码可读性
		{
		case Quit:
			isRunning = false;
			system("cls");
			printf("已退出学生成绩管理系统\n");
			break;
		case Entry:
			entryStudent(&list);
			break;
		case Print:
			printStudent(&list);
			break;
		case Remove:
			removeStudent(&list);
			break;
		case Alter:
			alterStudent(&list);
			break;
		case Rank:
			rankStudent(&list);
			break;
		case Analyse:
			break;
		case Char:
			break;
		case Save:
			//saveStudent(&list);
			saveStudentHuman(&list);
			break;
		case Read:
			//readStudent(&list);
			readStudentHuman(&list);
			break;
		case Find:
		{
			Node* node = findStudent(&list);
			if (!node)
			{
				printf("未找到所查询学生\n");
			}
			//else
			//{
			//	printf("%llu\t%s\t%s\t%.lf\t%.lf\t%.lf\t%.lf\n", node->stu.number, node->stu.name, node->stu.class,
			//		node->stu.math, node->stu.english, node->stu.computer, node->stu.average);
			//}
			break;
		}
		default:
			printf("输入参数错误\n");
			break;
		}

		if (isRunning)
		{
			//让程序暂停一会儿
			system("pause");
			//清屏，用以删除循环打印的多个菜单
			system("cls");
		}	
		}

		return 0;
	
}