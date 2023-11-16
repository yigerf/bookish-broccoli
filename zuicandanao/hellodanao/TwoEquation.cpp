#include <iostream>
#include <math.h>
#include <ctime>
#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>
#include "Tool.h"
#include "TwoEquation.h"

using namespace std;

TwoEquation::TwoEquation()
{
	init_param();			// ��ʼ�� a b c
	solving();				// ��ʼ�� flag x1 x2
}

/// <summary>
/// ������� a b c ϵ��
/// </summary>
void TwoEquation::init_param()
{
	a = getRand(1, 20);
	b = getRand(1, 20);

	double dice = getRand(1, 50);
	double tmp = b * b / (4 * a);

	if (dice <= 2)
	{
		do
		{
			c = getRand(1, 20);
		} while (c >= tmp);			// �����޽�	0 < b ^ 2 - 4 a c => c < b ^ 2 / 4 a
	}
	else if (dice <= 40)
	{
		do
		{
			c = getRand(1, 20);
		} while (c <= tmp);			// ����������	0 > b ^ 2 - 4 a c => c > b ^ 2 / 4 a
	}
	else
	{
		c = tmp;			// ����һ����	0 = b ^ 2 - 4 a c
	}
}

/// <summary>
/// ���� "ax^2 + bx + c = 0" �ַ���
/// </summary>
string TwoEquation::toEquationStr()
{
	// �����ַ�����
	std::ostringstream equation;

	// ƴ��һԪ���η���

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

	// �������յ��ַ���
	return equation.str();
}

bool TwoEquation::getFlag()
{
	return flag;
}

double TwoEquation::getX1()
{
	return x1;
}

double TwoEquation::getX2()
{
	return x2;
}

/// <summary>
/// �⿪�������
/// </summary>
/// <returns> �����нⷵ��true������false </returns>
bool TwoEquation::solving()
{
	//��Ԫһ�δ������ʽΪx=(-b����(b^2-4ac))/(2a)
	//�� = b ^ 2 - 4ac
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
		return flag = false;
	}
	return flag = true;
}


