#include<iostream>
#include<vector>
#include<algorithm>
#include<list>

using namespace std;

int main() {
    vector<int> v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> a;
    list<int> b;
    list<int> c;
    copy(v.cbegin(), v.cend(), back_inserter(a));
    cout << "back_inserter:";
    for (auto i : a) cout << i << " ";
    cout << endl;
    copy(v.cbegin(), v.cend(), front_inserter(b));
    cout << "front_inserter:";
    for (auto i : b) cout << i << " ";
    cout << endl;
    copy(v.cbegin(), v.cend(), inserter(c, c.begin()));
    cout << "inserter:";
    for (auto i : c) cout << i << " ";
    cout << endl;
    system("pause");
    return 0;
}