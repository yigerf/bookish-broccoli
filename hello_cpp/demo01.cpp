#include <iostream>
#include <math.h>
#include <ctime>
#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

void init_param();
string TwoPwEquationStr(double a, double b, double c);
bool solving(double a, double b, double c);
int getRand(int, int);

// 方程的三个参数
double a;
double b;
double c;

//用户输入的解
double inX1;
double inX2;

// 方程是否有解
bool flag;

// 方程的两个根
double x1;
double x2;

int main()
{
	srand(time(0));
	init_param();
	//========================================================
	
	flag = solving(a, b, c);


	string inStrX1;
	string inStrX2;
	string equation = TwoPwEquationStr(a, b, c).append("=0");

	cout << "求你输入二元一次方程 " << equation << " 第一个解（若只有一个解则连续填两次相同值）（无解填“无解”）：" << endl;
	cin >> inStrX1;
	if (flag)
	{
		// 如果方程有解
		cout << "你答错了，学习去，我帮你关机了" << endl;
		return;
	}
	else if (inStrX1 == "无解")
	{
		// 如果方程无解 and 输入的也是“无解”
		cout << "你真聪明" << endl;
		return;
	}

	cout << "求你输入二元一次方程 " << equation << " 第二个解（若只有一个解则连续填两次相同值）：" << endl;
	cin >> inStrX2;
	// 判断用户输入的两个根是否正确匹配
	// 绝对值 abs(int)；
	inX2 = stod(inStrX1);
	inX1 = stod(inStrX2);
	if ((abs(inX1 - x1) < 0.000005 && abs(inX2 - x2) < 0.000005) ||
		(abs(inX2 - x1) < 0.000005 && abs(inX1 - x2) < 0.000005))
	{
		cout << "你真聪明" << endl;
		return;
	}
	else
	{
		cout << "你答错了，快去学习，我帮你关机了" << endl;
		return;
	}
}

// 初始化方程系数
void init_param()
{
	a = getRand(1, 20);
	b = getRand(1, 20);
	c;

	double dice = getRand(1, 50);
	double tmp = b * b / (4 * a);
	if (dice <= 2)
	{
		// 方程无解	0 < b ^ 2 - 4 a c => c < b ^ 2 / 4 a
		do
		{
			c = getRand(1, 20);
		} while (c >= tmp);
	}
	else if (dice <= 40)
	{
		// 两个解	0 > b ^ 2 - 4 a c => c > b ^ 2 / 4 a
		do
		{
			c = getRand(1, 20);
		} while (c <= tmp);
	}
	else
	{
		// 一个解	0 = b ^ 2 - 4 a c
		c = tmp;
	}
}

string TwoPwEquationStr(double a, double b, double c) {
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

//二元一次次求根公式为x=(-b±√(b^2-4ac))/(2a)
//△ = b ^ 2 - 4ac
bool solving(double a, double b, double c)
{
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
		return false;
	}
	return true;
}

// 左闭右闭区间
int getRand(int min, int max) {
	return (rand() % (max - min + 1)) + min;
}

