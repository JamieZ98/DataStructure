//MergeList.cpp
#include <iostream>
#include "List.h"
#include "Sqlist.h"

using namespace std;

//建立线性表
void Creat(List<int> *lx, int k, char c)
{
	int e;
	if (k > 0)
	{
		cout << "请顺序输入" << k << "个" << c << "表中的数据：" << endl;
		for (int i = 0; i < k; i++)
		{
			cin >> e;
			lx->Append(e);
		}
	}
}

void MergeList(List<int> *la, List<int> *lb, List<int> *lc)
{
	int i = 1, j = 1;
	int sa, sb;
	int lalen = la->Length();
	int lblen = lb->Length();
	while (i <= lalen && j <= lblen)
	{
		la->GetElem(sa, i);
		lb->GetElem(sb, j);
		if (la <= lb)
		{
			lc->Append(sa);
			i++;
		}
		else
		{
			lc->Append(sb);
			j++;
		}
	}
	while (i <= lalen)
	{
		la->GetElem(sa, i);
		lc->Append(sa);
		i++;
	}
	while (j <= lblen)
	{
		lb->GetElem(sb, j);
		lc->Append(sb);
		j++;
	}
}

void Print(const int &c)
{
	cout << c << " ";
}

int main()
{
	void Print(const int &);
	void MergeList(List<int> *, List<int> *, List<int> *);
	void Create(List<int> *, int, char);
	int n, m;
	cout << "---此程序用于合并两个有序表---" << endl;
	cout << "请输入有序表A的长度: ";
	cin >> n;
	cout << "请输入有序表B的长度: ";
	cin >> m;
	cout << "抽象类模板连接的具体类是单链表类模板，数据元素是整型" << endl
		 << endl;
	SqList<int> lal(n), lbl(m), lcl(n + m);
	Creat(&lal, n, 'A');
	cout << endl;
	Creat(&lbl, m, 'B');
	cout << endl;
	MergeList(&lal, &lbl, &lcl);
	cout << "合并后的c表为：" << endl;
	lcl.Traverse(Print);
	system("pause");
	return 0;
}
