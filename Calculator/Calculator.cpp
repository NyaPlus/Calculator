// Calculator.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <Windows.h>

void convert_it(char *, char *);
int calculate(char *);

int main()
{
	printf("输入算式（支持+加-减*乘/除()括号^幂）：\n");
	char *c1 = new char[500], *c2 = new char[500];
	scanf("%s", c1);
	convert_it(c1, c2);
	printf("计算结果：%d\n", calculate(c2));
	system("pause");
    return 0;
}

void convert_it(char *from, char *to)
{

}