#include "TwoEquationRoot.h"

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
		if ( (root.getX1() == x1 && root.getX2() == x2) || 
			 (root.getX1() == x2 && root.getX2() == x1) )
		{
			return true;
		}
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
