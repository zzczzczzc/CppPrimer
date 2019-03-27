#include<iostream>
#include<list>
#include<vector>
using namespace std;

int main() {
    const int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    vector<int> a(ia, end(ia));
    list<int> b(a.begin(), a.end());
    vector<int>::iterator j = a.begin();
    for (auto i = a.begin(); i != a.end(); ) {
        if (*i & 0x1) i = a.erase(i);
        else i++;
    }
    for (auto i = b.begin(); i != b.end(); ) {
        if (!(*i & 0x1)) i++;
        else i = b.erase(i);
    }
    return 0;
}