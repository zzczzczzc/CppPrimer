#include<iostream>
#include<iterator>
#include<vector>

using namespace std;

int main() {
    vector<int> v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto i = v.cend(); i != v.cbegin();)
        cout << *(--i)<< " ";
    system("pause");
    return 0;
}