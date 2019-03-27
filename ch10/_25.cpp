#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;
using namespace std::placeholders;

void elimDups(vector<string>& v) {
    auto i = unique(v.begin(), v.end());
    v.erase(i, v.end());
}

bool bigerThanSZ(const string& a, vector<string>::size_type sz) {
    return a.size() >= sz;
}

bool outPut(const string& s) {
    cout << s << " ";
    return true;
}

void biggies(vector<string>& words, vector<string>::size_type sz) {
    elimDups(words);
    auto f = partition(words.begin(), words.end(), bind(bigerThanSZ, _1, sz));
    for_each(words.begin(), f, bind(outPut, _1));
}

int main() {
    vector<string> words{"the", "quick", "red", "fox", "jumps",
                             "over", "the", "slow", "red", "turtle"};
    biggies(words, 5); cout << endl;
    system("pause");
    return 0;
}