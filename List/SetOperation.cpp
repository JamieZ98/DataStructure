// SetOperation.cpp
#include <iostream>
#include "LinkList.h"

using namespace std;

void print(const char &c)
{
	cout << c << " ";
}

//ʹ�����Ա�ʵ�ּ������㣨A-B��U(B-A),���ҳ��������������в�ͬԪ��
void Difference(LinkList<char> &la, LinkList<char> &lb)
{
	int i, lblen;
	lblen = lb.Length();
	//��һ����B�����ݵ�A����ң����������A��ɾ�������򣬲��뵽A��
	for (i = 1; i <= lblen; i++)
	{
		char e;
		lb.GetElem(e, i); //��������ȡֵЧ�ʽ�˳���ͣ�o(n)
		int k = la.LocateElem(e);
		if (k)
			la.Delete(e, k); //o��1��
		else
			la.Append(e); //β�壬o��1��
	}
}

//���������Ա�洢��ʾ�ļ���
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
	cout << "---�˳���ʵ�ּ�������(A-B)��(B-A)---" << endl;
	cout << "�����뼯��A��Ԫ�ظ�����" << endl;
	cin >> n;
	cout << "�����뼯��B��Ԫ�ظ�����" << endl;
	cin >> m;

	cout << "����ģ���ǵ������࣬����Ԫ���������ַ���" << endl
		 << endl;
	LinkList<char> lal, lbl;
	cout << "������" << n << "������Ԫ��������A" << endl;
	Create(lal, n);
	cout << "������" << m << "������Ԫ��������A" << endl;
	Create(lbl, m);

	Difference(lal, lbl);

	cout << "�����ļ���A�ǣ�" << endl;
	lal.Traverse(print);
	cout << endl
		 << endl;

	system("pause");
	return 0;
}
