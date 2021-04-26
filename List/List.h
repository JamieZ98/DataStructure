//List.h
//以模板的形式为ADT List建立一个抽象类
#pragma once

template <class ElemType>
class List
{
public:
	//后面加个const 表明该函数不会改变成员函数的值！该函数可以被常量对象访问(const)。
	//注意 加了const 与不加const的函数是两个不同的函数！
	virtual bool IsEmpty() const = 0;//判断是否为空表
	virtual int Length() const = 0;//求表长
	virtual void Clear() = 0;//置空表
	virtual bool GetElem(ElemType&, int)const = 0;//取值
	virtual bool SetElem(const ElemType&, int) = 0;//表中存值
	virtual int LocateElem(const ElemType&)const = 0;//查找符合条件的数据元素
	virtual int LocatePrior(const ElemType&)const = 0;//查前驱
	virtual int LocateNext(const ElemType&)const = 0;//查后继
	virtual bool Insert(const ElemType&, int) = 0;//在指定位置插入值
	virtual bool Append(const ElemType&) = 0;//尾插
	virtual bool Delete(ElemType&, int i) = 0;//删值
	virtual void Traverse(void(*visit)(const ElemType&))const = 0;//遍历表
};
