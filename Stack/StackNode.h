/*
 * @Author: Jamie.Z 
 * @Date: 2021-04-20 15:59:05 
 * @Last Modified by: Jamie.Z
 * @Last Modified time: 2021-04-20 15:59:27
 */
//StackNode.h
#pragma once
template <class ElemType>
struct StackNode
{
	ElemType data;
	StackNode *next;
};