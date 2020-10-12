#include "pch.h"
#include "Function.h"

Function::Function()
{
	head = new Element;
	pnew = head;
	IsCorrect = true;
	
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

// //����һ���µ�Ԫ��
void Function::SetElement(Element ele)
{
	// TODO: �ڴ˴����ʵ�ִ���.

	pnew->number = ele.number;
	pnew->cal = ele.cal;
	pnew->bracket = ele.bracket;
	pnew->next = new Element;
	pnew = pnew->next;

}


// ��λ��С����λ��
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

	}

}


void Function::LogCal()
{
	// TODO: �ڴ˴����ʵ�ִ���.

	pcal->number = log(pcal->next->number) / log(pcal->number);
	pcal->cal = pcal->next->cal;
	pcal->next = pcal->next->next;

}


void Function::PowerCal()
{
	// TODO: �ڴ˴����ʵ�ִ���.

	pcal->number = pow(pcal->number, int(pcal->next->number));
	pcal->cal = pcal->next->cal;
	pcal->next = pcal->next->next;

}
