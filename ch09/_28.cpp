#include<iostream>
#include<forward_list>

using namespace std;

int answer28(forward_list<string>& t, const string& a, const string& c) {
    auto p = t.before_begin();
    auto q = t.begin();
    for (; q != t.end(); p = q, q++) {
        if (*q == a) {
            t.insert_after(q, c);
            return 1;
        }
    }
    t.insert_after(p, c);
    return 0;
}

int main() {
    forward_list<string> s{"sdfsd", "dsfsdfsgaa", "qwrwer", "a", "cvbxcvbhl"};
    string a = "ccc", b = "b";
    answer28(s, a, b);
    for (auto qq = s.begin(); qq != s.end(); qq++) {
        cout << *qq << endl;
    }
    system("pause");
    return 0;
}