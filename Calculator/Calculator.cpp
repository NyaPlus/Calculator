// Calculator.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <Windows.h>

void convert_it(char *, char *);
int calculate(char *);

int main()
{
	printf("������ʽ��֧��+��-��*��/��()����^�ݣ���\n");
	char *c1 = new char[500], *c2 = new char[500];
	scanf("%s", c1);
	convert_it(c1, c2);
	printf("��������%d\n", calculate(c2));
	system("pause");
    return 0;
}

void convert_it(char *from, char *to)
{

}