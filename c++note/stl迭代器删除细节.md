# STL 删除erase
c++中STL容器vector/list/map/set/deque/string等删除元素的问题，迭代器容易出现以下错误，示例代码如下：
```
std::vector<int> arrayList;
...
std::vector<int>::iterator it = arrayList.begin();
for ( ; it != arrayList.end(); it++)
{
    if (...)
        arrayList.erase(it);
}
```
显然若条件为真即if(...)为true，那么程序执行调试就会崩溃。
根本原因是：当容器中的一个元素被删除时，指向该元素后续的迭代器变得无效。上面的代码中，只要执行了erase(it),那么it就会变得无效，那么执行it++就肯定会出错。

通常有两条规则：
1. 对于节点式容器(map, list, set)元素的删除，插入操作会导致指向该元素的迭代器失效，其他元素迭代器不受影响
2. 对于顺序式容器(vector，string，deque)元素的删除、插入操作会导致指向该元素以及后面的元素的迭代器失效

# 正确写法
供参考的正确的写法如下：
1. 对于节点式容器（map/list/set）
```
std::map<int, struct> mapInfo;
...
std::map<int, struct>::iterator it = mapInfo.begin();
while (it != mapInfo.end())
{
    if (...)
    {
        // 删除节点的前，对迭代器进行后移的操作，因为其他元素不会失效
        mapInfo.erase(it++);
    }
    else
    {
        it++;
    }
}
```
2. 对于顺序式容器（vector/string/deque）
```
std::vector<int> arrayInt;
...
std::vector<int>::iterator it = arrayInt.begin();
while (it != arrayInt.end())
{
    if (...)
    {
        // 需要注意的是，因为顺序式容器会使本身和后面的元素迭代器都失效，所以不能简单的++操作
        // 顺序式容器的erase()会返回紧随被删除元素的下一个元素的有效迭代器（节点式容器的erase()的返回值是void）
        it = arrayInt.erase(it);
    }
    else
    {
        it++;
    }
```
