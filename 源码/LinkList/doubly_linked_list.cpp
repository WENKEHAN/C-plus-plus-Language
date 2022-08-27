//
// Created by HANWENKE on 2022/8/27.
//

#include "doubly_linked_list.h"

template<class _Ty>
Doubly_Linked_List<_Ty>::Doubly_Linked_List() {
    head=new Node<_Ty>;
    head->next= nullptr;
    head->pre= nullptr;
}

template<class _Ty>
//双向链表--头插有参构造
Doubly_Linked_List<_Ty>::Doubly_Linked_List( const _Ty *const &a, int n) {
    head=new Node<_Ty>;
    head->next= nullptr;
    head->pre= nullptr;
    for(int i=0;i<n;i++){
        if(head->next== nullptr){
            auto *s=new Node<_Ty>;
            s->data=a[i];
            s->pre=head;
            s->next=head->next;
            head->next=s;
        }else{
            auto *s=new Node<_Ty>;
            s->data=a[i];
            s->pre=head;
            s->next=head->next;
            head->next->pre=s;
            head->next=s;
        }
    }
}

template<class _Ty>
Doubly_Linked_List<_Ty>::~Doubly_Linked_List() {
    Node<_Ty> *p=head->next;
    Node<_Ty> *q=p;
    while(p){
        q=p->next;
        delete p;
        p=q->next;
    }
    delete head;
    p= nullptr;
    q= nullptr;
    head= nullptr;
}

template<class _Ty>
int Doubly_Linked_List<_Ty>::length() {
    Node<_Ty> *p;
    p=head->next;
    int count=0;
    while (p){
        ++count;
        p=p->next;
    }
    return count;
}
template<class _Ty>
//按位置查找
Node<_Ty>* Doubly_Linked_List<_Ty>::Get(int t) {
    Node<_Ty> *p=head->next;
    int count=1;
    while(p&&count<t){
        p=p->next;
        count++;
    }
    if (p == nullptr){
        cout<<"位置异常"<<endl;
        return nullptr;
    }
    else
        return p;

}
//按值查找--如果找到返回元素的序号，如果查找不成功返回0表示失败
template<class _Ty>
int Doubly_Linked_List<_Ty>::Locate(const _Ty &x) {
    Node<_Ty> *p=head->next;
    int count=1;
    while(p){
        if(p->data==x) return count;
        p=p->next;
        count++;
    }
    return 0;
}

template<class _Ty>
void Doubly_Linked_List<_Ty>::Insert(int i, const _Ty &x) {
    Node<_Ty> *temp= Get(i);
    auto *newNode=new Node<_Ty>;
    newNode->data=x;
    newNode->pre=temp;
    newNode->next=temp->next;
    temp->next->pre=newNode;
    temp->next=newNode;

}

template<class _Ty>
void  Doubly_Linked_List<_Ty>::Delete(int i) {
    if(i<0||i>length()){
        cout<<"删除位置不合法"<<endl;
        return;
    }
    auto temp= Get(i);
    temp->pre->next=temp->next;
    temp->next->pre=temp->pre;
    delete temp;
    temp= nullptr;
}

template<class _Ty>
/*遍历操作：
 * 临时结点指向第一个结点
 * 重复执行以下操作，直到p为空：
 *  输出结点p的数据域
 *  指针后移*/
void Doubly_Linked_List<_Ty>::Print() {
    Node<_Ty> *p=head->next;
    while(p!= nullptr){
        cout<<p->data<<"  ";
        p=p->next;
    }
    cout<<endl;
}
int main(){
    vector<char>res(20);
    for (int i = 0; i < res.size(); i++)
        res[i]=i+'A';

    Doubly_Linked_List<char> l(&res[0],res.size());
    l.Print();
    cout<<l.length()<<endl;

    //cout<<l.Get(100)->data<<endl;

    l.Insert(0,'W');
    l.Print();
    l.Delete(3);
    l.Print();
    return 0;
}
