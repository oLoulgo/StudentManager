#pragma once

/*
 * 学生结构
 */
typedef struct Student
{
	unsigned long long number;	//学号
	char name[10];				//姓名
	char class[32];				//班级
	float math;
	float english;
	float computer;
	float average;				//还未做
}Student;

/*
 * 节点 Node
 */
typedef struct Node
{
	Student stu;		//学生
	struct Node* next;	//指向下一个节点的指针
}Node;	//不能直接使用这个别名，因为使用时未出来，定义在后面

/**
 * 链表
 */
typedef struct List
{
	Node* front;	//指向第一个节点
	int size;		//当前节点数量
}List;

/**
 * 菜单功能.
 */
typedef enum MenuOptions
{
	Quit,		//退出系统
	Entry,		//录入学生
	Print,		//打印学生
	Remove,		//删除学生
	Alter,		//修改学生
	Rank,		//学生排序
	Analyse,	//成绩分析
	Char,		//学生总表
	Save,		//保存学生
	Read,		//读取学生
	Find,		//查找学生
}MenuOptions;

/**
 * 打印菜单，并提示用户选择功能.
 */
int menu();

/*学生录入*/
void entryStudent(List* list);

/*学生打印？查找*/
void printStudent(List* list);

/*保存学生,二进制保存（看不懂）*/
void saveStudent(List* list);

/*保存学生（看得懂）*/
void saveStudentHuman(List* list);

/*读取学生,二进制*/
void readStudent(List* list);

/*读取学生,读懂*/
void readStudentHuman(List* list);

/*查找学生*/
Node* findStudent(List* list);

/*修改学生*/
void alterStudent(List* list);

/*修改学生*/
void removeStudent(List* list);

//按平均成绩排序
void rankStudent(List* list);

