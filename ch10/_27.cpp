#include<iostream>
#include<list>
#include<vector>
#include<algorithm>

using namespace std;

void elimDups(vector<string>& v, list<string>& s) {
    auto i = unique_copy(v.begin(), v.end(), back_inserter(s));
}

int main() {
    vector<string> v = {"1", "22", "22", "333", "333", "333"};
    list<string> s;
    elimDups(v, s);
    for (auto i : s) cout << i << " ";
    system("pause");
    return 0;
}