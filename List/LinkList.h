//LinkList.h
#pragma once
#include "List.h"
#include "ListNode.h"

template <class ElemType>
class LinkList:public List<ElemType>
{
public:
	LinkList();
	LinkList(const LinkList<ElemType>&);
	~LinkList();
	bool IsEmpty()const { return len <= 0; }
	int Length()const { return len; }
	void Clear();
	bool GetElem(ElemType&, int)const;
	bool SetElem(const ElemType&, int);
	int LocateElem(const ElemType&)const;
	int LocatePrior(const ElemType&)const;
	int LocateNext(const ElemType&)const;
	bool Insert(const ElemType&, int);
	bool Append(const ElemType&);
	bool Delete(ElemType&, int);
	void Traverse(void(*visit)(const ElemType&))const;
	LinkList<ElemType>& operator=(const LinkList<ElemType>&);

private:
	int len;
	ListNode<ElemType>* head;
	ListNode<ElemType>* tail;
	void CopyFrom(const LinkList<ElemType>&);
};

template<class ElemType>
LinkList<ElemType>::LinkList()
{
	len = 0;
	head = tail = new ListNode<ElemType>;
	head->next = NULL;
}

template<class ElemType>
LinkList<ElemType>::LinkList(const LinkList<ElemType>& r)
{
	CopyFrom(r);
}

//从现有单链表拷贝构造出一个单链表
template<class ElemType>
LinkList<ElemType>::~LinkList()
{
	Clear();
	delete head; //释放头结点
}

//释放所有数据节点
template<class ElemType>
void LinkList<ElemType>::Clear()
{
	ListNode<ElemType>* p = head->next, * q;
	while (p)
	{
		q = p->next;
		delete p;
		p = q;
	}
	tail = head;
	head->next = NULL;
	len = 0;
}

template<class ElemType>
bool LinkList<ElemType>::GetElem(ElemType& e, int i) const
{
	if (i<1 || i>len)
		return false;
	ListNode<ElemType>* p = head->next;
	int k = 1;
	while (k<i)
	{
		p = p->next;
		k++;
	}
	e = p->data;
	return true;
}

template<class ElemType>
bool LinkList<ElemType>::SetElem(const ElemType& e, int i)
{
	if (i<1 || i>len)
		return false;
	ListNode<ElemType>* p = head->next;
	int k = 1;
	while (k<i)
	{
		p = p->next;
		k++;
	}
	p->data = e;
	return true;
}

//要考虑表中无p的情况
template<class ElemType>
int LinkList<ElemType>::LocateElem(const ElemType& e) const
{
	ListNode<ElemType>* p = head->next;
	int i = 1;
	while (p && p -> data != e)
	{
		p = p->next;
		i++;
	}
	if (p)
		return i;
	else
		return 0;
}

template<class ElemType>
int LinkList<ElemType>::LocatePrior(const ElemType& e) const
{
	int i = LocateElem(e);
	if (i > 1)
		return i - 1;
	return 0;
}

template<class ElemType>
int LinkList<ElemType>::LocateNext(const ElemType& e) const
{
	int i = LocateElem(e);
	if (i && i < len)
		return i + 1;
	return 0;
}

//前插，共len+1个空位
template<class ElemType>
bool LinkList<ElemType>::Insert(const ElemType& e, int i)
{
	if (i < 1 || i > len + 1)
		return false;
	ListNode<ElemType>* p, * q;
	int k = 1;
	q = new ListNode<ElemType>;
	q->data = e;
	//将p指针定位在i-1的位置上
	p = head;
	while (k<i)
	{
		p = p->next;
		k++;
	}
	q->next = p->next;
	p->next = q;

	if (i == len + 1)
		tail = q;
	++len;
	return true;
}

template<class ElemType>
bool LinkList<ElemType>::Append(const ElemType& e)
{
	ListNode<ElemType>* q;
	q = new ListNode<ElemType>;
	q->data = e;
	tail->next = q;
	tail = q;
	tail->next = NULL;
	++len;
	return true;
}

//删除第i个数据，并用e返回其值
template<class ElemType>
bool LinkList<ElemType>::Delete(ElemType& e, int i)
{
	if (i<1 || i>len)
		return false;
	ListNode<ElemType>* p, * q;
	p = head;
	int k = 1;
	while (k<i)
	{
		p = p->next;
		k++;
	}
	q = p->next;
	p->next = q->next;
	
	if (q == tail)
		tail = p;
	e = q->data;
	delete q;
	--len;
	return true;
}

template<class ElemType>
LinkList<ElemType>& LinkList<ElemType>::operator=(const LinkList<ElemType>& r)
{
	Clear();
	delete head;
	CopyFrom(r);
	return *this;//返回当前对象本身
}

template<class ElemType>
void LinkList<ElemType>::CopyFrom(const LinkList<ElemType>& r)
{
	len = 0;
	head = tail = new ListNode<ElemType>;
	head->next = NULL;
	ListNode<ElemType>* p = r.head->next;
	while (p)
	{
		Append(p->data);
		p = p->next;
	}
}

template<class ElemType>
void LinkList<ElemType>::Traverse(void(*visit)(const ElemType& r)) const
{
	ListNode<ElemType>* p = head->next;
	while (p)
	{
		visit(p->data);
		p = p->next;
	}
}

