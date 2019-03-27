#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<char> t{'H', 'e', 'l', 'l', 'o'};
    string s(t.begin(), t.end());
    cout << s << endl;
    system("pause");
    return 0;
}