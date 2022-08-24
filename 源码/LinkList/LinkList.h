//
// Created by HANWENKE on 2022/8/20.
//
#ifndef CLION_LINKLIST_H
#define CLION_LINKLIST_H
#include <iostream>
using  namespace  std;
struct Node {
public:
    //数据域
    int data;
    //next域
    Node *next;

    Node() : data(0), next(nullptr) {}

    Node(int  x) : data(x), next(nullptr) {}

    Node(int  x, Node *next) : data(x), next(nullptr) {}
};
class LinkList {
public:
        Node *head;//链表头结点'
        LinkList(){head= nullptr;}//构造函数
        ~LinkList(){DeleteAll();}//析构函数
        void InitList();;//链表初始化
        void DeleteAll();//删除所有结点
        void HeadCreat(int n);//头插法建立单链表
        void TailCreate(int n);//尾插法建立单链表
        int Length();//获取单链表的长度
        Node *GetT(const int &x);//查找值为x的元素
        Node *GetIndex(const int  &i);//查找第i个元素
        bool Insert(const int val,int i);//在第i个位置插入val;
        bool Delete(const int &val);//删除链表中值为val的结点
        void Print();//打印链表
};
#endif //CLION_LINKLIST_H
