#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void elimDups(vector<int> v) {
    for (auto i : v)
        cout << i << " ";
    cout << endl;
    auto i = unique(v.begin(), v.end());
    for (auto i : v)
        cout << i << " ";
    cout << endl;
    v.erase(i, v.end());
    for (auto i : v)
        cout << i << " ";
    cout << endl;
}

int main() {
    vector<int> v{0, 1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4};
    elimDups(v);
    system("pause");
    return 0;
}