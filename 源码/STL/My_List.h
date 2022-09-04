//
// Created by HANWENKE on 2022/8/31.
//
#include <iostream>
#include <ostream>
#include <stdexcept>
//双向链表
using namespace  std;
template<class t>
class list{
private:
    //结点类
    class node{
    public:
        node(node *prev,t const &data,node *next):m_prev(prev),m_data(data),m_next(next){}
        node *m_prev;//前 指针
        t m_data;//数据区
        node *m_next;//后 指针
    };
public:
    //正向非常迭代类--迭代器本身可以改-常迭代器无法修改
    class Iterator {
    public:
        Iterator(node *start, node *cur, node *end) :m_start(start), m_cur(cur), m_end(end){}
        t &operator *(){
            if(m_cur== nullptr){
                throw underflow_error("null node");
            }
            return m_cur->m_data;
        }
        Iterator &operator++(){
            if(m_cur== nullptr){
                m_cur=m_start;
            }else{
                m_cur=m_cur->m_next;
            }
            return *this;
        }
        Iterator &operator--(){
            if(m_cur==nullptr)
                m_cur=m_end;
            else
                m_cur=m_cur->m_prev;
            return *this;
        }
        bool operator==(Iterator const &that)const{
            return m_start==that.m_start&&m_cur==that.m_cur&&m_end==that.m_end;
        }
        bool operator!=(Iterator const &that)const{
            return !(*this==that);
        }
    private:
        //开始指向
        node *m_start;
        //当前指向
        node *m_cur;
        //终止指向
        node *m_end;
        friend class list;
    };
public:
    //常迭代器
    class const_Iterator{
    private:
        Iterator m_it;
        friend class list;
    public:
        const_Iterator(Iterator const &it): m_it(it){}
        //用常引用来接收-链表就无法修改
         t const & operator *(){
            return  *m_it;
        }
        const_Iterator const &operator++(){
             ++m_it;
             return *this;
        }
        const_Iterator const &operator--(){
            --m_it;
            return *this;
        }
        bool operator==(const_Iterator const&that)const{
            return m_it==that.m_it;
        }
        bool operator!=(const_Iterator const &that)const{
            return !(*this==that.m_it);
        }
    };
private:
    node *m_head;//链表头;
    node *m_tail;//链表尾
public:
    //缺省构造
    list():m_head(nullptr),m_tail(nullptr){}
    //拷贝构造
    list(list const &that):m_head(nullptr),m_tail(nullptr){
        for(node *pnode=that.m_head;pnode!= nullptr;pnode=pnode->m_next)
            //从尾部插入-如果从头部插入-数据相反
            push_back(pnode->m_data);
    }
    //析构函数
    ~list();
    //链表判空
    bool empty();
    //添加头结点
    void push_front(t const & data);
    //删除链表头结点
    void pop_front();
    //获取头结点元素
    t &front();
    //重载--常对象调用常函数
    t const &front() const;
    //添加尾接结点
    void push_back(t const &data);
    //删除尾结点
    void pop_back();
    //获取尾结点的数据
    t &back();
    t const &back()const;
    //清空链表
    void clear();
    //获取链表的大小
    size_t size();
    //重载输出流操作符
    //friend ostream &operator<<(ostream &os,list<t>&l);
    //迭代器指向的位置添加结点
    void  insert(Iterator const &loc,t const &data);
    //迭代器指向的位置删除
    void erase(Iterator const &loc);
    //获取起始迭代器-遍历链表
    Iterator begin(){
        return Iterator(m_head,m_head,m_tail);
    }
    //获取终止迭代器--结束标志
    Iterator end(){
        return Iterator(m_head, nullptr,m_tail);
    }
    //常迭代器-修饰this指针--函数的重载
    const_Iterator begin()const{
        return Iterator(m_head,m_head,m_tail);
    }
    //获取终止常迭代器
    const_Iterator end()const{
        return Iterator(m_head,nullptr,m_tail);
    }
};