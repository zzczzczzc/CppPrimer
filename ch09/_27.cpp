#include<iostream>
#include<forward_list>

using namespace std;

int main() {
    forward_list<int> a{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto p = a.before_begin();
    auto q = a.begin();
    while (q != a.end())
        if (q % 2)
            q = a.erase_after(p);
        else {
            p = q;
            q++;
        }
    return 0;
}