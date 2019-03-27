#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// 一元谓词
bool howLong(string& s) {
    return s.size() >= 5;
}

void howMany(vector<string>& v) {
    auto i = partition(v.begin(), v.end(), howLong);
    for(auto j = v.begin(); j != i; j++) {
        cout << *j << " ";
    }
}

int main() {
    vector<string> v{"a", "abcde", "abcdef", "abab", "aaaaa", "esdgrhjkdfoghkdf"};
    howMany(v);
    system("pause");
    return 0;
}