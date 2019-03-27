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
    stable_sort(words.begin(), words.end(),
                    [](const string& a, const string& b) { return a.size() < b.size(); });
    auto f = find_if(words.begin(), words.end(),
                        [sz](const string& a) { return a.size() >= sz; });
    for_each(f, words.end(),
                [](const string& s) { cout << s << " "; });
}

int main() {
    vector<string> words{"the", "quick", "red", "fox", "jumps",
                             "over", "the", "slow", "red", "turtle"};
    biggies(words, 5); cout << endl;
    system("pause");
    return 0;
}