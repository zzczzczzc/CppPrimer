#include<iostream>
#include<vector>
#include <string>
#include<algorithm>
#include<functional>

using namespace std;
using namespace std::placeholders;

bool check_size(size_t sz, string& s) {
    return s.size() < sz;
}

int main() {
    string s = "abcdefghijklmnopqrstuvwxyz";
    vector<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9, 999};
    auto f = find_if(a.begin(), a.end(), bind(check_size, _1, s));
    if (f != a.end())
		cout << *f << endl;
    system("pause");
    return 0;
}