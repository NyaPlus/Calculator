// Calculator.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <Windows.h>

char convert_it(char *, char *, int, int, int);
int calculate(char *);

int main()
{
	printf("输入算式（支持+加-减*乘/除()括号^幂）：\n");
	char *c1 = new char[500], *c2 = new char[500];
	scanf("%s", c1);
	char error;
	if (!(error = convert_it(c1, c2,0,0,strlen(c1))))
		printf("计算结果：%d\n", calculate(c2));
	else
		printf("检测到非法字符：%c\n", error);
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