#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void elimDups(vector<string>& v) {
    auto i = unique(v.begin(), v.end());
    v.erase(i, v.end());
}

void biggies(vector<string>& words, vector<string>::size_type sz) {
    elimDups(words);
    auto f = stable_partition(words.begin(), words.end(),
                        [sz](const string& a) { return a.size() >= sz; });
    for_each(words.begin(), f,
                [](const string& s) { cout << s << " "; });
}

int main() {
    vector<string> words{"the", "quick", "red", "fox", "jumps",
                            "over", "the", "slow", "red", "turtle"};
    biggies(words, 5); cout << endl;
    system("pause");
    return 0;
}