## 练习9.1  

>对于下面的程序任务，vector、deque和list哪种容器最为合适？解释你的选择理由。如果没有哪种容器优于其他容器，也请解释理由。  
>&ensp;&ensp;(a) 读取固定数量的单词，将他们按字典序插入到容器中。我们将在下一章看到，关联容器更适合这个问题。  
>&ensp;&ensp;(b) 读取位置数量的单词，总是将新单词插入到末尾，删除操作在头部进行。  
>&ensp;&ensp;(c) 从一个文件读取位置数量的整数。将这些数排序，然后将他们打印到标准输出。

1. **list**：插入效率高。  
2. **deque**：队列操作。  
3. **vector**：可变长，不需要插入删除。  

## 练习9.2  

>定义一个list对象，其元素类型是int的deque。

```cpp
std::list<deque<int>> name;
```

## 练习9.3

>构成跌倒其范围的迭代器有何限制？

1. 指向同一个容器中的元素或最后一个元素之后的位置。
2. 可以通过递增begin到达end。（end 不在 begin 之前）

## [练习9.4](_4.cpp)

>编写函数，接受一对指向vector<int>的迭代器和一个int值。在两个迭代器指定范围中查找给定的值，返回一个布尔值来指出是否找到。

```cpp
bool find99(vector<int>::const_iterator begin, vector<int>::const_iterator end, int x) {
    while (begin++ != end) {
        if (*begin == x) // 迭代器支持解引用，以指向他对应的值
            return true;
    }
    return false;
}
```

## [练习9.5](_5.cpp)

>重写上一题的函数，返回一个迭代器指向找到的元素。注意，程序必须处理未找到给定值的情况。

```cpp
vector<int>::const_iterator find886(auto begin, auto end, int x) {
    while (begin != end) {
        if (*begin == x)
            return begin;
        begin++; // 此时先判断后自增
    }
    return end; // end并不指向任何值
}
```

## 练习9.6

>下面程序有何错误？你应该如何修改它？
>```cpp
>list<int> lst1;
>list<int>::iterator iter1 = lst1.begin(), iter2 = lst1.end();
>while (iter < iter) /* ... */
>```

```cpp
list<int> lst1;
list<int>::iterator iter1 = lst1.begin();
list<int>::iterator iter2 = lst1.end();
while (iter1 != iter2)
```
&emsp;&emsp;迭代器本质上是模板指针，而指针比较大小常常是无意义的。
因此不能写
`while (iter1 < iter2)`

## 练习9.7

>为了索引int的vector中的元素，应该使用什么类型？

```cpp
vector<int>::size_type  
```
**size_type**:为容器内元素的类型的变量

## 练习9.8

>为了读取string的list中的元素，应该使用什么类型？如果写入list，又该使用什么类型？

* `list<string>::const_iterator // 读`
* `list<string>::iterator // 写`
* `list<list<string>>::const_iterator // 读`
* `list<list<string>>::iterator // 写`
## 练习9.9

>begin和cbegin两个函数有什么不同？

* begin：普通迭代器，可更改  
* cbegin：常量迭代器，不可更改  

## 练习9.10

>下面4个对象分别是什么类型？
>```cpp
>vector<int> v1;
>const vector<int> v2;
>auto it1 = v1.begin(), it2 = v2.begin();
>auto it3 = v1.cbegin(), it4 = v2.cbegin();
>```

* it1：iterator  
* it2：const_iterator  
* it3：const_iterator  
* it4：const_iterator  

## 练习9.11

>对6种创建和初始化vector对象的方法，每一种都给出一个实例。解释每个vector包含什么值。

```cpp
vector<int> name0 = {1, 2, 3, 4, 5, -1}; // 1，2，3，4，5，-1
vector<int> name1 = name0; // 同name0
vector<int> name2; // 空
vector<int> name3(20); // 20个0
vector<int> name4(20, 1); // 20个1
vector<int> name5(name0.begin(), name0.end()); // 同name0
```

## 练习9.12

>对于接受一个容器创建其拷贝的构造函数，和接受两个迭代器创建拷贝的构造函数，解释他们的不同。

**接受容器创建其拷贝的构造函数**：两个容器类型与元素类型都需要相等。  
**接受两个迭代器创建拷贝的构造函数**：容器类型和元素类型不必都相等，只需两者元素类型可转换。

## [练习9.13](_13.cpp)

>如何从一个`list<int>`初始化一个`vector<double>`？从一个`vector<int>`又该如何创建？编写代码验证你的答案。

```cpp
list<int> a(2, 2);
vector<double> name0(a.begin(), a.end());
vector<int> b(2, 2);
vector<double> name1(b.begin(), b.end());
```

## [练习9.14](_14.cpp)

>编写程序，将一个list中的char*指针（指向C风格字符串）元素给一个vector中的string。

```cpp
list<const char*> a{"hello", "world"};
vector<string> name1;
name1.assign(a.cbegin, a.cend());
```

## [练习9.15](_15.cpp)

>编写程序，判定两个`vector<int>`是否相等。

```cpp
bool equal(vector<int> a, vector<int> b) {
    if(a == b) return true;
    else return false;
}
```

## [练习9.16](_16.cpp)

>重写上一题程序，比较一个`list<int>`中的元素和一个`vector<int>`中的元素。

关系运算符必须在同类容器同类元素之间使用，因此需先进行元素转换。
```cpp
bool equal(list<int> a, vector<int> b) {
    vector<int> t(a.begin(), a.end());
    if(t == b) return true;
    else return false;
}
```

## 练习9.17

>假定c1和c2是两个容器，下面的比较操作有何限制（如果有的话）？
>```cpp
>if(c1 < c2)
>``` 

* c1,c2为同类型容器且c1,c2中元素为同类型元素
* 元素类型需支持关系运算符

## [练习9.18](_18.cpp)

>编写程序，从标准输入读取string序列，存入一个deque中。编写一个循环，用迭代器打印deque中的元素。

```cpp
for (string a; a != "0"; name.push_back(a))
    cin >> a;
for (auto c = name.cbegin(); c != name.cend(); c++)
    cout << *c << endl;
```

## [练习9.19](_19.cpp)

>重写上题的程序，用list替代deque。列出程序要做出哪些改变。

将`deque<string>`改为`list<string>`

## [练习9.20](_20.cpp)

>编写程序，从一个list<int>拷贝元素到两个deque中。值为偶数的所有元素拷贝到一个deque中，而奇数值元素都拷贝到另一个deque中。

```cpp
list<int> la{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
deque<int> d1;
deque<int> d2;
for (auto i : la) {
    if (i % 2 == 0) d1.push_back(i);
    else d2.push_back(i);
}
```

## 练习9.21

>假如我们将308页中使用insert返回值将元素添加到list中的循环程序改写为将元素插入到vector中，分析循环将如何工作。

```cpp
vector<string> lst; // string的vector类型
auto iter = lst.begin(); // vector的迭代器类型，指向首元素。
while (cin >> word) // 标准输入字符串
    iter = lst.insert(iter, word); // 在iter之前创建一个值为word的元素，将iter指向新元素的迭代器。
```

## 练习9.22

>假定iv是一个int的vector，下面程序存在什么错误？你将如何修改？
>```cpp
>vector<int>::iterator iter = iv.begin(), \
>                      mid = iv.begin() + iv.size() / 2;
>while (iter != mid)
>    if (*iter == some_val)
>        iv.insert(iter, 2 * some_val);
>```

迭代器没有移动，循环无法终止。改正如下：
```cpp
vector<int>::iterator iter = iv.begin(), \
                      mid = iv.begin() + iv.size() / 2;
while (iter != mid) {
    if (*iter == some_val) iv.insert(iter++, 2 * some_val);
    else iter++;
}
```

## 练习9.23

>在本节第一个程序（第309页）中，若c.size()为1，则val1、val2、val3和val4的值会是什么？

val1：首迭代器指向的元素  
val2：第一个元素  
val3：尾迭代器前的一个元素  
val4：最后一个元素  
**以上均为c中唯一元素**

## [练习9.24](_24.cpp)

>编写程序，分别使用at、下标运算符、front和begin提取一个vector中的第一个元素。在一个空vector上测试你的程序。

VSCode+MinGW环境程序闪退。

## 练习9.25

>对于第312页中删除一个范围内元素的程序，如果elem1与elem2相等会发生什么？如果elem2是尾后迭代器，或者elem1和elem2皆为尾后迭代器，又会发生什么？

* elem1与elem2相等，他们之间没有任何元素，因此不删除任何元素
* elem2是尾后迭代器，删除elem1之后的所有元素
* elem1和elem2皆为尾后迭代器，他们之间没有任何元素，因此不删除任何元素

## [练习9.26](_26.cpp)

>使用下面代码定义的ia，将ia拷贝到一个vector和一个list中。使用单迭代器版本的erase从list中删除奇数元素，从vector中删除偶数元素。  
>```cpp
>int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
>```

```cpp
vector<int> a(ia, end(ia)); // vector拷贝数组
```

## [练习9.27](_27.cpp)

>编写程序，查找并删除forward_list<int>中的奇数元素。


## [练习9.28](_28.cpp)

>编写函数，接受一个forward_list<string>和两个string共三个参数。函数应在链表查找第一个string，并将第二个string插入紧接着第一个string之后的位置。若第一个string未在链表中，则将第二个string插入到链表末尾。

```cpp
int answer28(forward_list<string>& t, const string& a, const string& c); // t为引用类型，a，c不可变
```

## 练习9.29

>假定vec包含25个元素，那么vec.resize(100)会做什么？如果接下来调用vec.resize(10)会做什么？

```cpp
C<c> vec;
vec.resize(25);
vec.resize(100); // 将75个元素进行值初始化并添加到vec的末尾。
vec.resize(10); // 从vec中删除90个元素。
```

## 练习9.30

>接受单个参数的resize版本对元素类型有什么限制（如果有的话）?

元素类型必须提供一个默认构造函数。

## 练习9.31

>第316页中删除偶数值元素并复制奇数值元素的程序不能用在list或forward_list。为什么？修改程序，使之也能用于这些类型。

list不能使用复合复制语句。
```cpp
iter += 2; // 此行，改为下行。
iter++; iter++;
```

forward_list在删除元素时，需要改变删除元素之前的元素。如程序[_31.cpp](_31.cpp)。

## 练习9。32

>在第316页的程序中，向下面语句这样调用insert是否合法？如果不合法，为什么？
>```cpp
>iter = vi.insert(iter, *iter++);
>```

不合法，自增运算优先级高于取值运算。

## [练习9.33](_33.cpp)

>在本节最后一个例子中，如果不将insert的结果赋予begin，将会发生什么？编写程序，去掉赋值语句，验证你的答案。

begin会失效。

## [练习9.34](_34.cpp)

>假定vi是一个保存int的容器，其中有偶数值也有奇数值，分析下面循环的行为，然后编写程序验证你的分析是否正确。
>```cpp
>iter = vi.begin();
>while (iter != vi.end())
>    if (*iter % 2)
>        iter = vi.insert(iter, *iter);
>++iter;
>```

如果vi中没有奇数元素，则不进行任何操作。
如果vi中有奇数元素，则无限循环复制vi中第一个奇数元素。

## 练习9.35

>解释一下vector的capacity和size有何区别。

* capacity：不重新分配内寸的情况下，容器可存储的元素数量。
* size：容器中元素的数量。

## 练习9.36

>一个容器的capacity可能小于size吗？

不可能。

## 练习9.37

>为什么list或array没有capacity成员函数？

* list是链表，保存多少元素就是用多少空间。
* array是长度不可变的容器。

##[练习9.38](_38.cpp)

>编写程序，探究你的标准库实现中，vector是如何增长的。

当需要分配新内存空间时加倍。

## 练习9.39

>解释下面程序片段做了什么：
>```cpp
>vector<string> svec;
>svec.reserve(1024);
>string word;
>while (cin >> word)
>    svec.push_back(word);
>svec.resize(svec.size() + svec.size() / 2);
>```

```cpp
vector<string> svec; // 定义string的vector：svec。
svec.reserve(1024); // 分配至少能存储1024个元素的容量。
string word; // 定义string变量：word。
while (cin >> word) // 从标准输入接受word
    svec.push_back(word); // 将word添加到svec中。
svec.resize(svec.size() + svec.size() / 2); // 循环结束，将svec容量大小设置为svec中元素数量的1.5倍。
```

## 练习9.40

>如果上一题中的程序读入256个词，在resize之后容器的capacity可能是多少？如果读入512个、1000个或1048个呢？

* 512个：capacity为1048
* 1000个：capacity为2048（当需要重新分配新内存空间时加倍情况）
* 1048个：capacity为4096（当需要分配新内存空间时加倍情况）

## [练习9.41](_41.cpp)

>编写程序，从一个vector<char>初始化一个string。

## 练习9.42

>假定你希望每次读取一个字符存入一个string中，而且知道最少读取100个字符，应该如何提高程序的性能？

```cpp
string s;
s.reserve(100); // 预先分配100个元素空间。
```

## [练习9.43](_43.cpp)

>编写一个函数，接受三个string参数s、oldVal、newVal。使用迭代器及insert和erase函数将s中所有oldVal替换为newVal。测试你的程序，用它替换通用的简写形式，如，将"tho"替换为"though"，将"thus"替换为"through"。

## [练习9.44](_44.cpp)

>重写上一题函数，这次使用一个下标和replace。

## [练习9.45](_45.cpp)

>编写一个函数，接受一个表示名字的string参数和两个分别表示前缀（如"Mr."或"Ms."）和后缀（如"Jr."或"III"）的字符串。使用迭代器insert和append函数将前缀和后缀添加到给定的名字中，将生成的新string返回。

## [练习9.46](_46.cpp)

>重写上一题函数，这次使用位置和长度来管理string，并只使用insert。

## [练习9.47](_47.cpp)

>编写程序，首先查找string"ab2c3d7R4E6"中的每个数字字符，然后查找其中每个字母字符。编写两个版本的程序，第一个使用find_first_of，第二个使用find_first_not_of。

## 练习9.48

>假定name和numbers的定义如325页所示，number.find(name)返回什么？

 返回`string::npos`

## [练习9.49](_49.cpp)

>如果一个字母延伸到中线之上，如d或f，则称其有上出头部分（ascender）。如果一个字母延伸到中线以下，如p或g，则称其有下出头部分（descender）。编写程序，读入一个单词文件，输出最长的既不包含上出头部分，也不包含下出头一部分的单词。

## [练习9.50](_50.cpp)

>编写程序处理一个vector<string>，其元素都表示整型值。计算vector中的所有元素之和。修改程序，使之计算表示浮点值的string之和。

## [练习9.51](_51.cpp)

>设计一个类，它有三个unsigned成员，分别表示年、月和日。为其编写构造函数，接受一个表示日期的string参数。你的构造函数应该能处理不同数据格式，如January,1,1900、1/1/1990、Jan 1 1900等。

## [练习9.52](_52.cpp)

>使用stack处理括号化的表达式。当你看到一个左括号，将其记录下来。当你在一个左括号之后看到一个右括号，从stack中pop对象，直至遇到左括号，将左括号也一起弹出栈。然后将一个值（括号内的运算结果）push到栈中，表示一个括号化的（子）表达式已经处理完毕，被其运算结果替代。