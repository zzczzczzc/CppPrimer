#include<iostream>
#include<algorithm>
#include<list>
using namespace std;

int main() {
    list<string> s{"a", "ab", "ab", "abc", "abc", "abc", "abcd", "abcd", "abcd", "abcd"};
    cout << count(s.begin(), s.end(), "abc");
    system("pause");
    return 0;
}