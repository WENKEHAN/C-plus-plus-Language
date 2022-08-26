//
// Created by HANWENKE on 2022/8/25.
//
#include "Circular_Linked_List.h"

//��ʼ��������
void Circular_Linked_list::InitList() {
    DeleteAll();
    head= nullptr;
    //����һ�������ͷ���
    head=new Node();
}
//���������
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
    //ͷ�巨����������
    Node * s=new Node(val);
    Node *pre= nullptr;
    //ͷ�巨--��һ������Ľ���next=head
    //֮������ʱ��-����Ҫ��head->next=s;
    //�����½���nextָ��  head->next  ����Ҫ�����½���next
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
       //֮ǰ�����һ������nextָ���µĽ��
       temp->next=s;
       //�½���nextָ��head;
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
    //��Ϊʱѭ��������--β����nextָ��ͷ���--����ʱp!=head;
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
    //����Ҫ�ж�p�Ƿ��ǻص���ͷ�ڵ�--����ص�ͷ�ڵ�˵��û���ҵ�
    while(p->data!=val&&p!=head){
        p=p->next;
    }
    //���p����head˵��û�ҵ�����null�����򷵻ؾ���Ľ��
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
//�ڵ�i��λ�ú����ֵΪval ��Ԫ��-�����ж���λ���Ƿ�Ϸ�
bool Circular_Linked_list::Insert(const int &val, int i) {
    if(i<0||i>length()+1){
        cout<<"����λ�ò��Ϸ�"<<endl;
        return false;
    }
    //�����0��λ�þ���ͷ�壬ֱ�ӵ���ͷ�巽��
    if(i==0){
        HearCreate(val);
        return true;
        //�������length����β��
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
//ɾ����i��λ�õĽ��
void Circular_Linked_list::Delete(const int &i) {
    if(i<0||i>length()){
        cout<<"ɾ��λ�ò��Ϸ�"<<endl;
        return ;
    }
    //��ȡ��i��λ�õ�ǰһ�����
    Node *temp= Get(i-1);
    //Ҫɾ���Ľ��
    Node *p=temp->next;
    //ǰһ������nextָ��ǰ����next
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
    cout<<"���һ��Ԫ�ص�ֵΪ:"<<temp->data<<endl;
    temp=l.Findval(18);
    if(temp==nullptr){
        cout<<"û�ж�Ӧ��ֵ"<<endl;
    }else{
        cout<<temp->data<<endl;
    }
    //��22����0��λ��
    l.Insert(22,0);
    l.Print();
    //��44���뵽���һ��λ��
    l.Insert(44,l.length());
    l.Print();
    //��33���뵽��3��λ�ú���
    l.Insert(33,3);
    l.Print();
    //ɾ����һ��λ�õĽ��
    l.Delete(1);
    l.Print();
    //ɾ�����һ��λ�õĽ��
    l.Delete(l.length());
    l.Print();
    //ɾ����3��λ�õĽ��
    l.Delete(3);
    l.Print();
    return 0;
}
