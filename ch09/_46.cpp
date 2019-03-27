#include<iostream>
using namespace std;

string addChange(string& name, const string& a, const string& z) {
    name.insert(0, a);
    name.insert(name.size(), z);
    return name;
}

int main() {
    string s{"who"};
    cout << addChange(s, "Mr.", " Jr.") << endl;
    system("pause");
    return 0;
}