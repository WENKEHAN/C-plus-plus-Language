//
// Created by HANWENKE on 2022/8/25.
//

#ifndef CIRCULAR_LINKED_LIST_CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_CIRCULAR_LINKED_LIST_H

#endif //CIRCULAR_LINKED_LIST_CIRCULAR_LINKED_LIST_H
#include <iostream>
using namespace  std;
class Node{
public:
    int  data;
    Node *next;
    Node ():data(0),next(nullptr){};
    Node (const int &val):data(val),next(nullptr){};
};
class Circular_Linked_list {
public:
    Node  *head;
    void InitList();//链表的初始话
    Circular_Linked_list(){head= nullptr;}//构造函数
    ~Circular_Linked_list(){//析构函数
        DeleteAll();
    }
    void DeleteAll();//删除所有结点
    void HearCreate(const int &val);//头插法建立单链表
    void TailCreate(const int &val);//尾插法建立单链表
    int  length();//求单链表的长度
    Node  *Findval(const int &val);//查找值为val的元素并返回其结点
    Node * Get(const int &i);//获取第i个位置的结点
    bool Insert(const int &val,int i);//在第i个位置前插入x
    void Delete(const int &i);//删除第i个位置的结点
    void Print();//打印链表
};

