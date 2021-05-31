//SqList.h
#pragma once
#include "List.h"

template <class ElemType>
class SqList : public List<ElemType>
{
public:
	SqList(int m = 0);
	SqList(const SqList<ElemType> &);
	~SqList();
	bool IsEmpty() const { return len <= 0; } //len<=0时返回true
	int Length() const { return len; }
	void Clear() { len = 0; } //置线性表为空表
	bool GetElem(ElemType &, int) const;
	bool SetElem(const ElemType &, int);
	int LocateElem(const ElemType &) const;
	int LocatePrior(const ElemType &) const;
	int LocateNext(const ElemType &) const;
	bool Insert(const ElemType &, int);
	bool Append(const ElemType &);
	bool Delete(ElemType &, int);
	void Traverse(void (*visit)(const ElemType &)) const;
	SqList<ElemType> &operator=(const SqList<ElemType> &);

private:
	int len;
	int size;
	ElemType *elem; //基地址指针
	void CopyFrom(const SqList<ElemType> &);
};

//初始化顺序表
template <class ElemType>
SqList<ElemType>::SqList(int m)
{
	len = 0;
	if (0 == m)
		elem = nullptr;
	else
		elem = new ElemType[m];
	size = m;
}

//复制构造函数
template <class ElemType>
SqList<ElemType>::SqList(const SqList<ElemType> &r)
{
	len = 0;
	size = 0;
	elem = nullptr;
	CopyFrom(r);
}

//析构函数
template <class ElemType>
SqList<ElemType>::~SqList()
{
	delete[] elem;
}

//表中取值
template <class ElemType>
bool SqList<ElemType>::GetElem(ElemType &e, int i) const
{
	if (i < 1 || i > len)
		return false;
	e = elem[i - 1];
	return true;
}

//表中存值
template <class ElemType>
bool SqList<ElemType>::SetElem(const ElemType &e, int i)
{
	if (i < 1 || i > len)
		return false;
	elem[i - 1] = e;
	return true;
}

//按数据元素查值
template <class ElemType>
int SqList<ElemType>::LocateElem(const ElemType &e) const
{
	ElemType *p = elem;
	int i = 1;
	while (i < len && *p != e)
	{
		p++;
		i++;
	}
	if (i <= len)
		return i;
	return 0;
}

//查某数据元素前驱
template <class ElemType>
int SqList<ElemType>::LocatePrior(const ElemType &e) const
{
	ElemType *p = elem;
	int i = 1;
	while (i < len && *p != e)
	{
		p++;
		i++;
	}
	if (i > 1 && i <= len)
		return i - 1;
	return 0;
}

//查某数据元素后继
template <class ElemType>
int SqList<ElemType>::LocateNext(const ElemType &e) const
{
	ElemType *p = elem;
	int i = 1;
	while (i < len && *p != e)
	{
		p++;
		i++;
	}
	if (i >= 1 && i < len)
		return i + 1;
	return 0;
}

//在指定位置插入数据元素
template <class ElemType>
bool SqList<ElemType>::Insert(const ElemType &e, int i)
{
	if (i < 1 || i > len)
		return false;
	if (len >= size)
	{
		ElemType *newbase;
		newbase = new ElemType[size + 10];
		if (!newbase)
			return false;
		for (int j = 0; j < len; j++)
			newbase[j] = elem[j];
		delete[] elem;
		elem = newbase;
		size += 10;
	}

	ElemType *p, *q;
	q = &elem[i - 1]; //将elem[i-1]的地址赋给q
	for (p = &elem[len - 1]; p >= q; --p)
		*(p + 1) = *p;
	*q = e;
	++len;
	return true;
}

//在顺序表尾插入值
template <class ElemType>
bool SqList<ElemType>::Append(const ElemType &e)
{
	ElemType *newbase;
	if (len >= size)
	{
		newbase = new ElemType[size + 10];
		if (!newbase)
			return false;
		for (int j = 0; j < len; j++)
			newbase[j] = elem[j];
		delete[] elem;
		elem = newbase;
		size += 10;
	}
	elem[len++] = e;
	return true;
}

//删除指定位置数据元素，并返回其值
template <class ElemType>
bool SqList<ElemType>::Delete(ElemType &e, int i)
{
	if (i < 1 || i > len)
		return false;
	ElemType *p;
	p = &elem[i - 1];
	e = *p;
	for (p += 1; p <= &elem[len - 1]; ++p)
		*(p - 1) = *p;
	len--;
	return true;
}

//重载“=”
template <class ElemType>
SqList<ElemType> &SqList<ElemType>::operator=(const SqList<ElemType> &r)
{
	Clear();
	CopyFrom(r);
	return *this;
}

//从现有一个顺序表中复制所有元素
template <class ElemType>
void SqList<ElemType>::CopyFrom(const SqList<ElemType> &r)
{
	ElemType *p = r.elem;
	for (int i = 0; i < r.len; i++)
		Append(*p++);
}

//依次对顺序表每个元素调用一次visit()函数
template <class ElemType>
void SqList<ElemType>::Traverse(void (*visit)(const ElemType &e)) const
{
	ElemType *p = elem;
	for (int i = 0; i < len; i++)
		visit(*p++);
}
