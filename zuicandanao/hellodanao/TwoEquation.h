
#ifndef TWO_EQUATION_H
#define TWO_EQUATION_H
#include "TwoEquationRoot.h"

using namespace std;

class TwoEquation
{
private:
	// 方程的三个参数
	double a;
	double b;
	double c;

	// 方程的根
	TwoEquationRoot root;

public:
	TwoEquation(double a, double b, double c);

	string toString();
	bool trySolving(TwoEquationRoot root);

	TwoEquationRoot getRoots();
	bool getRealRootNum();
	double getX1();
	double getX2();

private:
	void solving();
};
#endif	// TWO_EQUATION_H