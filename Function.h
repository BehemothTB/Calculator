#pragma once

#include "pch.h"
#include <cmath>

struct Element
{
	double number;
	int cal;
	int bracket;
	Element* next;
};

class Function
{
protected:
	Element* head, * pnew, * p1, * p2, * pcal;
	double min, max, x, y;
	bool IsCorrect;

public:
	Function();
	~Function();
	
	// //设置一个新的元素
	void SetElement(Element ele);
	// 定位最小括号位置
	void Locate();
	void Calculate();
	void LogCal();
	void PowerCal();
};

