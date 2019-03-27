#include<iostream>
#include<deque>

using namespace std;

int main() {
    deque<string> name;
    for (string a; a != "0"; name.push_back(a))
        cin >> a;
    for (auto c = name.cbegin(); c != name.cend(); c++)
        cout << *c << endl;
    system("pause");
    return 0;
}