#include<iostream>
#include<list>
#include<vector>
using namespace std;

int main() {
    list<const char*> a{"hello", "world"};
    vector<string> name0;
    name0.assign(a.cbegin(), a.cend());
    for (auto i : name0) cout << i << " ";
    cout << endl;
    system("pause");
    return 0;
}