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

TwoEquation::TwoEquation(double a, double b, double c)
{
	// ��ʼ�� a b c
	this->a = a;
	this->b = b;
	this->c = c;
	solving();				// ��ʼ�� flag x1 x2
}


/// <summary>
/// ���� "ax^2 + bx + c = 0" �ַ���
/// </summary>
string TwoEquation::toString()
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

	equation << " = 0 ";

	return equation.str();
}

/// <summary>
/// ����һ�� ���ж�Ԫһ�η��̸� ����Ϣ�Ķ����жϸö����ṩ�������Ƿ��ܽ⿪ this ��Ԫһ�η���
/// </summary>
/// <param name="root"> ������ </param>
/// <returns> �ɹ��⿪�÷��̷��� true������false </returns>
bool TwoEquation::trySolving(TwoEquationRoot root)
{
	return this->root.equals(root);
}

//===========================================

bool TwoEquation::getRealRootNum()
{
	return root.getRealRootNum();
}

double TwoEquation::getX1()
{
	return root.getX1();
}

double TwoEquation::getX2()
{
	return root.getX2();
}

/// <summary>
/// ��ȡ�÷��̵ĸ�
/// </summary>
/// <returns> ��������ʵ��������������ʵ�����ĸ����� </returns>
TwoEquationRoot TwoEquation::getRoots()
{
	return root;
}

/// <summary>
/// �⿪������̣���ʼ���÷��̵ĸ�
/// </summary>
void TwoEquation::solving()
{
	//��Ԫһ�δ������ʽΪx=(-b����(b^2-4ac))/(2a)
	//�� = b ^ 2 - 4ac
	double delta = b * b - 4 * a * c;

	if (delta > 0)
	{
		root.setRoot( (-b + sqrt(delta)) / (2 * a), (-b - sqrt(delta)) / (2 * a) );
	}
	else if (delta == 0)
	{
		root.setRoot( -b / (2 * a) );
	}
	else if (delta < 0)
	{
		root.emptyRoot();
	}
}


