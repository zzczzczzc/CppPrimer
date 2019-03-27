#include<iostream>
#include<iterator>
#include<list>
#include<algorithm>

using namespace std;

int main() {
    list<int> la{0, 1, 2, 3, 0, 5, 6, 7, 8, 9};
    auto i = find(la.crbegin(), la.crend(), 0);
    cout << distance(i, la.crend()) << endl;
    system("pause");
    return 0;
}