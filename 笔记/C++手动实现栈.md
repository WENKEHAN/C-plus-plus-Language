***C++栈的实现***

《大学》–第四章

> 所谓诚其意者，毋自欺也。如恶如臭，如好好色，此之谓自谦，故君子必慎独也。
>
> 小人闲居为不善，无所不致，见君子然后厌然， 揜其不善而著其善。
>
> 人之视己，如见其肺肝然，则何益矣？
>
> 此谓诚于中，形于外，故君子必慎其独也。
>
> 曾子曰：“十目所视，十手所指，其严乎！”
>
> 富润屋，德润身，心广体胖，故君子必诚其意。

**译文：**

> 所谓真诚面对自己的意念，就是指不要欺骗自己。就像讨厌难闻的味道，就像喜欢美丽的色彩，这样才可以说让自己满意了，因此君子一定要在独处时特别谨慎。小人平日就不做善的事，没有什么坏事不做的；看到君子之后，才躲躲闪闪的样子，遮掩他所做的坏事，并且弘扬他所做的善事，就像看透自己的肺肝一样清楚，这样做又有什么用处呢？这叫做：心中的真正情况会显示于外在的言行上，因此君子一定要在独处时特别谨慎。
>
> 曾子说：“十只眼在看着，十只手指在指着，真是严厉啊！”
>
> 财富可以装潢屋子，德行可以滋润身体。心胸开阔而体态舒适，因此君子一定要真诚的面对自己的意念。

[TOC]

# 1.栈（stack）的定义

**==栈是限定仅在表尾进行插入和删除操作的线性表==**

1. **栈顶：**
   1. 允许插入和删除的一端叫做栈顶（Top）
2. **FILO（先进后出）**

# 2.栈的基础操作

1. 栈的初始化
2. 获取栈的元素个数
3. 栈的判空操作
4. 获取栈顶元素值
5. 出栈
6. 出栈的同时获取栈顶元素值 

```cpp
#include<iostream>
using namespace std;
enum { STACK_INIT_SIZE = 20, STACK_INC_SIZE = 2 };
#define T int
class MyStack {
private:
	T * data;
	int top;
	int size;
public:
	//构造函数--申请资源
	MyStack() :data(nullptr), top(-1), size(STACK_INIT_SIZE) {
		data = new(nothrow) T[size];
		if (data == nullptr) {
			exit(1);
		}
	
	}
	//析构函数--释放资源
	~MyStack() {
		delete[]data;
		data = nullptr;
		top = -1;
		size = 0;
	}
	//拷贝构造函数
	MyStack(const MyStack& stack) {
		size = stack.size;
		top = stack.top;
		data = new T[size];
		memmove(data, stack.data, sizeof(T) * stack.Size());
	}
	bool Resize(T newsize) {
		if (newsize <= size)return true;
		//在这里注意 申请空间以2倍扩容
		T* newdata = new(nothrow)T[STACK_INIT_SIZE*STACK_INC_SIZE];
		if (newdata == nullptr) {
			return false;
		}
		memmove(newdata, data, sizeof(T) * Size());
		delete []data;
		data = nullptr;
		data = newdata;
		size = STACK_INIT_SIZE*2;
		return true;
	}
	//获取元素个数
	int Size() const {
		return top + 1;
	}
	//判空操作
	bool Empty()const {
		return Size()==0;
	}
	int  Capc()const{
		return size;
	}
	//判满
	bool  Full() {
		//如果栈中元素的个数与栈的大小相等的话，那么栈已满
		return Size() == Capc();
	}
	//入栈
	bool  Push(const T val) {
		//栈已满，入栈失败
		if (Full()&&!Resize(STACK_INIT_SIZE*STACK_INC_SIZE)) {
			return false;

		}
		top += 1;
		data[top] = val;
		return true;
	}
	T Top()const {
		if (!Empty()) {
			return data[top];
		}
		else {
			cout << "栈为空，无元素" << endl;
			return false;
		}
	}
	bool  Pop() {
		if (!Empty()) {
			top -= 1;
			return true;
		}
		return false;
	}
	//既要出栈也要获取栈顶元素值
	T GetPop() {
		if (!Empty()) {
			T x = data[top];
			top -= 1;
			return x;
		}
		return false;
		cout << "栈已经为空，没有元素可以出栈" << endl;
	}
};
int main() {
	int n;
	cin >> n;
	MyStack st;
	for (int i = 0; i < n; i++) {
		st.Push(i );
	}
	for (int i = 0; i < n; i++) {
		cout <<st.Top() << "\t";
		st.Pop();
	}
	return 0;
}

```

