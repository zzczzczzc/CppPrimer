#include<iostream>
#include<vector>
#include<set>

using namespace std;

int main() {
    vector<string> vec;
    set<string> se;
    string word;
    while (cin >> word && word != "q") {
        vec.push_back(word);
        se.insert(word);
    }
    for (auto i : vec) cout << i << " ";
    cout << endl;
    for (auto i : se) cout << i << " ";
    system("pause");
    return 0;
}