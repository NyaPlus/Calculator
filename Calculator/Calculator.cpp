// Calculator.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <Windows.h>

char convert_it(char *, char *, int*, int*, int, bool, bool,bool);
int calculate(char *);

int main()
{
	printf("支持+加-减*乘/除()括号^幂!阶乘\n优先级：括号>阶乘=幂>乘除>加减\n请输入算式：");
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
		printf("错误：缺少括号\")\"\n");
		break;
	case 3:
		printf("错误：存在多余的括号\")\"");
		break;
	default:
		printf("错误：检测到非法字符\"%c\"，位于第%d个字符", error, (*fromnum)+1);
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