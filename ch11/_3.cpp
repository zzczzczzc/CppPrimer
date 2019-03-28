#include<iostream>
#include<map>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
    map<string, size_t> word_count;
    vector<string> vec = {"a", "b", "b", "c", "c", "c", "d", "d", "d", "d"};
    for (auto i = vec.begin(); i != vec.end(); i++) {
        ++word_count[*i];
    }
    for (const auto& w : word_count) {
        cout << w.first << " " << w.second << endl;
    }
    system("pause");
    return 0;
}