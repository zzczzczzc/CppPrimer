#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

size_t bigerThanSix(vector<string>& words) {
    return count_if(words.begin(), words.end(),
                        [](const string& a) { return a.size() <= 6; });
}

int main() {
    vector<string> words{"the", "quick", "red", "fox", "jumps",
                             "over", "the", "slow", "red", "turtle"};
    cout << bigerThanSix(words) << endl;
    system("pause");
    return 0;
}