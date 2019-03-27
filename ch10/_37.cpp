#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<iterator>

using namespace std;

int main() {
    vector<int> v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> l;
    copy(v.crbegin() + 2, v.crbegin() + 7, back_inserter(l));
    for (auto i : l) cout << i << " ";
    system("pause");
    return 0;
}