#include <cstdlib>

// 左闭右闭区间
int getRand(int min, int max) {
	return (rand() % (max - min + 1)) + min;
}

/// <summary>
/// 判断两个浮点数之间的绝对值是否小于tolerance，小于则认为两数相等并返回true
/// </summary>
bool areAlmostEqual(double a, double b, double tolerance = 1e-9) {
	return fabs(a - b) < tolerance;
}
