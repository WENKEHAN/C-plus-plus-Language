#include<iostream>
#include<cassert>
using namespace std;
template<class _Ty>
class MyVector {
public:
	typedef _Ty value_type;

	typedef _Ty* pointer;
	typedef const _Ty* const_pointer;

	typedef _Ty& reference;
	typedef const _Ty& const_reference;

	typedef pointer iterator;
	typedef const pointer const_iterator;

	typedef unsigned int size_type;
public:
	_Ty* _M_start; //_Ty *datat;
	_Ty* _M_finish;//size_t maxsize;
	_Ty* _M_end_of_storage;//size_t currsize;
public:
	MyVector() :_M_start(nullptr), _M_finish(nullptr), _M_end_of_storage(nullptr) {}
	~MyVector{
		clear();
		free(_M_start);
	}
	//拷贝构造
	MyVector(const MyVector& it) {
		
	}
	MyVector& operator=(const MyVector& it) {
		if (this != &it) {

		}
		return this;
	}
public:
	//容量
	size_t size()const {
		return (size_type)(_M_finish - _M_start);
	}
	size_t max_size()const {
		return (size_type)(_M_end_of_storage - _M_start);
	}
	bool empty()const {
		return 0 == size();
	}
public:
	//迭代器
	iterator begin() { return _M_start };
	const_iterator begin() const { return _M_start };

	iterator end() { return _M_finish};
	const_iterator end()const  { return _M_finish };
public:
	//元素访问
	reference at(size_type pos) {
		assert(pos >= 0 && pos < size());
		return begin()[pos];
	}
	const_reference at(size_type pos) const {
		assert(pos >= 0 && pos < size());
		return begin()[pos];
	}
	reference operator[](size_type pos) {
		return at(pos);
	}
	const_reference operator([size_type pos])const {
		return at(pos);
	}
	reference front() {
		return *begin();
	}
	const_reference front()const {
		return *begin;
	}
	reference back() {
		return *(end() - 1);
	}
	const_reference back()const {
		return *(end() - 1);
	}
	//返回指向内存中数组第一个元素的指针
	_Ty* data() {
		return _M_start;
	}
	const _Ty* data()const {
		return _M_start;
	}
public:
	void clear() {
		erase(begin(), end());
	}
	void insert() {
	}
	void erase(iterator _F,iterator _L) {

	}
	iterator erase(iterator pos) {
		iterator res = pos;
		if (pos + 1 != _M_finish) {
			while (pos != _M_finish - 1) {
				*pos = *(pos + 1);
				++pos;
			}
		}
		--_M_finish;
		_M_finish->~_Ty();
		return res;
	}
	void push_back(const _Ty& val) {
		if (_M_finish != _M_end_of_storage) {
			new(_M_finish)_Ty(val);
			++_M_finish;
		}
	}
	void pop_back() {

	}
	void swap() {

	}
};
