#include <iostream>
#include "AnswerView.h"

using namespace std;

int main()
{
	AnswerView& av = AnswerView::getSingleton();
	av.mainFun();		// 这里获取单例然后开始答题.
	system("pause");
}




