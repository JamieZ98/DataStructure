/*
 * @Author: Jamie.Z 
 * @Date: 2021-04-20 15:58:51 
 * @Last Modified by: Jamie.Z
 * @Last Modified time: 2021-04-20 15:59:20
 */
//LinkStack.h
#include <iostream>
#pragma once
#include "Stack.h"
#include "StackNode.h"
using namespace std;

template <class ElemType>
class LinkStack : public Stack<ElemType>
{
public:
	LinkStack();
	LinkStack(const LinkStack &s);
	~LinkStack();
	void clear();
	void push(const ElemType &e);
	void pop();
	bool empty();
	int size();
	ElemType top();
	LinkStack<ElemType> &operator=(const LinkStack<ElemType> &s);

private:
	StackNode<ElemType> *stackbase;
	StackNode<ElemType> *stacktop;
	int stacksize;
	void copyfrom(const LinkStack<ElemType> &s);
};

//Ĭ�Ϲ��캯��
template <class ElemType>
LinkStack<ElemType>::LinkStack()
{
	stacktop = stackbase = nullptr;
	stacksize = 0;
}
//�������캯��
template <class ElemType>
LinkStack<ElemType>::LinkStack(const LinkStack &s)
{
	stacktop = stackbase = nullptr;
	copyfrom(s);
}
template <class ElemType>
void LinkStack<ElemType>::copyfrom(const LinkStack<ElemType> &s)
{
	clear();
	StackNode<ElemType> *sp = s.stacktop;
	while (sp)
	{
		push(sp->data);
		sp = sp->next;
	}
}
//��������
template <class ElemType>
LinkStack<ElemType>::~LinkStack()
{
	clear();
}
//���ջ
template <class ElemType>
void LinkStack<ElemType>::clear()
{
	while (stacktop)
	{
		pop();
	}
	stacktop = stackbase = nullptr;
	stacksize = 0;
}
//�����=����
template <class ElemType>
LinkStack<ElemType> &LinkStack<ElemType>::operator=(const LinkStack<ElemType> &s)
{
	copyfrom(s);
	return *this;
}
//ѹջ
template <class ElemType>
void LinkStack<ElemType>::push(const ElemType &e)
{
	StackNode<ElemType> *p = new StackNode<ElemType>;
	p->data = e;
	p->next = stacktop;
	stacktop = p;
	stacksize++;
}
//��ջ
template <class ElemType>
void LinkStack<ElemType>::pop()
{
	if (stacktop == nullptr)
	{
		cout << "Error: BaseFlow!" << endl;
		exit(0);
	}
	else
	{
		StackNode<ElemType> *p = stacktop;
		stacktop = stacktop->next;
		delete p;
		stacksize--;
	}
}
//����ջ��Ԫ��
template <class ElemType>
ElemType LinkStack<ElemType>::top()
{
	if (stacktop == nullptr)
	{
		cout << "Error:Stack Empty!" << endl;
		exit(0);
	}
	else
	{
		return stacktop->data;
	}
}
//�ж��Ƿ�Ϊ��
template <class ElemType>
bool LinkStack<ElemType>::empty()
{
	if (stacktop == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//����ջ�Ĵ�С
template <class ElemType>
int LinkStack<ElemType>::size()
{
	return stacksize;
}
