/*
 * @Author: Jamie.Z 
 * @Date: 2021-04-20 15:59:02 
 * @Last Modified by: Jamie.Z
 * @Last Modified time: 2021-04-20 15:59:25
 */
//Stack.h
//以模板的形式为ADT Stack建立一个抽象类
#pragma once

template <class ElemType>
class Stack
{
public:
	virtual void push(const ElemType &e) = 0;
	virtual void pop() = 0;
	virtual ElemType top() = 0;
	virtual bool empty() = 0;
	virtual int size() = 0;
	virtual ~Stack() = 0;
};
template <class ElemType>
Stack<ElemType>::~Stack() {}