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
	
	// //����һ���µ�Ԫ��
	void SetElement(Element ele);
	// ��λ��С����λ��
	void Locate();
	void Calculate();
	void LogCal();
	void PowerCal();
};

