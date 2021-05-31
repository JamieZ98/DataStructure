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
{ //����������
public:
    bool IsEmpty();             //�ж�BT�Ƿ�Ϊ��
    void PreOrderTraversal();   //�������
    void InOrderTraversal();    //�������
    void PostOrderTraversal();  //�������
    void LevelOrderTraversal(); //��α��������ϵ��´�����
    
};