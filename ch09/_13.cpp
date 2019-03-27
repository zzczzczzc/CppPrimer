#include<iostream>
#include<list>
#include<vector>
using namespace std;

int main() {
    list<int> a(2, 2);
    vector<double> name0(a.begin(), a.end());
    vector<int> b(2, 2);
    vector<double> name1(b.begin(), b.end());
    for (auto i : a) cout << i << " ";
    cout << endl;
    for (auto j : name0) cout << j << " ";
    cout << endl;

    for (auto i : b) cout << i << " ";
    cout << endl;
    for (auto j : name1) cout << j << " ";
    cout << endl;
    system("pause");
    return 0;
}