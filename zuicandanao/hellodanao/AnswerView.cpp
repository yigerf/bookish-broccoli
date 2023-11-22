#include <iostream>
#include <math.h>
#include <ctime>
#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>
#include "Tool.h"
#include "TwoEquation.h"
#include "TwoEquationRoot.h"
#include "AnswerView.h"

void mainFun()
{

	TwoEquation equation = randEquation();
	string inStrX1;
	string inStrX2;

	cout << "请解开这个二元一次方程 " << equation.toString() << " 否则你的电脑将面临灾难。" << endl;
	cout << "提示：" << endl;
	cout << "\t若方程只有一个解就连续填两次相同值." << endl;
	cout << "\t若方程无解则填“无解”，不考虑虚数解." << endl;
	cout << "请输入第一个解：" << endl;
	cin >> inStrX1;

	if (inStrX1 == "无解")
	{
		TwoEquationRoot root;
		if (equation.trySolving(root))
		{
			cout << "确实是无解" << endl;
		}
		else
		{
			cout << "其实这道题有解，只是你打错了，乖乖关机吧" << endl;
		}
		return;
	}
	cout << "请输入第二个解：" << endl;
	cin >> inStrX2;

	// 打包用户输入的解
	double userX1, userX2;
	try
	{
		userX1 = stod(inStrX1);
		userX2 = stod(inStrX2);
	}
	catch (const std::exception&)
	{
		cerr << "请输入数字，或者”无解“，乱输入就关机吧！！" << endl;
		return;
	}
	TwoEquationRoot root(userX1, userX2);

	// 判断用户输入的两个解是否正确匹配		//这里逻辑有误，待修复
	if (equation.trySolving(root))
	{
		cout << "你真聪明" << endl;
	}
	else
	{
		cout << "你答错了，快去学习吧，我帮你关机了" << endl;
	}

}

/// <summary>
/// 随机生成一个二元一次函数
/// </summary>
/// <returns>二元一次函数对象</returns>
TwoEquation randEquation()
{
	srand(time(0));		// 这里初始化随机数函数，不然不给用，有疑问去问本贾尼·斯特劳斯特卢普

	double a, b, c;
	a = getRand(1, 16);
	b = getRand(-10, 10);

	double dice = getRand(1, 50);
	double temp = (b * b) / (4 * a);

	if (dice <= 2)
	{
		do
		{
			c = getRand(temp + 1, temp + 20);
		} while (c <= temp);			// 方程无解	 Δ = b ^ 2 - 4 a c < 0  =>  c > b ^ 2 / 4 a
	}
	else if (dice <= 40)
	{
		do
		{
			c = getRand(temp - 20, temp - 1);
		} while (c >= temp);			// 方程两个解	 Δ = b ^ 2 - 4 a c > 0  =>  c < b ^ 2 / 4 a
	}
	else
	{
		c = temp;						// 方程一个解	 Δ = b ^ 2 - 4 a c = 0
	}
	TwoEquation equ(a, b, c);
	return equ;
}