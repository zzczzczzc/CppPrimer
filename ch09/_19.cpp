#include<iostream>
#include<list>

using namespace std;

int main() {
    list<string> name;
    for (string a; a != "0"; name.push_back(a))
        cin >> a;
    for (auto c = name.cbegin(); c != name.cend(); c++)
        cout << *c << endl;
    system("pause");
    return 0;
}