#include <cstdlib>

// ����ұ�����
int getRand(int min, int max) {
	return (rand() % (max - min + 1)) + min;
}

/// <summary>
/// �ж�����������֮��ľ���ֵ�Ƿ�С��tolerance��С������Ϊ������Ȳ�����true
/// </summary>
bool areAlmostEqual(double a, double b, double tolerance = 1e-9) {
	return fabs(a - b) < tolerance;
}
