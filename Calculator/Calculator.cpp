// Calculator.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <math.h>

char convert_it(char *, char *, int*, int*, int, bool, bool,bool);
int calculate(char *, int*, int, int);

int main()
{
	printf("支持整数的+加-减*乘/除()括号^幂!阶乘运算\n可显示的数值范围：-2147483648----2147483647\n负数请写(0-x)比如-1就写(0-1)\n优先级：括号>阶乘=幂>乘除>加减\n请输入算式：");
	char *c1 = new char[500], *c2 = new char[1000];
	std::cin >> c1;
	char error;
	int *fromnum = new int, *tonum = new int;
	*fromnum = 0;
	*tonum = 0;
	error = convert_it(c1, c2, fromnum, tonum, strlen(c1), false, false,false);
	switch (error)
	{
	case 1:
		*fromnum = 0;
		std::cout << "结果=" << calculate(c2, fromnum, *tonum, 0) << std::endl;
		break;
	case 2:
		std::cout << "错误：缺少括号\")\"" << std::endl;
		break;
	case 3:
		std::cout << "错误：存在多余的括号\")\"" << std::endl;
		break;
	case 4:
		std::cout << "错误：表达式错误，位于第" << (*fromnum) + 1 << "个字符" << std::endl;
		break;
	default:
		std::cout << "错误：检测到非法字符\"" << error << "\"，位于第" << (*fromnum) + 1 << "个字符" << std::endl;
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
	bool mul = false, numed=false ,mulmul = false;
	char temp;
	char error;
	while (*fromnum <= length)
	{
		
		if (from[*fromnum] == '(')
		{
			numed = true;
			mulmul = false;
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
			if (mulmul)
				return 4;
			numed = true;
			to[(*tonum)++] = from[(*fromnum)++];
		}
		else if (from[*fromnum] == '!')
		{
			if (!numed)
				return 4;
			mulmul = true;
			to[(*tonum)++] = from[(*fromnum)++];
		}
		else if (from[*fromnum] == '^')
		{
			if (!numed)
				return 4;
			if (ispow)
				return 0;
			numed = false;
			mulmul = false;
			to[(*tonum)++] = ' ';
			temp = from[(*fromnum)++];
			error = convert_it(from, to, fromnum, tonum, length, isaddorsub, ismulordiv,true);
			to[(*tonum)++] = temp;
			if (error)
				return error;
			numed = true;
		}
		else if (from[*fromnum] == '*' || from[*fromnum] == '/')
		{
			if (!numed)
				return 4;
			if (ispow || ismulordiv)
				return 0;
			numed = false;
			mulmul = false;
			to[(*tonum)++] = ' ';
			temp = from[(*fromnum)++];
			error = convert_it(from, to, fromnum, tonum, length, isaddorsub, true,false);
			to[(*tonum)++] = temp;
			if (error)
				return error;
			numed = true;
		}
		else if (from[*fromnum] == '+' || from[*fromnum] == '-')
		{
			if (!numed)
				return 4;
			if (ispow || ismulordiv || isaddorsub)
				return 0;
			numed = false;
			mulmul = false;
			to[(*tonum)++] = ' ';
			temp = from[(*fromnum)++];
			error = convert_it(from, to, fromnum, tonum, length, true, false,false);
			to[(*tonum)++] = temp;
			if (error)
				return error;
			numed = true;
		}
		else if (from[*fromnum] == ')')
		{
			(*fromnum)++;
			return 3;
		}
		else if (from[*fromnum] == 0)
		{
			if (!numed)
				return 4;
			(*fromnum)++;
		}
		else
		{
			return from[*fromnum];
		}
	}
	return 1;
}

int calculate(char *cal,int *begin, int length, int num1)
{
	int num2 = 0;
	while (*begin < length)
	{
		if (cal[*begin] >= '0' && cal[*begin] <= '9')
		{
			num2 *= 10;
			num2 += cal[(*begin)++] - '0';
		}
		else if (cal[*begin] == ' ')
		{
			(*begin)++;
			num2 = calculate(cal, begin, length, num2);
		}
		else if (cal[*begin] == '+')
		{
			(*begin)++;
			return num1 + num2;
		}
		else if (cal[*begin] == '-')
		{
			(*begin)++;
			return num1 - num2;
		}
		else if (cal[*begin] == '*')
		{
			(*begin)++;
			return num1 * num2;
		}
		else if (cal[*begin] == '/')
		{
			(*begin)++;
			return num1 / num2;
		}
		else if (cal[*begin] == '^')
		{
			(*begin)++;
			return (int)pow((double)num1,(double)num2);
		}
		else if (cal[*begin] == '!')
		{
			(*begin)++;
			int temp = 1;
			for (int i = 1;i <= num2;i++)
			{
				temp *= i;
			}
			num2 = temp;
		}
	}
	return num1 + num2;
}