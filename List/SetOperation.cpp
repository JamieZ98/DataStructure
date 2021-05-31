// SetOperation.cpp
#include "LinkList.h"
#include <iostream>

using namespace std;

void print(const char &c)
{
	cout << c << " ";
}

//使用线性表实现集合运算（A-B）U(B-A),即找出两个集合中所有不同元素
void Difference(LinkList<char> &la, LinkList<char> &lb)
{
	int i, lblen;
	lblen = lb.Length();
	//逐一读入B表数据到A表查找，若存在则从A表删除，否则，插入到A表
	for (i = 1; i <= lblen; i++)
	{
		char e;
		lb.GetElem(e, i); //单链表中取值效率较顺序表低，o(n)
		int k = la.LocateElem(e);
		if (k)
			la.Delete(e, k); //o（1）
		else
			la.Append(e); //尾插，o（1）
	}
}

//建立以线性表存储表示的集合
void Create(LinkList<char> &la, const int &k)
{
	char e;
	for (int i = 0; i < k; i++)
	{
		cin >> e;
		la.Append(e);
	}
}

int main()
{
	int n, m;
	cout << "---此程序实现集合运算(A-B)∪(B-A)---" << endl;
	cout << "请输入集合A中元素个数：" << endl;
	cin >> n;
	cout << "请输入集合B中元素个数：" << endl;
	cin >> m;

	cout << "解题模板是单链表类，数据元素类型是字符型" << endl
		 << endl;
	LinkList<char> lal, lbl;
	cout << "请输入" << n << "个数据元素至集合A" << endl;
	Create(lal, n);
	cout << "请输入" << m << "个数据元素至集合A" << endl;
	Create(lbl, m);

	Difference(lal, lbl);

	cout << "运算后的集合A是：" << endl;
	lal.Traverse(print);
	cout << endl
		 << endl;

	system("pause");
	return 0;
}
