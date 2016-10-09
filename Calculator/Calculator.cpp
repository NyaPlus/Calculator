// Calculator.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <Windows.h>

char convert_it(char *, char *, int*, int*, int, bool, bool,bool);
int calculate(char *);

int main()
{
	printf("֧��+��-��*��/��()����^��!�׳�\n���ȼ�������>�׳�=��>�˳�>�Ӽ�\n��������ʽ��");
	char *c1 = new char[500], *c2 = new char[1000];
	scanf("%s", c1);
	char error;
	int *fromnum = new int, *tonum = new int;
	*fromnum = 0;
	*tonum = 0;
	error = convert_it(c1, c2, fromnum, tonum, strlen(c1), false, false,false);
	switch (error)
	{
	case 1:
		printf(c2);
		break;
	case 2:
		printf("����ȱ������\")\"\n");
		break;
	case 3:
		printf("���󣺴��ڶ��������\")\"");
		break;
	default:
		printf("���󣺼�⵽�Ƿ��ַ�\"%c\"��λ�ڵ�%d���ַ�", error, (*fromnum)+1);
		break;
	}
	system("pause");
	delete[]c1;
	delete[]c2;
	delete[]fromnum;
	delete[]tonum;
    return 0;
}

char convert_it(char *from, char *to, int *fromnum, int *tonum, int length, bool isaddorsub, bool ismulordiv, bool ispow)
{
	bool mul = false;
	char temp;
	char error;
	while (*fromnum < length)
	{
		
		if (from[*fromnum] == '(')
		{
			if (from[*fromnum - 1] >= '0' && from[*fromnum - 1] <= '9')
			{
				to[(*tonum)++] = ' ';
				mul = true;
			}
			else
				mul = false;
			(*fromnum)++;
			error = convert_it(from, to, fromnum, tonum, length, false, false,false);
			if (error != 3)
			{
				return 2;
			}
			if (mul)
				to[(*tonum)++] = '*';
		}
		if ((from[*fromnum] >= '0' && from[*fromnum] <= '9'))
		{
			to[(*tonum)++] = from[(*fromnum)++];
		}
		else if (from[*fromnum] == '!')
		{
			to[(*tonum)++] = from[(*fromnum)++];
			to[(*tonum)++] = ' ';
		}
		else if (from[*fromnum] == '^')
		{
			if (ispow)
				return 0;
			to[(*tonum)++] = ' ';
			temp = from[(*fromnum)++];
			error = convert_it(from, to, fromnum, tonum, length, isaddorsub, ismulordiv,true);
			to[(*tonum)++] = temp;
			if (error != 1 && error != 0)
				return error;
		}
		else if (from[*fromnum] == '*' || from[*fromnum] == '/')
		{
			if (ispow || ismulordiv)
				return 0;
			to[(*tonum)++] = ' ';
			temp = from[(*fromnum)++];
			error = convert_it(from, to, fromnum, tonum, length, isaddorsub, true,false);
			to[(*tonum)++] = temp;
			if (error != 1 && error != 0)
				return error;
		}
		else if (from[*fromnum] == '+' || from[*fromnum] == '-')
		{
			if (ispow || ismulordiv || isaddorsub)
				return 0;
			to[(*tonum)++] = ' ';
			temp = from[(*fromnum)++];
			error = convert_it(from, to, fromnum, tonum, length, true, false,false);
			to[(*tonum)++] = temp;
			if (error != 1 && error != 0)
				return error;
		}
		else if (from[*fromnum] == ')')
		{
			(*fromnum)++;
			return 3;
		}
		else
		{
			return from[*fromnum];
		}
	}
	to[*tonum] = 0;
	return 1;
}

int calculate(char *cal)
{
	return 0;
}