#include <iostream>
#include <math.h>
#include <ctime>
#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>
#include "TwoEquation.h"

using namespace std;

void fun();

int main()
{
	srand(time(0));
	//========================================================

	fun();
	system("pause");
	//cin.get();
	//cin.ignore();

}

void fun()
{
	TwoEquation equation;
	string inStrX1;
	string inStrX2;

	cout << "求你输入二元一次方程 " << equation.toEquationStr() << " 第一个解（只有一个解连续填两次相同值）（无解填“无解”，不考虑虚数解）：" << endl;
	cin >> inStrX1;
	if (equation.getFlag() && inStrX1 == "无解")		// 有解答无解，答错
	{
		cout << "你答错了，学习去，我帮你关机了" << endl;
		return;
	}
	else if (inStrX1 == "无解")			// 无解答无解，答对
	{
		cout << "你真聪明" << endl;
		return;
	}

	cout << "求你输入二元一次方程 " << equation.toEquationStr() << " 第二个解（只有一个解连续填两次相同值）：" << endl;
	cin >> inStrX2;

	
	// 获取用户输入的解
	double inX1 = 0;
	double inX2 = 0;
	try
	{
		double inX1 = stod(inStrX2);
		double inX2 = stod(inStrX1);
	}
	catch (const std::exception&)
	{
		cerr << "请输入数字，或者”无解“，输错了就结束吧" << endl;
		return;
	}
	double x1 = equation.getX1();
	double x2 = equation.getX2();

	// 判断用户输入的两个解是否正确匹配		//这里逻辑有误，待修复
	if ((abs(inX1 - x1) < 0.000005 && abs(inX2 - x2) < 0.000005) ||
		(abs(inX2 - x1) < 0.000005 && abs(inX1 - x2) < 0.000005))
	{
		// 答对
		cout << "你真聪明" << endl;
		return;
	}
	else
	{
		// 答错
		cout << "你答错了，快去学习，我帮你关机了" << endl;
		return;
	}

}
