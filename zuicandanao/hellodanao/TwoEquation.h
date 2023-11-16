
#ifndef TWO_EQUATION_H
#define TWO_EQUATION_H

using namespace std;

class TwoEquation
{
private:
	// ���̵���������
	double a;
	double b;
	double c;

	// �����Ƿ��н�
	bool flag;

	// ���̵�������
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