#pragma once

#include "Marcros.h"
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
	bool IsX;
};

class Function
{
protected:
	Element* head, * pnew, * pold, * p1, * p2, * pcal;
	Element_ backup[100];
	int count;
	double x, y;
	bool IsCorrect;

public:
	Function();
	~Function();

	friend class CCalculatorDlg;
	
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
	void LoadBackup();
	void SetElement_(Element_ ele);
	void CosCal();
	void SinCal();
	void LoadText(const char* text);
};

