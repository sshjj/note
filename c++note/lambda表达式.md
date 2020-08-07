lambda函数语法定义：
[capture](parameters)mutable ->return-type{statement}
* [capture]:捕捉列表
* (parameters):参数列表
* mutable：mutabe修饰符，默认为const函数
* ->return-type：返回类型（可以省略）
* {statement}：函数体

捕捉列表的形式：
* [var]表示值传递方式捕捉var。
* [=]表示值传递的方式捕捉所有父作用域的变量
* [&var]表示引用传递捕捉变量var。
* [&]表示引用传递捕捉所有父作用域的变量
* [this]表示值传递方式捕捉当前的this指针


仿函数：简单的说就是重定义了成员函数operator()的一种自定义类型对象
仿函数是编译器实现lambda的一种方式，C++11中，lambda可以视为仿函数的一种等价形式
封装一些代码逻辑，相较于传统意义上的函数定义，lambda函数更加直观，使用也非常简便，代码可读性好
