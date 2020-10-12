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

// //设置一个新的元素
void Function::SetElement(Element ele)
{
	// TODO: 在此处添加实现代码.

	pnew->number = ele.number;
	pnew->cal = ele.cal;
	pnew->bracket = ele.bracket;
	pnew->next = new Element;
	pnew = pnew->next;

}


// 定位最小括号位置
void Function::Locate()
{
	// TODO: 在此处添加实现代码.
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
	// TODO: 在此处添加实现代码.

	switch (pcal->cal)
	{

	}

}


void Function::LogCal()
{
	// TODO: 在此处添加实现代码.

	pcal->number = log(pcal->next->number) / log(pcal->number);
	pcal->cal = pcal->next->cal;
	pcal->next = pcal->next->next;

}


void Function::PowerCal()
{
	// TODO: 在此处添加实现代码.

	pcal->number = pow(pcal->number, int(pcal->next->number));
	pcal->cal = pcal->next->cal;
	pcal->next = pcal->next->next;

}
