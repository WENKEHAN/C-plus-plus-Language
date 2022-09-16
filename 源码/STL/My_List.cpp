//
// Created by HANWENKE on 2022/8/31.
//
#include "My_List.h"
template<class t>
bool list<t>::empty(){
    return m_head== nullptr&&m_tail== nullptr;
}
template<class t>
void list<t>::push_front(const t &data) {
    m_head=new node(nullptr,data,m_head);
    if(m_head->m_next){
        m_head->m_next->m_prev=m_head;
    } else{
        m_tail=m_head;
    }
}
template<class t>
void list<t>::pop_front() {
    if(empty()){
        return ;
    }
    node *pnode=m_head->m_next;
    delete m_head;
    if(pnode!= nullptr){
        pnode->m_prev= nullptr;
    }else{
        m_tail= nullptr;
    }
    m_head=pnode;
}
template<class t>
t &list<t>::front() {
    if(empty()){
        //不知道返回什么
        throw underflow_error("null node");
    }
    return m_head->m_data;
}
template<class t>
t const &list<t>::front() const {
    //去常转化
    return const_cast<list*>(this)->front();
}
template<class t>
void list<t>::push_back(const t &data) {
    m_tail=new node(m_tail,data, nullptr);
    if(m_tail->m_prev) {
        m_tail->m_prev->m_next = m_tail;
        return;
    }
    else
        m_head=m_tail;
}
template<class t>
void list<t>::pop_back() {
    if(empty()){
        return;
    }
    node *pnode=m_tail->m_prev;
    delete m_tail;
    //如果存前一个结点
    if(pnode)
        pnode->m_next= nullptr;
    else
        //只有一个结点的时候
        m_head= nullptr;
    m_tail=pnode;
}
template<class t>
t &list<t>::back() {
    if(empty()){
        throw underflow_error("null node");
    }
    return m_tail->m_data;
}
template<class t>
t const &list<t>::back() const {
    return const_cast<list*>(this)->back();
}
template<class t>
void list<t>::clear() {
    while(!empty()){
        //pop_back();
        //删除头或者一直删除尾
        pop_front();
    }
}
template<class t>
size_t list<t>::size() {
    size_t i=0;
    for(node *pnode=m_head;pnode!= nullptr;pnode=pnode->m_next)
        ++i;
    return i;
}
template<class t>
list<t>::~list() {
    clear();
}
//类的内部函数外部不允许访问--所以这里必须是友元才可以
/*ostream &operator<<(ostream &os, list<int>&l) {
    for(list<int>::node *pnode=l.m_head; pnode != nullptr; pnode=pnode->m_next){
        os<<pnode->m_data<<" ";
    }
    return os;
}*/

template<class t>
void list<t>::erase(const list::Iterator &loc) {
    //指向尾部结点的下一个位置-直接返回
    if(loc==end()){
        return;
    }
    node *pdel=loc.m_cur;
    //要删除结点的前一个结点的next指向--待删除结点的next结点
    if(pdel->m_prev)
        pdel->m_prev->m_next=pdel->m_next;
    else
        m_head=pdel->m_next;
    //要删除结点的洗一个结点的pre指向当前结点的pre
    if(pdel->m_next)
        pdel->m_next->m_prev=pdel->m_prev;
    else
        m_tail=pdel->m_prev;
    delete pdel;
}

template<class t>
void list<t>::insert(const list::Iterator &loc, const t &data) {
    //指向结尾--直接push_back
    if(loc==end()){
        push_back(data);
    }else{
        node *pnode=new node(loc.m_cur->m_prev,data,loc.m_cur);
        //如果当前结点没有前一个-那就就在头结点的位置
        if(pnode->m_prev){
            pnode->m_prev->m_next=pnode;
        }else
            m_head=pnode;
        pnode->m_next->m_prev=pnode;
    }
}
void print(list<int>&l){
    typedef list<int>::Iterator it;
    for(it It=l.begin();It!=l.end();++It){
        cout<<*It<<" ";
    }
    cout<<endl<<"--------------------------------"<<endl;
}
//比较查找
template<class IT,class t>IT find(IT const&a,IT const &b,t const&data){
    for(IT it=a;it!=b;++it){
        //如果找到了--返回找到的迭代器
        if(*it==data){
            return it;
        }
    }
    //b结点不参与比较
    return b;
}
//比较器排序
template<class It,class cmp>
void sort(It const &begin,It const &end,cmp CMP){
    It p=begin;
    It last=end;
    --last;
    for(It i=begin,j=last;i!=j;){
        while(i!=p&&CMP(*i,*p)){
            ++i;
        }
        if(i!=p){
            swap(*i,*p);
        }
        while(j!=p&&CMP(*p,*j)){
            --j;
        }
        if(j!=p){
            swap(*p,*j);
        }
    }
    It it=begin;
    ++it;
    //p没有指向第一个结点-也没有指向第二个结点，说明至少有三个结点
    if(p!=begin&&p!=it)
        sort(begin,p,CMP);
    it=p;
    ++it;
    //说明p指向了倒数第二个结点
    if(it!=end&&it!=last){
        sort(it,end,CMP);
    }
}
//排序--快速排序
template<class It> void sort(It const &begin,It const &end){
    It p=begin;
    It last=end;
    --last;
    for(It i=begin,j=last;i!=j;){
        while(i!=p&&*i<*p){
            ++i;
        }
        if(i!=p){
            swap(*i,*p);
        }
        while(j!=p&&*p<*j){
            --j;
        }
        if(j!=p){
            swap(*p,*j);
        }
    }
    It it=begin;
    ++it;
    //p没有指向第一个结点-也没有指向第二个结点，说明至少有三个结点
    if(p!=begin&&p!=it)
        sort(begin,p);
    it=p;
    ++it;
    //说明p指向了倒数第二个结点
    if(it!=end&&it!=last){
        sort(it,end);
    }
}
int main(){
    list<int>ls;
    for(int i=0;i<5;i++){
        ls.push_front(10+i);
    }
    for(int i=0;i<5;i++){
        ls.push_back(100+i);
    }
    print(ls);
   //cout<<ls<<endl;
  /*  print(ls);
    ls.erase(ls.begin());
    print(ls);
    ls.pop_back();
    ls.pop_front();
    print(ls);
    typedef list<int>::Iterator It;*/
    typedef list<int>::const_Iterator CIT;
  /*  It it=ls.begin();
    *it=900;
    print(ls);
    //常属性的链表一般需要赋初值
    const list<int>cls(ls);*/

   /* for(CIT cit=cls.begin();cit!=cls.end();++cit){
        cout<<*cit<<" ";
    }*/
    auto fit=find(ls.begin(),ls.end(),100);
    ls.erase(fit);
    print(ls);
    //sort(ls.begin(),ls.end());
    class cmp{
    public:
        bool operator ()(int const &a,int const &b){
            return a>b;
        }
    };
    cmp cm;
    sort(ls.begin(),ls.end(),cm);
    print(ls);
}



