// Calculator.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <Windows.h>

char convert_it(char *, char *, int, int, int);
int calculate(char *);

int main()
{
	printf("������ʽ��֧��+��-��*��/��()����^�ݣ���\n");
	char *c1 = new char[500], *c2 = new char[500];
	scanf("%s", c1);
	char error;
	if (!(error = convert_it(c1, c2,0,0,strlen(c1))))
		printf("��������%d\n", calculate(c2));
	else
		printf("��⵽�Ƿ��ַ���%c\n", error);
	system("pause");
    return 0;
}

char convert_it(char *from, char *to, int fromnum, int tonum, int length)
{
	for (int i = fromnum;i <= length;i++)
	{

	}
	return 0;
}