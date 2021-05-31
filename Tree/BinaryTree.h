/*
 * @Author: Jamie.Z 
 * @Date: 2021-05-07 04:16:47 
 * @Last Modified by: Jamie.Z
 * @Last Modified time: 2021-05-07 04:24:47
 */
//BinaryTree.h
#pragma once

template <typename T>
class BinaryTree
{ //二叉树类型
public:
    bool IsEmpty();             //判断BT是否为空
    void PreOrderTraversal();   //先序遍历
    void InOrderTraversal();    //中序遍历
    void PostOrderTraversal();  //后序遍历
    void LevelOrderTraversal(); //层次遍历，从上到下从左到右
    
};