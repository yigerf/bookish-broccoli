#include <iostream>
#include <math.h>
#include <ctime>
#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>
#include "Tool.h"
#include "TwoEquation.h"

using namespace std;

TwoEquation::TwoEquation()
{
	init_param();			// 初始化 a b c
	solving();				// 初始化 flag x1 x2
}

/// <summary>
/// 随机分配 a b c 系数
/// </summary>
void TwoEquation::init_param()
{
	a = getRand(1, 20);
	b = getRand(1, 20);

	double dice = getRand(1, 50);
	double tmp = b * b / (4 * a);

	if (dice <= 2)
	{
		do
		{
			c = getRand(1, 20);
		} while (c >= tmp);			// 方程无解	0 < b ^ 2 - 4 a c => c < b ^ 2 / 4 a
	}
	else if (dice <= 40)
	{
		do
		{
			c = getRand(1, 20);
		} while (c <= tmp);			// 方程两个解	0 > b ^ 2 - 4 a c => c > b ^ 2 / 4 a
	}
	else
	{
		c = tmp;			// 方程一个解	0 = b ^ 2 - 4 a c
	}
}

/// <summary>
/// 返回 "ax^2 + bx + c = 0" 字符串
/// </summary>
string TwoEquation::toEquationStr()
{
	// 创建字符串流
	std::ostringstream equation;

	// 拼接一元二次方程

	if (a >= 0) {
		equation << a << "x^2";
	}
	else {
		equation << " - " << -a << "x^2";
	}

	if (b >= 0) {
		equation << " + " << b << "x";
	}
	else {
		equation << " - " << -b << "x";
	}

	if (c >= 0) {
		equation << " + " << c;
	}
	else {
		equation << " - " << -c;
	}

	// 返回最终的字符串
	return equation.str();
}

bool TwoEquation::getFlag()
{
	return flag;
}

double TwoEquation::getX1()
{
	return x1;
}

double TwoEquation::getX2()
{
	return x2;
}

/// <summary>
/// 解开这个方程
/// </summary>
/// <returns> 方程有解返回true，否则false </returns>
bool TwoEquation::solving()
{
	//二元一次次求根公式为x=(-b±√(b^2-4ac))/(2a)
	//△ = b ^ 2 - 4ac
	double delta = b * b - 4 * a * c;

	if (delta > 0)
	{
		x1 = (-b + sqrt(delta)) / (2 * a);
		x2 = (-b - sqrt(delta)) / (2 * a);
	}
	else if (delta == 0)
	{
		x1 = x2 = (-b + sqrt(delta)) / 2 * a;
	}
	else if (delta < 0)
	{
		return flag = false;
	}
	return flag = true;
}


