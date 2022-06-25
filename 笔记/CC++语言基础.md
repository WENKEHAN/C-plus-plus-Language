《引言》

大学之道，在明明德，在亲明，在止于至善。

知止而后有定，定而后能静，静而后能安，安而后能虑，虑而后能得。

物有本末，事有始终，之所先后，则近道矣。



[TOC]

# 1·C/C++语言的编译链接过程：

在Windows操作系统中，扩展名为: * .exe,    * .bat  , * .com等的文件是可以执行文件，可执行文件由指令和数据构成。

在Linux是靠文件属性来判断是否可执行

不可执行文件：其内容由数据构成。

在C/C++ 语言中 * .c/ * .cpp 源文件（文本），* .h 头文件（文本）,* .i预编译文件（文本）， *.s 汇编文件， *.o  / * .obj二进制目标文件， *.exe 可执行文件

<a href="https://imgtu.com/i/OwCFw8"><img src="https://s1.ax1x.com/2022/05/12/OwCFw8.png" alt="OwCFw8.png" border="0" /></a>

# 2·进制转换

**贪心减法**

| 128  | 64         | 32            | 16   | 8    | 4     | 2     | 1    |
| ---- | ---------- | ------------- | ---- | ---- | ----- | ----- | ---- |
| <    | >103-64=39 | 39>32 39-32=7 | 7<16 | 7<8  | 7-4=3 | 3-2=1 | 1<=1 |
| 0    | 1          | 1             | 0    | 0    | 1     | 1     | 1    |

103（10）->	011 001 11(2)	->	147(8)	->	67(16)

# 3·基本数据类型与大小

## 3·1在64位操作系统下：

| 基本数据类型 | 所占字节 |
| ------------ | -------- |
| char         | 1        |
| bool         | 1        |
| short        | 2        |
| int          | 4        |
| long         | 4        |
| long long    | 8        |
| float        | 4        |
| double       | 8        |
| string       | 40       |

## 3·2在32位操作系统下：

| 基本数据类型 | 所占字节 |
| ------------ | -------- |
| char         | 1        |
| bool         | 1        |
| short        | 2        |
| int          | 4        |
| long         | 4        |
| long long    | 8        |
| float        | 4        |
| double       | 8        |
| string       | 28       |

## 3.3测试代码

```cpp
#include<iostream>
using namespace std;
int main() {
	cout << "char=" << sizeof(char) << endl;;
	cout << "short=" << sizeof(short) << endl;
	cout << "bool=" << sizeof(bool)<<endl;
	cout << "int=" << sizeof(int) << endl;
	cout << "long=" << sizeof(long) << endl;
	cout << "long long=" << sizeof(long long) << endl;
	cout << "float=" << sizeof(float) << endl;
	cout << "double=" << sizeof(double) << endl;
	cout << "string=" << sizeof(string) << endl;
	return  0;
}

```

# 4·定义与声明

## 4·1什么是定义？

为变量分配一块儿内存空间，并给其取个名字–一旦变量名与内存块匹配起来，它们就同生共死，并且这块儿内存的位置不能够被该变，一个区域内，只能被定义一次，不能够被多次定义。

## 4·2什么是声明

1. 告诉编译器，这个名字已经匹配到一块儿内存上了。
2. 告诉编译器，这个名字已经预定了，其它地方不能够使用这个了

## 4·3定义和声明的区别

**定义创建了对象并为这个对象分配了一块儿内存空间，而声明是没有分配内存空间的**

# 5·变量的作用域

1. 全局变量：再函数外定义的变量
2. 局部变量：在函数内部定义的变量
3. 程序块中的变量：在程序块中定义的变量，只能在程序块中使用

```cpp
int n;//全局变量
void fun(){
    //局部变量
    int age=10;
    int sum=100;
}
int main(){
    //块变量，在块之外不可以使用
    {
        int z=100;
        z+=10;
    }
    return 0;
}
```

# 6·c语言的常量

**全局变量未初始化为0**

**局部变量未初始化则为一个随机值**

## 6·1字面常量

```cpp
int main(){
	int a=10;//10为一个字面常量，不可以对其赋值
	return 0;
}
```

## 6·2用#define定义的宏常量

定义的标识符不占内存空间，只是一个临时符号，预编译后这个符号就不存在了

## 6·3 用const关键字修饰的变量，称为常量

**不论是局部常变量还是全局常变量，都需要进行初始化**

```cpp
#include <iostream>
using namespace std;
int main(){
    int const s=100;
    s=1000;//error 常变量不可以被修改
    return 0;
}
```

1. 在C语言当中const修饰的长变量  –**以变量为主**

2. 在C++当中以    **常量为主**   –在编译时进行替换

   ​	例如：如下代码，在CPP中式正常的，在C语言中编译不通过

   ```cpp
   int main(){
      int const len=10;
      int arr[len];
       return 0;
   }
   ```

### 6.3.1 #define与const的区别

1. 宏是在预编译的时进行替换；const是在编译时进行替换
2. #defines无类型是不开辟内存空间的；const会开辟内存空间

## 6·4枚举常量

枚举当中的值，称为枚举常量	**枚举常量只能为整形**

不初始化的值，则在上一个值的基础上+1

enum week{mon=1,tw=2,wen=3}

```cpp
#include <iostream>
using namespace std;
enum week{one=1,two=2,three=3};
int main(){
   enum week x;
   x=one;
   cout <<x<<endl;
   x=two;
   cout<<x<<endl;
   x=three;
   cout <<x;
    return 0;
}
```

## 6·5 字符常量和字符串常量

| 字符  | 对应字符 |
| ----- | -------- |
| 0     | 48       |
| A     | 65       |
| a     | 97       |
| \n    | 10       |
| enter | 13       |
| 空格  | 32       |

### 6.5.1空字符 

```cpp
char a=0;//0空字符 0
char c='0';//'0'=》48
char b='\0';//空字符 ASCALL 码为 0
//空格！=空字符
```

### 6.5.2 字符串C与C++都以\0结束

**只要是“ ”**就都以\0结束-占空间，但不计算长度

```c
char char[]={"len"};
//最后一个字符以\0结束，表示但字符串的长度并不计算\0
//但\0占空间
```

