#include <cstdlib>

// ����ұ�����
int getRand(int min, int max) {
	return (rand() % (max - min + 1)) + min;
}
