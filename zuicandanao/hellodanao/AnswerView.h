#ifndef ANSWER_VIEW
#define ANSWER_VIEW
#include "TwoEquation.h"

class AnswerView
{
public:
	void mainFun();
	TwoEquation randEquation();
	static AnswerView& getSingleton();

private:
	AnswerView();
};


#endif // !ANSWER_VIEW

