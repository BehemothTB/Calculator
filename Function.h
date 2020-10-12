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

struct Element_
{
	double number;
	int cal;
	int bracket;
};

class Function
{
protected:
	Element* head, * pnew, * p1, * p2, * pcal;
	Element_ backup[100];
	int count;
	double min, max, x, y;
	bool IsCorrect;

public:
	Function();
	~Function();
	
	void SetElement(Element_ ele);
	void Locate();
	void Calculate();
	void LogCal();
	void PowerCal();
	void SqrtCal();
	void MultiCal();
	void DevideCal();
	void PlusCal();
	void MinusCal();
	bool GetAnswer();
	void SetSection(double min, double max);
	void LoadBackup();
	void SetElement_(Element_ ele);
};

