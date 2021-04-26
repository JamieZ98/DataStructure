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

//�ж��Ƿ����
bool ispalindrome(char *in_string)
{
	SqStack<char> s(MAX_STRING_LEN);
	char deblankstring[MAX_STRING_LEN], c;
	int i = 0;
	//�����ַ��ո�
	while (*in_string != '\0')
	{
		if (*in_string != ' ')
			deblankstring[i++] = *in_string;
		in_string++;
	}
	deblankstring[i] = '\0';
	//��Ч�ַ�������ջ
	i = 0;
	while (deblankstring[i] != '\0')
	{
		s.push(deblankstring[i++]);
	}
	//��ջ�е����ַ����αȽ�
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
	cout << "������һ���ַ�����" << endl;
	cin.get(instring, MAX_STRING_LEN);
	if (ispalindrome(instring))
		cout << "\"" << instring << "\""
			 << "�ǻ��ġ�" << endl;
	else
		cout << "\"" << instring << "\""
			 << "���ǻ��ġ�" << endl;
	system("pause");
	return 0;
}
