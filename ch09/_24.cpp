#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> a;
    cout << a.at(0);
    cout << a[0];
    cout << a.front();
    cout << *a.begin(); // 解引用
    system("pause");
    return 0;
}