#include<iostream>
#include<vector>
using namespace std;

vector<int>::const_iterator find886(auto begin, auto end, int x) {
    while (begin != end) {
        if (*begin == x)
            return begin;
        begin++; // 此时先判断后自增
    }
    return end; // end并不指向任何值
}

int main() {
    vector<int> c = {2, 4, 5, 6, 4, 4, 56};
    int x = 56;
    vector<int>::const_iterator cc;
    cc = find886(c.begin(), c.end(), x);
    cout << *cc;
    system("pause");
    return 0;
}