# C++内存泄漏检查工具——Valgrind（--tool = memcheck）
在写大型C/C++工程时难免会发生内存泄漏现象，系统编程中一个重要的方面就是有效地处理与内存相关的问题。你的工作越接近系统，你就需要面对越多的内存问题。有时这些问题非常琐碎，而更多时候它会演变成一个调试内存问题的恶梦。 常见的内存问题一共七种：1. 动态内存泄露；2. 资源泄露，比如文件指针不关闭；3. 动态内存越界；4.数组内存越界；5.动态内存double free；6.使用野指针，即未初始化的指针；7.释放野指针，即未初始化的指针。

内存问题非常难定位，对于小工程来说，简单去检查代码中new和delete的匹配对数就基本能定位到问题，但是一旦代码量上升到以万单位时，仅靠肉眼检查来定位问题那就非常困难了，所以我们需要利用工具帮助我们找出问题所在。在Linux系统下内存检测工具首推Valgrind，一款非常好用的开源内存管理框架。Valgrind其实是一个工具集，内存错误检测只是它众多功能的一个，但我们用得最多的功能正是它——memcheck。

该工具可以检测下列与内存相关的问题 :

* 未释放内存的使用
* 对释放后内存的读/写
* 对已分配内存块尾部的读/写
* 内存泄露
* 不匹配的使用malloc/new/new[] 和 free/delete/delete[]
* 重复释放内存

下面开始讲解Valgrind的应用场景。

注意: 下面讨论的所有测试代码都应该使用gcc/g++并且加上-g选项。
***
## 1. 使用未初始化的内存（使用野指针）
这里我们定义了一个指针p，但并未给他开辟空间，即他是一个野指针，但我们却使用它了。  
![](/pic/val1.png)  

Valgrind检测出我们程序使用了未初始化的变量，但并未检测出内存泄漏。 

![](/pic/val2.png)   
***
## 2.在内存被释放后进行读/写（使用野指针）
p所指向的内存被释放了，p变成了野指针，但是我们却继续使用这片内存。  
![](/pic/val3.png)

Valgrind检测出我们使用了已经free掉的内存，并给出这片内存是哪里分配哪里释放的。

![](/pic/val4.png)
***
## 3.从已分配内存块的尾部进行读/写（动态内存越界）
我们动态地分配了一段数组，但我们在访问个数组时发生了越界读写，程序crash掉。

![](/pic/val5.png)

Valgrind检测出越界的位置。

![](/pic/val6.png)

注意：Valgrind不检查静态分配数组的使用情况！所以对静态分配的数组，Valgrind表示无能为力！比如下面的例子，程序crash掉，我们却不知道为什么。
***
## 4.内存泄漏
内存泄漏的原因在于没有成对地使用malloc/free和new/delete，比如下面的例子。

![](/pic/val7.png)

Valgrind会给出程序中malloc和free的出现次数以判断是否发生内存泄漏，比如对上面的程序运行memcheck，Valgrind的记录显示上面的程序用了1次malloc，却调用了0次free，明显发生了内存泄漏！

![](/pic/val8.png)

上面提示了我们可以使用--leak-check=full进一步获取内存泄漏的信息，比如malloc和free的具体行号。

![](/pic/val9.png)
***
## 5. 不匹配地使用malloc/new/new[] 和 free/delete/delete[]
不匹配地使用malloc/new/new[] 和 free/delete/delete[]则会被提示mismatch：

![](/pic/val10.png)

![](/pic/val11.png)
***
## 6.两次释放内存
double free的情况同样是根据malloc/free的匹配对数来体现的，比如free多了一次，Valgrind也会提示。

![](/pic/val12.png)

![](/pic/val13.png)