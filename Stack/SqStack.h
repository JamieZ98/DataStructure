/*
 * @Author: Jamie.Z 
 * @Date: 2021-04-20 15:58:56 
 * @Last Modified by: Jamie.Z
 * @Last Modified time: 2021-04-20 15:59:23
 */
//SqStack.h
#include <iostream>
#pragma once
#include "Stack.h"
using namespace std;

template <class ElemType>
class SqStack : public Stack<ElemType>
{
public:
	SqStack(int n);
	SqStack(const SqStack &s);
	~SqStack();
	void clear();
	void push(const ElemType &e);
	void pop();
	bool empty();
	int size();
	ElemType top();
	SqStack<ElemType> &operator=(const SqStack<ElemType> &s);

private:
	ElemType *stackbase;
	ElemType *stacktop;
	int stacksize;
	void copyfrom(const SqStack<ElemType> &s);
};

//默认构造函数
template <class ElemType>
SqStack<ElemType>::SqStack(int n)
{
	stackbase = new ElemType[n];
	stacktop = stackbase;
	stacksize = n;
}
//拷贝构造函数
template <class ElemType>
SqStack<ElemType>::SqStack(const SqStack &s)
{
	stackbase = nullptr;
	copyfrom(s);
}
template <class ElemType>
void SqStack<ElemType>::copyfrom(const SqStack<ElemType> &s)
{
	clear();
	stackbase = new ElemType[s.stacksize];
	for (int i = 0; i < s.stacksize; i++)
	{
		push(*(s.stackbase + i));
	}
	stacktop = stackbase + stacksize;
}
//析构函数
template <class ElemType>
SqStack<ElemType>::~SqStack()
{
	clear();
}
//清空栈
template <class ElemType>
void SqStack<ElemType>::clear()
{
	if (stackbase != nullptr)
	{
		delete[] stackbase;
	}
	stacktop = stackbase = nullptr;
	stacksize = 0;
}
//运算符=重载
template <class ElemType>
SqStack<ElemType> &SqStack<ElemType>::operator=(const SqStack<ElemType> &s)
{
	copyfrom(s);
	return *this;
}
//压栈
template <class ElemType>
void SqStack<ElemType>::push(const ElemType &e)
{
	if (stacktop - stackbase == stacksize)
	{
		cout << "Error: Stack OverFLow!" << endl;
		exit(0);
	}
	else
	{
		*stacktop = e;
		stacktop++;
		stacksize++;
	}
}
//出栈
template <class ElemType>
void SqStack<ElemType>::pop()
{
	if (stacktop == stackbase)
	{
		cout << "Error: BaseFlow!" << endl;
		exit(0);
	}
	else
	{
		stacksize--;
		stacktop--;
	}
}
//返回栈顶元素
template <class ElemType>
ElemType SqStack<ElemType>::top()
{
	if (stackbase == stacktop)
	{
		cout << "Error:Stack Empty!" << endl;
		exit(0);
	}
	else
	{
		return *(stacktop - 1);
	}
}
//判断是否为空
template <class ElemType>
bool SqStack<ElemType>::empty()
{
	if (stackbase == stacktop)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//返回栈的大小
template <class ElemType>
int SqStack<ElemType>::size()
{
	return stacksize;
}
