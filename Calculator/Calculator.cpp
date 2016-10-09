// Calculator.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <Windows.h>

char convert_it(char *, char *, int*, int, int, bool);
int calculate(char *);

int main()
{
	printf("支持+加-减*乘/除()括号^幂!阶乘\n优先级：括号>阶乘>幂>乘除>加减\n请输入算式：");
	char *c1 = new char[500], *c2 = new char[500];
	scanf("%s", c1);
	char error;
	int *fromnum = new int;
	*fromnum = 0;
	if (!(error = convert_it(c1, c2,fromnum,0,strlen(c1), false)))
		printf("计算结果：%d\n", calculate(c2));
	else
		printf("检测到非法字符\"%c\"，位于第%d个字符\n", error, *fromnum);
	system("pause");
	delete[]c1;
	delete[]c2;
	delete[]fromnum;
    return 0;
}

char convert_it(char *from, char *to, int *fromnum, int tonum, int length, bool isaddorsub)
{

	while (*fromnum <= length)
	{
		if (from[*fromnum] == '(')
		{
			convert_it(from, to, fromnum, tonum, length);
		}
		if (from[*fromnum] >= '0' && from[*fromnum] <= '9')
		{
			to[tonum++] = from[(*fromnum)++];
		}
		else if (from[*fromnum] == '!')
		{

		}
		else if (from[*fromnum] == '^')
		{

		}
		else if (from[*fromnum] == '*' || from[*fromnum] == '/')
		{

		}
		else if (from[*fromnum] == '+' || from[*fromnum] == '-')
		{
			if (isaddorsub)
				return 0;

		}
		else if (from[*fromnum] == ')')
		{
			(*fromnum)++;
			return 0;
		}
		else
		{
			return from[*fromnum];
		}
	}
	return 0;
}

int calculate(char *cal)
{
	return 0;
}