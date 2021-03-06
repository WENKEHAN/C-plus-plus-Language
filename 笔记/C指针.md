《引言》-2022年5月14日

[TOC]

# 1·指针

内存-（在程序中称为主存DRAM），是外存于CUP进行沟通的桥梁

**计算机中所有的程序都是在内存中运行** 为了有效的使用内存，就把存以8位二进制的(bit)划分为存储单元也就是一个字节。为了有效的访问道每个内存的存储单元，就给内存存储的单元进行了编号，这些编号被称为该  **内存存储单元的地址**

**指针就是指向存储单元的地址**

## 1·1在32位操作系统下和62位操作系统下指针的大小

| 操作系统     | 指针大小 |
| ------------ | -------- |
| 32位操作系统 | 4字节    |
| 64位操作系统 | 8字节    |

```cpp
#include<iostream>
using namespace std;
int main() {
	int n;
	cout << &n << "\t" << sizeof(&n) << endl;
	return 0;
}
```

## 1·2指针变量 *

**指针变量储存地址的变量**

在32位操作系统下指针变量的大小为4个字节

在64位操作系统下指针变量的大小为8个字节

```cpp
int a;
char c;
int * ip=&a;
char *cp=&c;
//类型必须保持一致
```

### 1·21· * 在C/C++语言中的3种用法

1. 乘法
2. 指针变量
3. 取值

```cpp
#include <iostream>
using namespace std;
int main(){
   int a=1,b=10,c=0;
   c=a*b;//乘法
   int *p =&a;//指针类型的变量
   cout <<p<<endl;
   //*p  取值
   cout <<*p;
    return 0;
}
```

### 1·22 指针的值

1. 自身的值–保持的地址
2. 所指的指 *p 就是所指的值

**p=&a** 取的是当前变量的低地址

存放数据时：高位数存放在高地址，低位数存放在低地址

<a href="https://imgtu.com/i/OcebVK"><img src="https://s1.ax1x.com/2022/05/14/OcebVK.png" alt="OcebVK.png" border="0" /></a>