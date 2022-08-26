//
// Created by HANWENKE on 2022/8/25.
//
#include "Circular_Linked_List.h"

//初始化单链表
void Circular_Linked_list::InitList() {
    DeleteAll();
    head= nullptr;
    //创建一个虚拟的头结点
    head=new Node();
}
//清除单链表
void Circular_Linked_list::DeleteAll() {
    Node *p=head;
    Node *q=head;
    while(p){
        q=p->next;
        delete p;
        p=q;
    }
    head= nullptr;
}
void Circular_Linked_list::HearCreate(const int &val) {
    //头插法建立单链表
    Node * s=new Node(val);
    Node *pre= nullptr;
    //头插法--第一个插入的结点的next=head
    //之后插入的时候-就需要让head->next=s;
    //而让新结点的next指向  head->next  所以要保存新结点的next
    if(head->next!= nullptr){
        pre=head->next;
        head->next=s;
        s->next=pre;
    }else{
        s->next=head;
        head->next=s;
    }
}
void Circular_Linked_list::TailCreate(const int &val) {
   Node *p=head->next;
   if(p){
       Node *temp=Get(length());
       Node *s=new Node(val);
       //之前的最后一个结点的next指向新的结点
       temp->next=s;
       //新结点的next指向head;
       s->next=head;
   }else{
       Node *s=new Node(val);
       head->next=s;
       s->next=head;
   }
}

int Circular_Linked_list::length() {
    Node *p=head->next;
    int count=0;
    //因为时循环单链表--尾结点的next指向头结点--所以时p!=head;
    while(p!=head){
        count++;
        p=p->next;
    }
    return count;
}

Node  *Circular_Linked_list::Findval(const int &val) {
    Node *p=head->next;
    if(p== nullptr){
        return nullptr;
    }
    //并且要判断p是否是回到了头节点--如果回到头节点说明没有找到
    while(p->data!=val&&p!=head){
        p=p->next;
    }
    //如果p等于head说明没找到返回null，否则返回具体的结点
    return p==head? nullptr:p;

}

Node* Circular_Linked_list::Get(const int &i) {
    Node *p=head->next;
    int temp=i;
    while(--temp&&p!=head){
        p=p->next;
    }
    return p;
}
//在第i个位置后插入值为val 的元素-首先判断其位置是否合法
bool Circular_Linked_list::Insert(const int &val, int i) {
    if(i<0||i>length()+1){
        cout<<"插入位置不合法"<<endl;
        return false;
    }
    //如果第0个位置就是头插，直接调用头插方法
    if(i==0){
        HearCreate(val);
        return true;
        //如果等于length就是尾插
    }else if(i==length()){
        TailCreate(val);
        return true;
    }else{
        Node *temp= Get(i);
        Node *s=new Node(val);
        s->next=temp->next;
        temp->next=s;
        return true;
    }
    return false;
}

void Circular_Linked_list::Print() {
    Node *p=head->next;
    while(p!=head){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
//删除第i个位置的结点
void Circular_Linked_list::Delete(const int &i) {
    if(i<0||i>length()){
        cout<<"删除位置不合法"<<endl;
        return ;
    }
    //获取第i个位置的前一个结点
    Node *temp= Get(i-1);
    //要删除的结点
    Node *p=temp->next;
    //前一个结点的next指向当前结点的next
    temp->next=p->next;
    delete p;
    p= nullptr;
}

int main(){
    Circular_Linked_list l;
    l.InitList();
    for(int i=10;i>0;i--){
        //l.HearCreate(i+100);
        l.TailCreate(i+10);
    }
    l.Print();
    cout<<l.length()<<endl;
    Node *temp=l.Get(l.length());
    cout<<"最后一个元素的值为:"<<temp->data<<endl;
    temp=l.Findval(18);
    if(temp==nullptr){
        cout<<"没有对应的值"<<endl;
    }else{
        cout<<temp->data<<endl;
    }
    //将22插入0号位置
    l.Insert(22,0);
    l.Print();
    //将44插入到最后一个位置
    l.Insert(44,l.length());
    l.Print();
    //将33插入到第3个位置后面
    l.Insert(33,3);
    l.Print();
    //删除第一个位置的结点
    l.Delete(1);
    l.Print();
    //删除最后一个位置的结点
    l.Delete(l.length());
    l.Print();
    //删除第3个位置的结点
    l.Delete(3);
    l.Print();
    return 0;
}
