#include<iostream>
#include<vector>
using namespace std;

bool find99(vector<int>::const_iterator begin, vector<int>::const_iterator end, int x) {
    while (begin++ != end) {
        if (*begin == x) // 迭代器支持解引用，以指向他对应的值
            return true;
    }
    return false;
}

int main() {
    vector<int> c = {2, 4, 5, 6, 4, 4, 56};
    int x = 4;
    if (find99(c.begin(), c.end(), x))  cout<<"t";
    else  cout<<"f";
    system("pause");
    return 0;
}