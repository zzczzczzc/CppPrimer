#include<iostream>
#include<vector>
#include <string>
#include<algorithm>
#include<functional>

using namespace std;
using namespace std::placeholders;

bool check_size(const string& a, string::size_type sz) {
    return a.size() <= sz;
}

size_t bigerThanSix(vector<string>& words) {
    return count_if(words.cbegin(), words.cend(), bind(check_size, _1, 6));
}

int main() {
    vector<string> words{"the", "quick", "red", "fox", "jumps",
                             "over", "the", "slow", "red", "turtle"};
    cout << bigerThanSix(words) << endl;
    system("pause");
    return 0;
}