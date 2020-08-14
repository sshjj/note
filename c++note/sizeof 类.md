# sizeof（类）
类的大小是什么？确切的说，类只是一个类型定义，它是没有大小可言的。 用sizeof运算符对一个类型名操作，得到的是具有该类型实体的大小。首先：我们要知道什么是类的实例化，所谓类的实例化就是在内存中分配一块地址

用sizeof对类名操作，得到的结果是该类的对象在存储器中所占据的字节大小，由于静态成员变量不在对象中存储，因此这个结果等于各非静态数据成员（不包括成员函数）的总和加上编译器额外增加的字节。后者依赖于不同的编译器实现，C++标准对此不做任何保证。

确定类大小的几个原则：
1. 为类的非静态成员数据的类型大小之和
2. 有编译器额外加入的成员变量的大小，用来支持语言的某些特性（如：指向虚函数的指针）
3. 为了优化存取效率，进行的边缘调整
4. 与类中的构造函数，析构函数以及其他的成员函数无关

## 空类
```
#include <iostream> 
using namespace std;

class A{};

int main()
{
    cout << sizeof(A) << endl;
    system("pause");
}

输出：1
```
C++标准规定类的大小不为0，空类的大小为1，当类不包含虚函数和非静态数据成员时，其对象大小也为1。这就是我们刚才所说的实例化的原因（空类同样可以被实例化），每个实例在内存中都有一个独一无二的地址，为了达到这个目的，编译器往往会给一个空类隐含的加一个字节，这样空类在实例化后在内存得到了独一无二的地址

## 简单类

使用sizeof求这种简单类，结果和求结构体的sizeof是一样的，需要考虑偏移和对齐。要注意的是static变量不属于类的一部分，如果类中定义了static变量，求sizeof时可以忽略它们。
```
#include <iostream> 
using namespace std;

class A
{
    int a;
};
class B
{
    char a;
};
class C
{
    int a;
    char b;
};

int main()
{
    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;
    cout << sizeof(C) << endl;
    system("pause");
}

输出：

4　　sizeof(int)
1　　sizeof(char)
8　　sizeof(int) + sizeof(char)（考虑对齐）
```
## 带虚函数的类

虚函数放在虚表中，类中定义了虚函数，需要存放一个指向虚表的指针

如果在类中声明了虚函数（不管是1个还是多个），那么在实例化对象时，编译器会自动在对象里安插一个指针指向虚函数表VTable，在32位机器上，一个对象会增加4个字节来存储此指针，它是实现面向对象中多态的关键。而虚函数本身和其他成员函数一样，是不占用对象的空间的
```
#include <iostream> 
using namespace std;

class A
{
    int num;
    char str;
};
class B : public A
{
    char str2;
    int num2;
};

int main()
{
    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;
    system("pause");
}

输出：

8　　 sizeof(类A)
16　　sizeof(类A) + sizeo(类B)
```
一般来说，普通继承的空间计算结果应当是sizeof(基类)+sizeof(派生类)，然后考虑对齐，内存空间必须是类中数据成员所占用最大空间的整数倍。不过这是一般情况，具体怎么算要看编译器，codeblocks把类B看成12，因为把str2和str放在一起了

## 普通继承（父类含虚函数）
```
#include <iostream> 
using namespace std;

class A
{
    int num;
    virtual void fun(){}
};
class B : public A
{
    int num2;
};

int main()
{
    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;
    system("pause");
}
输出：

8　　 sizeof(类A)
12　　sizeof(类A) + sizeo(类B)
```
## 普通继承（含虚函数的子类普通继承含虚函数的父类）

这个要注意的一点是，虽然子类和父类都包含虚函数， 但它们存放于同一个虚表中，因此只需要一个指针

```
#include <iostream> 
using namespace std;

class A
{
    int num;
    virtual void fun(){}
};
class B : public A
{
    int num2;
    virtual void fun1(){}
};

int main()
{
    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;
    system("pause");
}
```
 
输出：

8　　 sizeof(int) + sizeof(指针)
12　　sizeof(int) + sizeof(int) + sizeof(指针)  （继承后只有一个虚表）

## 子类虚继承父类

sizeof(子类)=sizeof(基类)+sizeof(虚表指针)+sizeof(子类数据成员)
此外，如果子类和基类都有虚函数，各自用各自的虚表

```
#include <iostream> 
using namespace std;

class A
{
    int num;
};
class B : virtual public A
{
    int num2;
};

int main()
{
    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;
    system("pause");
}
```
输出：

4
12　　sizeof(A) + sizeof(B) + sizeof(虚继承指针)

```
#include <iostream> 
using namespace std;

class A
{
    int num;
    virtual void fun(){}
};
class B : virtual public A
{
    int num2;
    virtual void fun1(){}
};

int main()
{
    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;
    system("pause");
}

输出：

8
20　　sizeof(A) + sizeof(B) + sizeof(虚继承指针) +  sizeof(A类虚表指针) +  sizeof(B类虚表虚指针)
```
## 多重虚继承

虚继承存在的意义就是为了减少内存开销和二义性，实现对象共享。

```
#include <iostream> 
using namespace std;

class A
{
    int num;
};
class B : virtual public A
{
    int num2;
};

class C : virtual public A
{
    int num3;
};

class D : public B, public C
{
    int num4;
};

int main()
{
    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;
    cout << sizeof(C) << endl;
    cout << sizeof(D) << endl;
    system("pause");
}
```
 

输出：

4
12
12
24　　

D中包含a,b,c,d四个数据成员，还包含两个指向虚基类A的指针，这种情况下，VS和CB都没有将两个指针合为一个。这种情况也可以这样考虑，sizeof(D)=sizeof(B)+sizeof(C)，但由于是虚继承，虚基类A中数据成员a只需要保留一份，而我们算了两次，所以还需要减去A的数据成员，所以公式应当是sizeof(D)=sizeof(D的非静态数据成员) + sizeof(B)+sizeof(C)-sizeof(A的非静态数据成员)。

 