#include "TwoEquationRoot.h"
#include "Tool.h"

TwoEquationRoot::TwoEquationRoot(double x1, double x2)
{
	setRoot(x1, x2);
}

TwoEquationRoot::TwoEquationRoot(double x)
{
	setRoot(x);
}

TwoEquationRoot::TwoEquationRoot()
{
	setRoot();
}

//===================================================

void TwoEquationRoot::setRoot(double x1, double x2)
{
	this->x1 = x1;
	this->x2 = x2;
	realRootNum = 2;
}

void TwoEquationRoot::setRoot(double x)
{
	x1 = x2 = x;
	realRootNum = 1;
}

void TwoEquationRoot::setRoot()
{
	x1 = x2 = realRootNum = 0;
}

void TwoEquationRoot::emptyRoot()
{
	setRoot();
}

bool TwoEquationRoot::equals(TwoEquationRoot root)
{
	if (root.getRealRootNum() == realRootNum)
	{
		int tolerable = 0.001;		// 比较小数点前 3 位
		return areAlmostEqual(root.getX1(), x1, 0.001) && areAlmostEqual(root.getX2(), x2, 0.001) ||
			areAlmostEqual(root.getX1(), x2, 0.001) && areAlmostEqual(root.getX2(), x1, 0.001);
	}
	return false;
}

//============================================================

double TwoEquationRoot::getX1()
{
	return x1;
}

double TwoEquationRoot::getX2()
{
	return x2;
}

int TwoEquationRoot::getRealRootNum()
{
	return realRootNum;
}
