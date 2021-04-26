/*
 * @Author: Jamie.Z 
 * @Date: 2021-04-20 15:58:54 
 * @Last Modified by: Jamie.Z
 * @Last Modified time: 2021-04-20 15:59:22
 */
// Palindrome.cpp
#include <iostream>
#include "SqStack.h"

using namespace std;

#define MAX_STRING_LEN 100

//判断是否回文
bool ispalindrome(char *in_string)
{
	SqStack<char> s(MAX_STRING_LEN);
	char deblankstring[MAX_STRING_LEN], c;
	int i = 0;
	//过滤字符空格
	while (*in_string != '\0')
	{
		if (*in_string != ' ')
			deblankstring[i++] = *in_string;
		in_string++;
	}
	deblankstring[i] = '\0';
	//有效字符依次入栈
	i = 0;
	while (deblankstring[i] != '\0')
	{
		s.push(deblankstring[i++]);
	}
	//从栈中弹出字符依次比较
	i = 0;
	while (!s.empty())
	{
		c = s.top();
		s.pop();
		if (c != deblankstring[i])
			return false;
		i++;
	}
	return true;
}

int main()
{
	char instring[MAX_STRING_LEN];
	cout << "请输入一个字符串：" << endl;
	cin.get(instring, MAX_STRING_LEN);
	if (ispalindrome(instring))
		cout << "\"" << instring << "\""
			 << "是回文。" << endl;
	else
		cout << "\"" << instring << "\""
			 << "不是回文。" << endl;
	system("pause");
	return 0;
}
