## 练习11.1
>描述map和vector的不同。

* map：关联容器，包含一个键值（key-value）对应关系。
* vector：顺序容器，仅包含元素本身。

## 练习11.2
>分别给出适合使用list、vector、deque、map以及set的例子。

* list：常需要插入/删除元素的情况。
* vector：常需要随机访问元素的情况。
* deque：常需要随机访问，高效在头部删除，尾部插入元素的情况。
* map：包含键值（key-value）对应关系的情况。
* set：需要有序不重复元素的情况。

## [练习11.3](_3.cpp)
>编写你自己的单词计数程序。

## [练习11.4](_4.cpp)\*\*
>扩展你的程序，忽略大小写和标点。例如："example."、"example,"和"Example"应该递增相应的计数器。

## 练习11.5
>解释map和set的区别，你如何选择使用哪个？

* map：每个值有一个对应的关键字，通过关键字访问值。
* set：只有关键字。

## 练习11.6
>解释set和list的区别，你如何选择使用哪个？

* set：有序，不含重复元素。
* list：无序，可重复。

## [练习11.7](_7.cpp)
>定义一个map，关键字是家庭的姓，值是一个vector，保存家中孩子（们）的名。编写代码，实现添加新的家庭以及向已有家庭中添加新的孩子。

## [练习11.8](_8.cpp)
>编写一个程序，在一个vector而不是set中保存不重复的单词。使用set的优点是什么？

使用set不会保存重复元素。

## 练习11.9
>定义一个map，将单词与一个行号的list关联，list中保存的是单词所出现的行号。

```cpp
map<string, list<size_t>> m;
```

## 练习11.10
>可以定义一个vector<int>::iterator到int的map吗？list<int>::iterator到int的map呢？对于两种情况，如果不能，解释为什么。

* vector<int>::iterator：可以。
* list<int>::iterator：不行，list的迭代器不支持比较运算。

## 练习11.11
>不使用decltype重新定义bookstore。

