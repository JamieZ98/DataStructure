/*
 * @Author: Jamie.Z 
 * @Date: 2021-04-20 15:58:46 
 * @Last Modified by: Jamie.Z
 * @Last Modified time: 2021-04-20 15:59:19
 */
//BasicTest.cpp
#include <iostream>
#include "SqStack.h"
#include "LinkStack.h"
using namespace std;

int main()
{
	SqStack<int> SqS(10);
	for (int i = 0; i < 10; i++)
	{
		SqS.push(i + 1);
	}

	while (!SqS.empty())
	{

		cout << SqS.top() << " ";
		SqS.pop();
	}
	cout << endl;

	LinkStack<int> LS;
	for (int i = 0; i < 10; i++)
	{
		LS.push(i + 1);
	}

	while (!LS.empty())
	{
		cout << LS.top() << " ";
		LS.pop();
	}
	cout << endl;

	return 0;
}
