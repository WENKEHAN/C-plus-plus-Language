//
// Created by kexib on 2022/8/20.
//

#include "LinkList.h"
void LinkList::InitList() {
    DeleteAll();
    head= nullptr;
}
//头插法建立单链表
void LinkList::HeadCreat(int n) {
    DeleteAll();
    Node *s;
    Node *p=new Node();
   //建立一个空的头结点
    p->next=nullptr;
    int i;
    for(int i=0;i<n;i++){
        s=new Node(i+10);
        s->next=p->next;
        p->next=s;
    }
    head=p;
}
//尾插法建立单链表
void LinkList::TailCreate(int n) {
    DeleteAll();
    Node *s;
    Node *pre= nullptr;
    Node *p=new Node();
    p->next= nullptr;
    for(int i=0;i<n;i++){
        s=new Node(i+100);
        if(pre==nullptr){
            p->next=s;
            pre=s;
        }else{
            //记录上一个结点
            pre->next=s;
            pre=s;
        }
    }
    head=p;
}

void LinkList::Print() {    Node *p;
    p=head->next;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

void LinkList::DeleteAll() {
    Node *p=head,*q;
    while(p){
        q=p->next;
        delete p;
        p=q;
    }
    head== nullptr;
}

int LinkList::Length() {
    Node *p=head->next;
    if(p== nullptr){
        return 0;
    }
    int count=0;
    while(p){
        count++;
        p=p->next;
    }
    return count;
}

Node *LinkList::GetT(const int &x) {
    Node *p=head;
    if(p== nullptr){
        return nullptr;
    }
    while(p){
        if(p->data==x){
            return p;
        }
        p=p->next;
    }
    return nullptr;
}

Node *LinkList::GetIndex(const int &i) {
    //如果访问的位置大于length-直接返回
    if(i>this->Length()){
        return nullptr;
    }
    Node *p=head->next;
    int count=0;
    while(p!= nullptr&&count!=i-1){
        count++;
        p=p->next;
    }
    return p;
}

bool LinkList::Insert(const int val, int i) {
    //如果小于0或者大于1整个长度的话，那么位置不合法
    if(i<0||i>this->Length()){
        return false;
    }
    //在尾部插入--找到最后一个结点的位置，让最后一个结点的位置指向新结点
    if(i==this->Length()){
        Node *p=head->next;
        //最后一个结点的next为空所以在这里终止条件是p->next
        while (p->next){
            p=p->next;
        }
        Node *newNode=new Node(val);
        p->next=newNode;
        return true;
    }
    //在头部插入
    if(i==0){
        //在头部插入，只需要让头节点的next指向新的结点--让新结点指向头结点的next就OK
        Node *newNode=new Node(val);
        //这里二者顺序不能够换--如果发生改变则将指向空
        newNode->next=head->next;
        head->next=newNode;
        return true;
    }
    //在某个具体的位置插入具体的值
    Node *p=head->next;
    //因为要找上这个位置的上一个结点，并且结点的个数是从0开始所以是<i-2
    for(int j=0;j<i-2;j++){
        p=p->next;
    }
    Node *newNode=new Node(val);
    newNode->next=p->next;
    p->next=newNode;
    return false;
}

bool LinkList::Delete(const int &val) {
    //首先第一步找到这个结点的值-其次要找这个结点上一个位置的结点,让上一个结点的next指向当前结点的next
    //然后delete释放当前结点
    Node *p=head->next,*q=head;
    while(p->data!=val&&p!= nullptr){
        p=p->next;
        q=q->next;
    }
    //没有找到对应的值
    if(p== nullptr){
        return false;
    }
    q->next=p->next;
    delete p;
    p= nullptr;
    return true;
}


int main(){
    LinkList L;
    L.InitList();
    //L.HeadCreat(10);
    L.TailCreate(10);
    L.Print();
    cout<<L.Length()<<endl;
    Node *temp=L.GetT(101);
    if(temp== nullptr){
        cout<<"不存在"<<endl;
    }else{
        cout<<temp->data<<endl;
    }
    temp=L.GetIndex(4);
    if(temp!= nullptr){
        cout<<temp->data<<endl;
    }
    //最后一个位置插入
    L.Insert(20,10);
    L.Insert(10,0);
    //在第3个位置插入55
    L.Insert(55,3);
    //
    L.Print();
    //删除第一个元素
    L.Delete(10);
    L.Print();
    //删除中间位置元素
    L.Delete(55);
    L.Print();
    //删除最后一个位置的元素
    L.Delete(20);
    L.Print();
    return 0;
}