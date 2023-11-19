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

TwoEquation::TwoEquation(double a, double b, double c)
{
	// 初始化 a b c
	this->a = a;
	this->b = b;
	this->c = c;
	solving();				// 初始化 flag x1 x2
}


/// <summary>
/// 返回 "ax^2 + bx + c = 0" 字符串
/// </summary>
string TwoEquation::toString()
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

	equation << " = 0 ";

	return equation.str();
}

/// <summary>
/// 接收一个 带有二元一次方程根 的信息的对象，判断该对象提供的数据是否能解开 this 二元一次方程
/// </summary>
/// <param name="root"> 根对象 </param>
/// <returns> 成功解开该方程返回 true，否则false </returns>
bool TwoEquation::trySolving(TwoEquationRoot root)
{
	return this->root.equals(root);
}

//===========================================

bool TwoEquation::getRealRootNum()
{
	return root.getRealRootNum();
}

double TwoEquation::getX1()
{
	return root.getX1();
}

double TwoEquation::getX2()
{
	return root.getX2();
}

/// <summary>
/// 获取该方程的根
/// </summary>
/// <returns> 包含方程实数根个数及具体实数根的根对象 </returns>
TwoEquationRoot TwoEquation::getRoots()
{
	return root;
}

/// <summary>
/// 解开这个方程，初始化该方程的根
/// </summary>
void TwoEquation::solving()
{
	//二元一次次求根公式为x=(-b±√(b^2-4ac))/(2a)
	//△ = b ^ 2 - 4ac
	double delta = b * b - 4 * a * c;

	if (delta > 0)
	{
		root.setRoot( (-b + sqrt(delta)) / (2 * a), (-b - sqrt(delta)) / (2 * a) );
	}
	else if (delta == 0)
	{
		root.setRoot( -b / (2 * a) );
	}
	else if (delta < 0)
	{
		root.emptyRoot();
	}
}


