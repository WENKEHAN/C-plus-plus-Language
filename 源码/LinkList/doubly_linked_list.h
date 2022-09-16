//
// Created by HANWENKE on 2022/8/27.
//

#ifndef DOUBLY_LINKED_LIST_DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_DOUBLY_LINKED_LIST_H

#endif //DOUBLY_LINKED_LIST_DOUBLY_LINKED_LIST_H
#include <iostream>
#include <vector>
#include <random>
using  namespace  std;
template <class  _Ty>
struct Node{
    _Ty data;
    Node<_Ty> *next;
    Node<_Ty> *pre;
};
template <class _Ty>
class Doubly_Linked_List{
private:
    Node<_Ty> *head;//链表的头指针
public:
    Doubly_Linked_List();//无参构造
    Doubly_Linked_List(const _Ty *const &a, int n);//有参构造,建立有n个元素的单链表
    ~Doubly_Linked_List();//析构函数
    int length();//求单链表的长度
    Node<_Ty>* Get(int t);//按位置查找，在双链表中查找第i个结点
    int Locate(const _Ty &x);//按值查找。在单链表中查找值为x的元素序号
    void Insert(int i,const _Ty &x);//插入操作，在第i个位置后插入元素值为x的结点
    void Delete(int i);//删除单链表中第i个结点
    void Print();//遍历操作，按序号输出各个元素
};

