#include<iostream>
#include<list>
#include<vector>
using namespace std;

bool equal(vector<int> a, vector<int> b) {
    if(a == b) return true;
    else return false;
}

int main() {
    vector<int> name0{1, 2, 3, 4, 5};
    vector<int> name1{1, 2, 3, 4, 5};
    equal(name0, name1) ? cout << "true" : cout << "false";
    system("pause");
    return 0;
}