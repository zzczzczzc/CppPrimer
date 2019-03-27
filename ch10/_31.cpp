#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>

using namespace std;

int main() {
    istream_iterator<int> in_iter(cin), eof;
    vector<int> v;
    copy(in_iter, eof, back_inserter(v));
    sort(v.begin(), v.end());
    unique_copy(v.begin(), v.end(), ostream_iterator<int>(cout, " ")); cout << endl;
    system("pause");
    return 0;
}