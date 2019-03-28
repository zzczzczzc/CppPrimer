#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

void add(map<string, vector<string>>& family) {
    string familyName, childName;
    cout << "print family name:";
    cin >> familyName;
    cout << "print child name:";
    cin >> childName;
    family[familyName].push_back(childName);
}

void showFamily(map<string, vector<string>>& family) {
    for (const auto& w : family) {
        cout << "family:" << w.first << endl;
        for (const auto& e : w.second) {
            cout << "child:" << e << endl;
        }
    }
    cout << endl;
}

int main() {
    map<string, vector<string>> family;
    int select;
    while (1) {
        cout << "1.Add a family" << endl;
        cout << "2.Add a child" << endl;
        cout << "3.ls" << endl;
        cout << "0.exit" << endl;
        cin >> select;
        switch (select) {
            case 1:
                add(family); break;
            case 2:
                add(family); break;
            case 3:
                showFamily(family); break;
            case 0:
                return 0;
            default:
                break;
        }
    }
}