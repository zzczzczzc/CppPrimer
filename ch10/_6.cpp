#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> v(100);
    fill_n(v.begin(), v.size(), 0);
    for (auto i : v)
        cout << i << endl;
    system("pause");
    return 0;
}