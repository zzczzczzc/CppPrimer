## [练习10.1](_1.cpp)

>头文件algorithm定义了一个名为count的函数。它类似find，接受一对迭代器和一个值作为参数。count返回给定值在序列中出现的次数。编写程序，读取int序列存入vector中，打印有多少个元素的值等于给定值。

## [练习10.2](_2.cpp)

>重做上一题，但读取string序列存如list中。

## 练习10.3

>用accumulate求一个vector<int>中的元素之和。

```cpp
vector<int> s{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
accumulate(s.cbegin(), s.cend(), 0);
```

## 练习10.4

>假定v是一个vector<double>，那么调用accumulate(v.cbegin(), v.cend(), 0)有何错误（如果存在的话）？

会使用int计算，丢失精度。

## 练习10.5

>在本节对名册（roster）调用equal的例子中，如果两个名册中保存的都是C风格字符串而不是string，会发生什么？

会比较两个字符串的地址大小。

## [练习10.6](_6.cpp)

>编写程序，使用fill_n将一个序列中的int值都设置为0。

## 练习10.7

>下面程序是否有错误？如果有，请改正。  
>```cpp
>(a) vector<int> vec; list<int> lst; int i;
>    while (cin >> i) 
>        lst.push_back(i);
>    copy(lst.cbegin(), lst.cend(), vec.begin());
>
>(b) vector<int> vec;
>    vec.reserve(10);
>    fill_n(vec.begin(), 10, 0);
>```


```cpp
(a) vector<int> vec(10); list<int> lst; int i; //分配10个元素空间。
    while (cin >> i)
        lst.push_back(i);
    copy(lst.cbegin(), lst.cend(), vec.begin());

(b) 正确。
```
## 练习10.8

>本节提到过，标准库算法不会改变他们所操作的容器的大小。为什么使用back_inserter不会使这一断言失效？

因为它是插入迭代器，通过迭代器对容器进行操作。

## [练习10.9](_9.cpp)

>实现你自己的elimDups。测试你的程序，分别在读取输入后、调用unique后以及调用erase后打印vector的内容。

## 练习10.10

>你认为算法不改变容器大小的原因是什么？

不同容器改变大小方法不同，算法实现需要通用。

## [练习10.11](_11.cpp)

>编写程序，使用stable_sort和isShorter将传递给你的elimDups版本的vector排序。打印vector的内容，验证你的程序的正确性。

## [练习10.12](_12.cpp)\*

>编写名为compareIsbn的函数，比较两个Sales_data对象的isbn()成员。使用这个函数排序一个保存Sales_data对象的vector。

## [练习10.13](_13.cpp) 

>标准库函数定义了名为partition的算法，它接受一个谓词，对容器内容进行划分，使得谓词为true的值会排在容器的前半部分，而使谓词为false的值会排在后半部分。算法返回一个迭代器，指向最后一个使谓词为true的元素之后的位置。编写函数，接受一个string，返回bool值，指出string是否有5个或更多字符。使用此函数划分words。打印出长度大于等于5个元素。

## 练习10.14

>编写一个lambda，接受两个int，返回他们的和。

```cpp
auto f = [](int a, int b) { return a + b; };
```

## 练习10.15

>编写一个lambda。捕获它所在函数的int，并接受一个int参数。lambda应该返回捕获的int和int参数的和。

```cpp
int a;
auto f = [a](int b) { return a + b; };
```

## [练习10.16](_16.cpp)

>使用lambda编写你自己版本的biggies。

## [练习10.17](_17.cpp)\*

>重写10.3.1节练习10.12（第345页）的程序，在对sort的调用中使用lambda来代替函数compareIsbn。

## [练习10.18](_18.cpp)

>重写biggies，用partition代替find_if。我们在10.3.1节练习10.13（第345页）中介绍了partition算法。

## [练习10.19](_19.cpp)

>用stable_partition重写前一题的程序，与stable_sort类似，在划分后的序列中维持原有元素的顺序。

## [练习10.20](_20.cpp)

>标准库定义了一个名为count_if的算法。类似fid_if，此函数接受一对迭代器，表示一个输入范围，还接受一个谓词，会对输入范围中每个元素执行。count_if返回一个计数值，表示谓词有多少次为真。使用count_if重写我们程序中统计有多少单词长度超过6的部分。

## 练习10.21

>编写一个lambda，捕获一个局部int变量，并递减变量值，直至它变为0。一旦变量变为0，再调用lambda应该不再递减变量。lambda应该返回一个bool值，指出捕获的变量是否为0。

```cpp
int a;
auto f = [&a]() -> bool { return (a == 0 ? true : !(a--)); };
while (!f()) cout << a << " ";
```

## [练习10.22](_22.cpp)

>重写统计长度小于等于6的单词数量的程序，使用函数代替lambda。

## 练习10.23

>bind接受几个参数？

```cpp
auto newCallable = bind(callable, arg_list); //两个参数
```
* check_size：一个可调用对象。
* arg_list：是一个逗号分隔的参数列表。可能包含形如 *_n* 的名字，其中 *n* 是一个整数。

## [练习10.24](_24.cpp)

>给定一个string，使用bind和check_size在一个int的vector中查找第一个大于string长度的值。

## [练习10.25](_25.cpp)

>在10.3.2节（第349页）的练习中，编写了一个使用partition的biggies版本。使用check_size和bind重写此函数。

## 练习10.26

>解释三种插入迭代器的不同之处。

* back_inserter：使用push_back插入在容器末尾。
* front_inserter：使用push_front插入在容器开头。
* inserter：函数接受第二个指向给定容器的迭代器参数。插入在给定迭代器表示元素之前。

## [练习10.27](_27.cpp)

>除了unique（参见10.2.3节，第343页）之外，标准库还定义了名为unique_copy的函数，它接受三个迭代器，表示拷贝不重复元素的目的位置。编写一个程序，使用unique_copy将一个vector中不重复的元素拷贝到一个初始为空的list中。

## [练习10.28](_28.cpp)

>一个vector中保存1到9，将其拷贝到三个其他容器中，分别使用inserter、back_inserter和front_inserter将元素添加到三个容器中。对每中inserter，估计输出序列是怎样的，运行程序验证你的估计是否正确。

```cpp
vector<int> v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
```
* back_inserter：0, 1, 2, 3, 4, 5, 6, 7, 8, 9
* front_inserter：9, 8, 7, 6, 5, 4, 3, 2, 1, 0
* inserter：0, 1, 2, 3, 4, 5, 6, 7, 8, 9

## [练习10.29](_29.cpp)

>编写程序，使用流迭代器读取一个文本文件，存入一个vector中的string里。

## [练习10.30](_30.cpp)

>使用流迭代器、sort和copy从标准输入读取一个整数序列，将其排序，并将结果写到标准输出。

## [练习10.31](_31.cpp)

>修改前一题的代码，使其只能打印不重复的元素。你的程序应使用unique_copy（参见10.4.1节，第359页）。

## [练习10.32](_32.cpp)\*

>重写1.6节（第21页）中的书店程序，使用一个vector保存交易记录，使用不同算法完成处理，使用sort和10.3.1节（第345页）中的compareIsbn函数来排序交易记录，然后使用find和accumulate求和。

## [练习10.33](_33.cpp)

>编写程序，接受三个参数，一个输入文件和两个输出文件的文件名。输入文件保存的应该是整数。使用istream_iterator读取输入文件。使用istream_iterator将奇数写入第一个输入文件，每个值之后都跟一个空格。将偶数写入第二个输出文件，每个值都独占一行。

## [练习10.34](_34.cpp)

>使用reverse_iteratror逆向打印一个vector。

## [练习10.35](_35.cpp)

>使用普通迭代器逆序打印一个vector。

## [练习10.36](_36.cpp)

>使用find在一个int的list中查找最后一个值为0的元素。

## [练习10.37](_37.cpp)

>给定一个包含10个元素的vector，将位置3到7之间的元素按逆序拷贝到一个list中。

## 练习10.38

>列出5个迭代器类别，以及每类迭代器所支持的操作。

* 输入迭代器：==,!=,++,*,->
* 输出迭代器：++,*
* 前向迭代器：==,!=,++,*,->
* 双向迭代器：==,!=,++,--,*,->
* 随机访问迭代器：<,<=,>,>=,+,+=,-,-=,iter[n]==*(iter[n])

## 练习10.39

>list上的迭代器属于哪类？vector呢？

* list：双向迭代器
* vector：随机访问迭代器

## 练习10.40

>你认为copy要求哪类迭代器？reverse和unique呢？

* copy：2个输入迭代器，1个输出迭代器
* reverse：双向迭代器
* unique：随机访问迭代器

## 练习10.41

>仅根据算法和参数的名字，描述下面两个标准库算法执行什么操作：
>```cpp
>replace(beg, end, old_val, new_val);
>replace_if(beg, end, pred, new_val);
>replace_copy(beg, end, dest, old_val, new_val);
>replace_copy_if(beg, end, dest, pred, new_val);
>```

```cpp
replace(beg, end, old_val, new_val); // 将[beg, end)中等于old_val的值改为new_val
replace_if(beg, end, pred, new_val); // 将[beg, end)中使谓词条件pred为真的值改为new_val
replace_copy(beg, end, dest, old_val, new_val); // 将[beg, end)中的old_val拷贝到dest位置并改为new_val
replace_copy_if(beg, end, dest, pred, new_val); // 将[beg, end)中的值拷贝到dest并将其中使谓词条件pred为真的值改为new_val
```

## [练习10.42](_42.cpp)

>使用list代替vector重现实现10.2.3（第343页）中的去除重复单词的程序。
  
  
<p align="center">2019.03.25-2019.03.26</p>