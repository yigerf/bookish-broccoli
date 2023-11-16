#include <cstdlib>

// ×ó±ÕÓÒ±ÕÇø¼ä
int getRand(int min, int max) {
	return (rand() % (max - min + 1)) + min;
}
