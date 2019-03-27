#include<iostream>
#include<vector>
#include<fstream>
#include<iterator>

using namespace std;

int main() {
    ifstream test("d:/test001.txt");
    istream_iterator<string> in_iter(test), eof;
    vector<string> s;
    copy(in_iter, eof, back_inserter(s));
    for (auto i : s) cout << i << endl;
    system("pause");
    return 0;
}