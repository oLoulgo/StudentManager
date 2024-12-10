#include "StudentManager.h"

#include<stdio.h>		//�˴�Ҫ�õ�printf��scanf����
#include<malloc.h>
#include<string.h>

static Node* CreateNode()	//Ϊ�����ڵ�дһ����������̬�ڲ��ģ�����Ϊ�������Ḵ�ö�Σ�entryStudent��readStudent��,ʹ��������
{
	//�����ڵ�
	Node* node = malloc(sizeof(Node));
	if (!node)	//�ڴ治��ͷ���ʧ��
	{
		printf("malloc failed\n");
		return NULL;
	}
	node->next = NULL;
	return node;
}

int menu()
{
	printf("**********************************************************************\n");
	printf("*		ѧ���ɼ�����ϵͳ		*\n");
	printf("**********************************************************************\n");
	printf("*	    	    ѡ����    	    	*\n");
	printf("**********************************************************************\n");
	printf("*	    	  1.���ѧ����Ϣ    	    	*\n");
	printf("*	    	  2.��ӡѧ����Ϣ    	    	*\n");
	printf("*	    	  3.ɾ��ѧ����Ϣ    	    	*\n");
	printf("*	    	  4.�޸�ѧ����Ϣ    	    	*\n");
	printf("*	    	  5.ѧ����������    		*\n");
	printf("*	    	  6.�༶�ɼ�����    	    	*\n");
	printf("*	    	  7.���ѧ����Ϣ��    		*\n");
	printf("*	    	  8.����ѧ����Ϣ    	    	*\n");
	printf("*	    	  9.��ȡѧ����Ϣ    	    	*\n");
	printf("*	    	  10.����ѧ����Ϣ    	    	*\n");
	printf("*	    	  0.�˳�ϵͳ    	    	*\n");
	printf("*************************************************\n");
	printf("select>");
	int select = -1;
	scanf("%d", &select);
	return select;
}

void entryStudent(List* list)
{
	/*//�����ڵ�	
	Node* node = malloc(sizeof(Node));
	if (!node)	//�ڴ治��ͷ���ʧ��
	{
		printf("malloc failed\n");
		return;
	}
	node->next = NULL;
	*/
	Node* node = CreateNode();	//�����˴����ڵ�

	//����ѧ����Ϣ
	printf("������ѧ��ѧ��>");
	scanf("%llu", &node->stu.number);	//��Ϊ�Ǹ�����(������)������ȡ��ַ&

	printf("������ѧ������>");
	scanf("%s", node->stu.name);		//�������ַ��������ַ�����,�����������׵�ַ����˲���&

	printf("������ѧ���༶>");
	scanf("%s", node->stu.class);

	printf("������ѧ����ѧ�ɼ�>");
	scanf("%f", &node->stu.math);

	printf("������ѧ��Ӣ��ɼ�>");
	scanf("%f", &node->stu.english);

	printf("������ѧ��������ɼ�>");
	scanf("%f", &node->stu.computer);

	node->stu.average = (node->stu.math + node->stu.english + node->stu.computer) /3.0f;

	//���뵽������
	node->next = list->front;	//ͷ�壺�½��ָ��ԭ�������һ����frontָ���½��
	list->front = node;
	list->size++;

}

void printStudent(List* list)
{
	printf("********************************************************************\n");
	printf("*			ѧ���ɼ�����ϵͳ			   *\n");
	printf("********************************************************************\n");
	printf("*	ѧ��	*  ����  *  �༶  *  ��ѧ  *  Ӣ��  *   �����   *  ƽ���ɼ�  *\n");	//��������tab����
	printf("********************************************************************\n");

	//��������	//04  4m
	Node* curNode = list->front;
	while (curNode != NULL)
	{
		printf("*%llu \t*%s \t*%s \t*%.1lf \t*%.1lf \t*%.1lf \t*%.1lf \t\n",curNode->stu.number,curNode->stu.name,curNode->stu.class,
			curNode->stu.math,curNode->stu.english,curNode->stu.computer,curNode->stu.average);
		curNode = curNode->next;
	}
}

void saveStudent(List* list)
{
	//���ļ�
	FILE* fp = fopen("students.data", "wb");	//wbָ�ö�����д�룬����ļ��п�����
	if (!fp)
	{
		perror("file open failed");
		return;
	}

	//д��ѧ����Ϣ
	Node* curNode = list->front;
	while (curNode != NULL)
	{
		fwrite(&curNode->stu, sizeof(Student), 1, fp);	//д�����ݵĵ�ַ��Ҫд��Ԫ�صĴ�С��д��1����д��fp�ļ�
		curNode = curNode->next;
	}

	//�ر��ļ�
	fclose(fp);
}

void saveStudentHuman(List* list)
{
	//���ļ�
	FILE* fp = fopen("students.txt", "w");	//wbָ�ö�����д�룬����ļ��п�����
	if (!fp)
	{
		perror("file open failed");
		return;
	}

	//д��ѧ����Ϣ
	Node* curNode = list->front;
	while (curNode != NULL)
	{
		fprintf(fp,"%llu\t%s\t%s\t%.lf\t%.lf\t%.lf\t%.lf\n", curNode->stu.number, curNode->stu.name, curNode->stu.class,
			curNode->stu.math, curNode->stu.english, curNode->stu.computer, curNode->stu.average);
		curNode = curNode->next;
	}

	//�ر��ļ�
	fclose(fp);
}

void readStudent(List* list)
{
	//���ļ�
	FILE* fp = fopen("students.data", "rb");	//�����saveStudent��ĸ��ƹ��������ǰ������wb�ĳ�rb�����Դ洢�ļ����������֮ǰ�Լ���ʾһ�����ر������¶�ȡ��ʾ�ļ��հ�
	if (!fp)
	{
		perror("file open failed");
		return;
	}

	//��ȡѧ����Ϣ
	while (!feof(fp))	//δ����ʱ��һֱ��
	{
		Node* node = CreateNode();	//�����˴����ڵ�
		if (!node)	//����ʧ�ܾ�����ѭ��
			break;

		size_t len = fread(&node->stu, sizeof(Student), 1, fp);		//ָ��һ���ڴ��ָ�루��Ŷ�ȡ���������ݣ���ÿ��Ԫ�صĴ�С��Ҫ��ȡ��Ԫ�ظ�������fp����ļ����
		if (len == 0)	//����0��˵����ʧ���ˣ��Ϳ��Բ����ˣ�
		{
			free(node);
			break;
		}

		//���뵽������		//�Ѷ�ȡ��Ԫ�ز��뵽�����У�
		node->next = list->front;
		list->front = node;
		list->size++;
	}

	//�ر��ļ�
	fclose(fp);

}

void readStudentHuman(List* list)
{
	//���ļ�
	FILE* fp = fopen("students.txt", "r");	//r,���ķ�ʽ
	if (!fp)
	{
		perror("file open failed");
		return;
	}

		//��ȡѧ����Ϣ
	while (!feof(fp))	//δ�����һֱ��
	{
		Node* node = CreateNode();
		if (!node)
			break;
		fscanf(fp,"%llu\t%s\t%s\t%f\t%f\t%f\t%f\n", &node->stu.number, node->stu.name, node->stu.class,
			&node->stu.math, &node->stu.english, &node->stu.computer, &node->stu.average);	//Ϊʲô%.lf�ĳ���%f	/ԭ��if ��7 ��=��
		//{
		//	free(node);
		//	break;
		//}

		//��������
		node->next = list->front;
		list->front = node;
		list->size++;
	}

		//�ر��ļ�
		fclose(fp);

}

Node* findStudent(List* list)
{
	///if (list->size == 0)
	//{
	//	//printf("ϵͳ����ѧ����Ϣ\n");
	//	return;
	//}

	char buffer[32];
	printf("������ѧ����ѧ�Ż�����>");
	scanf("%s", buffer);

	//��bufferת������
	unsigned long long number = -1;
	sscanf(buffer, "%llu", &number);

	Node* curNode = list->front;
	while (curNode != NULL)
	{
		if (strcmp(curNode->stu.name, buffer) == 0 || curNode->stu.number == number)
		{
			printf("%llu\t%s\t%s\t%.lf\t%.lf\t%.lf\t%.lf\n", curNode->stu.number, curNode->stu.name, curNode->stu.class,
				curNode->stu.math, curNode->stu.english, curNode->stu.computer, curNode->stu.average);
			return curNode;
		}
		curNode = curNode->next;
	}

	return NULL;
}	 //Ϊʲô����void

void alterStudent(List* list)	//�Ȳ������޸�
{
	if (list->size == 0)
	{
		printf("ϵͳ����ѧ����Ϣ\n");
		return;
	}

	char buffer[32];
	printf("������Ҫ�޸ĵ�ѧ����ѧ�Ż�����>");
	scanf("%s", buffer);

	//��bufferת������
	unsigned long long number = -1;
	sscanf(buffer, "%llu", &number);

	Node* curNode = list->front;
	while (curNode != NULL)
	{
		if (strcmp(curNode->stu.name, buffer) == 0 || curNode->stu.number == number)
		{
			printf("������Ҫ�޸ĵ�ѧ�����Ƴɼ�>");
			scanf("%f %f %f", &curNode->stu.math, &curNode->stu.english, &curNode->stu.computer);
			curNode->stu.average = (curNode->stu.math + curNode->stu.english + curNode->stu.computer) / 3.0f;
			printf("�޸ĳɹ�\n");
			break;
		}
		curNode = curNode->next;
	}
	if (curNode == NULL)
		printf("δ�ҵ���ѧ�����޸�ʧ��\n");
}

void removeStudent(List* list)	//�Ƴ�ǰ���ҵ�
{
	if (list->size == 0)
	{
		printf("ϵͳ����ѧ����Ϣ\n");
		return;
	}

	char buffer[32];
	printf("������Ҫɾ����ѧ����ѧ�Ż�����>");
	scanf("%s", buffer);

	//��bufferת������
	unsigned long long number = -1;
	sscanf(buffer, "%llu", &number);

	Node* curNode = list->front;
	Node* prevNode = NULL;
	while (curNode != NULL)
	{
		if (strcmp(curNode->stu.name, buffer) == 0 || curNode->stu.number == number)
		{
			break;
		}
		prevNode = curNode;
		curNode = curNode->next;

	}

	//�Ƿ��ҵ�
	if (curNode)
	{
		//Ҫɾ�����ǵ�һ���ڵ�
		if (prevNode == NULL)
		{
			list->front = curNode->next;
		}
		else
		{
			prevNode->next = curNode->next;
		}
		free(curNode);
		list->size--;
		printf("ɾ���ɹ�\n");
	}
	else
		printf("δ�ҵ���ѧ�����޸�ʧ��\n");
}

void rankStudent(List* list)
{
	/*int i = 0;
	int j = 0;
	for (; i < list->size - 1; i++)
	{
		for (; j < (list->size - 1 - i); j++)
		{
			if ((list->E[j].English - L->E[j + 1].English) >= 0)
			{
				People tmp;
				tmp = L->E[j];
				L->E[j] = L->E[j + 1];
				L->E[j + 1] = tmp;
			}
		}
	}
	printf("����ɹ���\n");*/
}


