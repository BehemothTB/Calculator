#include "pch.h"
#include "Function.h"

Function::Function()
{
	head = new Element;
	pnew = head;
	IsCorrect = true;
	p1 = p2 = pcal = NULL;
	max = min = x = y = 0;
	count = 0;
}

Function::~Function()
{
	p1 = head;
	for (;p1;)
	{
		p2 = p2->next;
		delete p1;
		p1 = p2;
	}
}


void Function::SetElement(Element_ ele)
{
	// TODO: �ڴ˴����ʵ�ִ���.

	pnew->number = ele.number;
	pnew->cal = ele.cal;
	pnew->bracket = ele.bracket;
	pnew->next = new Element;
	pnew = pnew->next;

}


void Function::Locate()
{
	// TODO: �ڴ˴����ʵ�ִ���.
	p1 = head;
	for (;p1->next;)
	{
		if (p1->bracket == LBRACKET)
		{
			p2 = p1->next;
			goto loop;
		}
		p1 = p1->next;
	}

	p2 = p1;
	p1 = head;
	return;

loop:
	for (; p2;)
	{
		if (p2->bracket == LBRACKET)
		{
			p1 = p2;
		}
		else if (p2->bracket == RBRACKET)
		{
			return;
		}
		p2 = p2->next;
	}

	IsCorrect = false;

}


void Function::Calculate()
{
	// TODO: �ڴ˴����ʵ�ִ���.

	switch (pcal->cal)
	{
	case LOG:this->LogCal();
	case POWER:this->PowerCal();
	case SQRT:this->SqrtCal();
	case MULTI:this->MultiCal();
	case DEVIDE:this->DevideCal();
	case PLUS:this->PlusCal();
	case MINUS:this->MinusCal();
	}

	Element* pdel;
	pcal->cal = pcal->next->cal;
	pdel = pcal->next;
	pcal->next = pcal->next->next;
	delete pdel;

}


void Function::LogCal()
{
	// TODO: �ڴ˴����ʵ�ִ���.

	if (pcal->number < 0 || pcal->next->number < 0 || pcal->next->number == 1)
	{
		IsCorrect = false;
		return;
	}

	pcal->number = log(pcal->next->number) / log(pcal->number);

}


void Function::PowerCal()
{
	// TODO: �ڴ˴����ʵ�ִ���.

	pcal->number = pow(pcal->number, int(pcal->next->number));

}


void Function::SqrtCal()
{
	// TODO: �ڴ˴����ʵ�ִ���.

	if (pcal->next->number < 0)
	{
		IsCorrect = false;
		return;
	}

	pcal->number = sqrt(pcal->next->number);

}


void Function::MultiCal()
{
	// TODO: �ڴ˴����ʵ�ִ���.

	pcal->number *= pcal->next->number;

}


void Function::DevideCal()
{
	// TODO: �ڴ˴����ʵ�ִ���.

	if (pcal->next->number == 0)
	{
		IsCorrect = false;
		return;
	}

	pcal->number /= pcal->next->number;

}


void Function::PlusCal()
{
	// TODO: �ڴ˴����ʵ�ִ���.

	pcal->number += pcal->next->number;

}


void Function::MinusCal()
{
	// TODO: �ڴ˴����ʵ�ִ���.

	pcal->number -= pcal->next->number;

}


bool Function::GetAnswer()
{
	// TODO: �ڴ˴����ʵ�ִ���.

	for (; head->next;)
	{
		this->Locate();
		if (IsCorrect == false)
		{
			return false;
		}

		for (int cal = LOG; cal <= MINUS; cal++)
		{
			for (pcal = p1; pcal != p2; pcal = pcal->next)
			{
				if (pcal->cal == cal)
				{
					if (pcal->next == p2)
					{
						p2 = pcal;
					}
					this->Calculate();
					if (IsCorrect == false)
					{
						return false;
					}
					if (p2 == pcal)
					{
						pcal->bracket = RBRACKET;
						break;
					}
				}
			}
		}

		p1->bracket = NBRACKET;
		p2->bracket = NBRACKET;

	}

	y = head->number;

	return true;

}


void Function::SetSection(double min, double max)
{
	// TODO: �ڴ˴����ʵ�ִ���.

	this->min = min;
	this->max = max;

}


void Function::LoadBackup()
{
	// TODO: �ڴ˴����ʵ�ִ���.

	pnew = head;
	for (int i = 0; i < count; i++)
	{
		this->SetElement(backup[i]);
	}

}


void Function::SetElement_(Element_ ele)
{
	// TODO: �ڴ˴����ʵ�ִ���.

	backup[count].number = ele.number;
	backup[count].cal = ele.cal;
	backup[count].bracket = ele.bracket;
	count++;

}
