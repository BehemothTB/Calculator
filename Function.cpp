#include "pch.h"
#include "Function.h"

Function::Function()
{
	head = new Element;
	pnew = head;
	IsCorrect = true;
	p1 = p2 = pcal = NULL;
	x = y = 0;
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
	// TODO: 在此处添加实现代码.

	pnew->number = ele.IsX ? this->x : ele.number;
	pnew->cal = ele.cal;
	pnew->lbracket = ele.lbracket;
	pnew->rbracket = ele.rbracket;
	pnew->next = new Element;
	pold = pnew;
	pnew = pnew->next;

}


void Function::Locate()
{
	// TODO: 在此处添加实现代码.
	p1 = head;
	for (; p1->next;)
	{
		if (p1->lbracket)
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
		if (p2->lbracket)
		{
			p1 = p2;
		}
		if (p2->rbracket)
		{
			return;
		}
		p2 = p2->next;
	}

	IsCorrect = false;

}


void Function::Calculate()
{
	// TODO: 在此处添加实现代码.

	switch (pcal->cal)
	{
	case LOG:this->LogCal(); break;
	case POWER:this->PowerCal(); break;
	case SQRT:this->SqrtCal(); break;
	case COS:this->CosCal(); break;
	case SIN:this->SinCal(); break;
	case MULTI:this->MultiCal(); break;
	case DEVIDE:this->DevideCal(); break;
	case PLUS:this->PlusCal(); break;
	case MINUS:this->MinusCal(); break;
	}

	Element* pdel;
	pcal->cal = pcal->next->cal;
	pdel = pcal->next;
	pcal->next = pcal->next->next;
	delete pdel;

}


void Function::LogCal()
{
	// TODO: 在此处添加实现代码.

	if (pcal->number < 0 || pcal->next->number < 0 || pcal->next->number == 1)
	{
		IsCorrect = false;
		return;
	}

	pcal->number = log(pcal->next->number) / log(pcal->number);

}


void Function::PowerCal()
{
	// TODO: 在此处添加实现代码.

	pcal->number = pow(pcal->number, int(pcal->next->number));

}


void Function::SqrtCal()
{
	// TODO: 在此处添加实现代码.

	if (pcal->next->number < 0)
	{
		IsCorrect = false;
		return;
	}

	pcal->number = sqrt(pcal->next->number);

}


void Function::MultiCal()
{
	// TODO: 在此处添加实现代码.

	pcal->number *= pcal->next->number;

}


void Function::DevideCal()
{
	// TODO: 在此处添加实现代码.

	if (pcal->next->number == 0)
	{
		IsCorrect = false;
		return;
	}

	pcal->number /= pcal->next->number;

}


void Function::PlusCal()
{
	// TODO: 在此处添加实现代码.

	pcal->number += pcal->next->number;

}


void Function::MinusCal()
{
	// TODO: 在此处添加实现代码.

	pcal->number -= pcal->next->number;

}


bool Function::GetAnswer()
{
	// TODO: 在此处添加实现代码.

	for (; head->next;)
	{
		this->Locate();
		if (IsCorrect == false)
		{
			return false;
		}

		for (int cal = LOG; cal <= PLUS; cal++)
		{
			for (pcal = p1; pcal != p2; pcal = pcal->next)
			{
				if (pcal->cal == cal)
				{
					int rb = 0;
					if (pcal->next == p2)
					{
						p2 = pcal;
						rb = p2->rbracket;
					}
					this->Calculate();
					if (IsCorrect == false)
					{
						return false;
					}
					if (p2 == pcal)
					{
						pcal->rbracket = rb;
						break;
					}
				}
			}
		}

		p1->lbracket--;
		p2->rbracket--;

	}

	y = head->number;

	return true;

}


void Function::LoadBackup()
{
	// TODO: 在此处添加实现代码.

	pnew = head;
	for (int i = 0; i < count; i++)
	{
		this->SetElement(backup[i]);
	}
	delete pnew;
	pold->next = NULL;
}


void Function::SetElement_(Element_ ele)
{
	// TODO: 在此处添加实现代码.

	backup[count].number = ele.number;
	backup[count].cal = ele.cal;
	backup[count].lbracket = ele.lbracket;
	backup[count].rbracket = ele.rbracket;
	backup[count].IsX = ele.IsX;
	count++;

}


void Function::CosCal()
{
	// TODO: 在此处添加实现代码.

	pcal->number = cos(pcal->next->number);

}


void Function::SinCal()
{
	// TODO: 在此处添加实现代码.

	pcal->number = sin(pcal->next->number);

}


void Function::LoadText(const char* text)
{
	// TODO: 在此处添加实现代码.

	Element_ ele;
	ele.number = 0;
	ele.cal = -1;
	ele.lbracket = 0;
	ele.rbracket = 0;
	ele.IsX = false;

	for (int i = 0;; i++)
	{
		switch (*(text + i))
		{
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':ele.number = ele.number * 10 + *(text + i) - '0'; break;
		case 'L':ele.cal = LOG; break;
		case '^':ele.cal = POWER; break;
		case '#':ele.cal = SQRT, ele.number = 0, ele.IsX = false; break;
		case 'C':ele.cal = COS, ele.number = 0, ele.IsX = false; break;
		case 'S':ele.cal = SIN, ele.number = 0, ele.IsX = false; break;
		case '/':ele.cal = DEVIDE; break;
		case '*':ele.cal = MULTI; break;
		case '-':ele.cal = MINUS; break;
		case '+':ele.cal = PLUS; break;
		case '(':ele.lbracket++; break;
		case ')':ele.rbracket++; break;
		case 'X':ele.number = 0, ele.IsX = true; break;
		case '\0':ele.cal = EQUAL; break;
		default:this->IsCorrect = false;
		}

		if (ele.cal != -1)
		{
			this->SetElement_(ele);
			if (ele.cal == EQUAL)
			{
				break;
			}
			ele.number = 0;
			ele.cal = -1;
			ele.lbracket = 0;
			ele.rbracket = 0;
			ele.IsX = false;
		}

	}

}
