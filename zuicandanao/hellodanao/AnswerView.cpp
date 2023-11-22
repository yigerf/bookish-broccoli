#include <iostream>
#include <math.h>
#include <ctime>
#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>
#include "Tool.h"
#include "TwoEquation.h"
#include "TwoEquationRoot.h"
#include "AnswerView.h"

void mainFun()
{

	TwoEquation equation = randEquation();
	string inStrX1;
	string inStrX2;

	cout << "��⿪�����Ԫһ�η��� " << equation.toString() << " ������ĵ��Խ��������ѡ�" << endl;
	cout << "��ʾ��" << endl;
	cout << "\t������ֻ��һ�����������������ֵͬ." << endl;
	cout << "\t�������޽�����޽⡱��������������." << endl;
	cout << "�������һ���⣺" << endl;
	cin >> inStrX1;

	if (inStrX1 == "�޽�")
	{
		TwoEquationRoot root;
		if (equation.trySolving(root))
		{
			cout << "ȷʵ���޽�" << endl;
		}
		else
		{
			cout << "��ʵ������н⣬ֻ�������ˣ��ԹԹػ���" << endl;
		}
		return;
	}
	cout << "������ڶ����⣺" << endl;
	cin >> inStrX2;

	// ����û�����Ľ�
	double userX1, userX2;
	try
	{
		userX1 = stod(inStrX1);
		userX2 = stod(inStrX2);
	}
	catch (const std::exception&)
	{
		cerr << "���������֣����ߡ��޽⡰��������͹ػ��ɣ���" << endl;
		return;
	}
	TwoEquationRoot root(userX1, userX2);

	// �ж��û�������������Ƿ���ȷƥ��		//�����߼����󣬴��޸�
	if (equation.trySolving(root))
	{
		cout << "�������" << endl;
	}
	else
	{
		cout << "�����ˣ���ȥѧϰ�ɣ��Ұ���ػ���" << endl;
	}

}

/// <summary>
/// �������һ����Ԫһ�κ���
/// </summary>
/// <returns>��Ԫһ�κ�������</returns>
TwoEquation randEquation()
{
	srand(time(0));		// �����ʼ���������������Ȼ�����ã�������ȥ�ʱ����ᡤ˹����˹��¬��

	double a, b, c;
	a = getRand(1, 16);
	b = getRand(-10, 10);

	double dice = getRand(1, 50);
	double temp = (b * b) / (4 * a);

	if (dice <= 2)
	{
		do
		{
			c = getRand(temp + 1, temp + 20);
		} while (c <= temp);			// �����޽�	 �� = b ^ 2 - 4 a c < 0  =>  c > b ^ 2 / 4 a
	}
	else if (dice <= 40)
	{
		do
		{
			c = getRand(temp - 20, temp - 1);
		} while (c >= temp);			// ����������	 �� = b ^ 2 - 4 a c > 0  =>  c < b ^ 2 / 4 a
	}
	else
	{
		c = temp;						// ����һ����	 �� = b ^ 2 - 4 a c = 0
	}
	TwoEquation equ(a, b, c);
	return equ;
}