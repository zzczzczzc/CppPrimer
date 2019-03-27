#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    vector<int> s{0, 1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6};
    cout << count(s.begin(), s.end(), 6);
    system("pause");
    return 0;
}