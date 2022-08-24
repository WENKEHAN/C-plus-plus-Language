//
// Created by kexib on 2022/8/20.
//

#include "LinkList.h"
void LinkList::InitList() {
    DeleteAll();
    head= nullptr;
}
//ͷ�巨����������
void LinkList::HeadCreat(int n) {
    DeleteAll();
    Node *s;
    Node *p=new Node();
   //����һ���յ�ͷ���
    p->next=nullptr;
    int i;
    for(int i=0;i<n;i++){
        s=new Node(i+10);
        s->next=p->next;
        p->next=s;
    }
    head=p;
}
//β�巨����������
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
            //��¼��һ�����
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
    //������ʵ�λ�ô���length-ֱ�ӷ���
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
    //���С��0���ߴ���1�������ȵĻ�����ôλ�ò��Ϸ�
    if(i<0||i>this->Length()){
        return false;
    }
    //��β������--�ҵ����һ������λ�ã������һ������λ��ָ���½��
    if(i==this->Length()){
        Node *p=head->next;
        //���һ������nextΪ��������������ֹ������p->next
        while (p->next){
            p=p->next;
        }
        Node *newNode=new Node(val);
        p->next=newNode;
        return true;
    }
    //��ͷ������
    if(i==0){
        //��ͷ�����룬ֻ��Ҫ��ͷ�ڵ��nextָ���µĽ��--���½��ָ��ͷ����next��OK
        Node *newNode=new Node(val);
        //�������˳���ܹ���--��������ı���ָ���
        newNode->next=head->next;
        head->next=newNode;
        return true;
    }
    //��ĳ�������λ�ò�������ֵ
    Node *p=head->next;
    //��ΪҪ�������λ�õ���һ����㣬���ҽ��ĸ����Ǵ�0��ʼ������<i-2
    for(int j=0;j<i-2;j++){
        p=p->next;
    }
    Node *newNode=new Node(val);
    newNode->next=p->next;
    p->next=newNode;
    return false;
}

bool LinkList::Delete(const int &val) {
    //���ȵ�һ���ҵ��������ֵ-���Ҫ����������һ��λ�õĽ��,����һ������nextָ��ǰ����next
    //Ȼ��delete�ͷŵ�ǰ���
    Node *p=head->next,*q=head;
    while(p->data!=val&&p!= nullptr){
        p=p->next;
        q=q->next;
    }
    //û���ҵ���Ӧ��ֵ
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
        cout<<"������"<<endl;
    }else{
        cout<<temp->data<<endl;
    }
    temp=L.GetIndex(4);
    if(temp!= nullptr){
        cout<<temp->data<<endl;
    }
    //���һ��λ�ò���
    L.Insert(20,10);
    L.Insert(10,0);
    //�ڵ�3��λ�ò���55
    L.Insert(55,3);
    //
    L.Print();
    //ɾ����һ��Ԫ��
    L.Delete(10);
    L.Print();
    //ɾ���м�λ��Ԫ��
    L.Delete(55);
    L.Print();
    //ɾ�����һ��λ�õ�Ԫ��
    L.Delete(20);
    L.Print();
    return 0;
}