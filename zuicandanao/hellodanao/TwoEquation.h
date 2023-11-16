
#ifndef TWO_EQUATION_H
#define TWO_EQUATION_H

using namespace std;

class TwoEquation
{
private:
	// 方程的三个参数
	double a;
	double b;
	double c;

	// 方程是否有解
	bool flag;

	// 方程的两个根
	double x1;
	double x2;

public:
	TwoEquation();
	void init_param();
	string toEquationStr();
	bool getFlag();
	double getX1();
	double getX2();

private:
	bool solving();
};
#endif	// TWO_EQUATION_H