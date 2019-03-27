#include<iostream>
using namespace std;

string addChange(string& name, const string& a, const string& z) {
    name.insert(name.begin(), a.cbegin(), a.cend());
    name.append(z);
    return name;
}

int main() {
    string s{"who"};
    cout << addChange(s, "Mr.", " Jr.") << endl;
    system("pause");
    return 0;
}