#ifndef TWO_EQUATION_ROOT_H
#define TWO_EQUATION_ROOT_H

class TwoEquationRoot
{
private:
	// 方程实数根个数
	int realRootNum;

	// 方程的两个根
	double x1;
	double x2;

public:
	TwoEquationRoot(double x1, double x2);
	TwoEquationRoot(double x);
	TwoEquationRoot();

	void setRoot(double x1, double x2);
	void setRoot(double x);
	void setRoot();
	void emptyRoot();
	bool equals(TwoEquationRoot root);

	double getX1();
	double getX2();
	int getRealRootNum();
};

#endif // !TWO_EQUATION_ROOT_H

