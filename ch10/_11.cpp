#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void elimDups(vector<string>& v) {
    auto i = unique(v.begin(), v.end());
    v.erase(i, v.end());
}

bool isShorter(const string& s1, const string& s2) {
    return s1.size() < s2.size();
}

int main() {
    vector<string> v{"a", "a", "ab", "ab", "ab", "abc"};
    elimDups(v);
    stable_sort(v.begin(), v.end(), isShorter);
    for (auto i : v)
        cout << i << " ";
    cout << endl;
    system("pause");
    return 0;
}