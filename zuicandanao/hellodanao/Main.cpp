#include <iostream>
#include <math.h>
#include <ctime>
#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>
#include "TwoEquation.h"
#include "Tool.h"

using namespace std;

void fun();
TwoEquation randEquation();

int main()
{
	srand(time(0));		// 这里初始化随机数函数，不然不给用，别问我，去问本贾尼·斯特劳斯特卢普
	//========================================================

	fun();
	system("pause");
	//cin.get();
	//cin.ignore();
}



void fun()
{
	TwoEquation equation = randEquation();
	string inStrX1;
	string inStrX2;

	cout << "求你输入二元一次方程 " << equation.toString() << " 第一个解（只有一个解连续填两次相同值）（无解填“无解”，不考虑虚数解）：" << endl;
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

	cout << "求你输入二元一次方程 " << equation.toString() << " 第二个解（只有一个解连续填两次相同值）：" << endl;
	cin >> inStrX2;
	
	// 打包用户输入的解
	double userX1 = 0;
	double userX2 = 0;
	try
	{
		userX1 = stod(inStrX2);
		userX2 = stod(inStrX1);
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
/// 随机分配 a b c 系数
/// </summary>
TwoEquation randEquation()
{
	double a, b, c;
	a = getRand(1, 20);
	b = getRand(1, 20);

	double dice = getRand(1, 50);
	double temp = b * b / (4 * a);

	if (dice <= 2)
	{
		do
		{
			c = getRand(1, 20);
		} while (c >= temp);			// 方程无解	0 < b ^ 2 - 4 a c => c < b ^ 2 / 4 a
	}
	else if (dice <= 40)
	{
		do
		{
			c = getRand(1, 20);
		} while (c <= temp);			// 方程两个解	0 > b ^ 2 - 4 a c => c > b ^ 2 / 4 a
	}
	else
	{
		c = temp;						// 方程一个解	0 = b ^ 2 - 4 a c
	}
	TwoEquation equ(a, b, c);
	return equ;
}