#include<iostream>
#include<vector>
#include<string>
using namespace std;

double sumVec(vector<string> s) {
    double sum = 0;
    for (auto i = s.begin(); i != s.end(); i++) {
        sum += stod(*i);
    }
    return sum;
}

int main() {
    vector<string> numberA{"1.2", "-2", "3", "4", "5", "6", "7", "-8", "9"};
    cout << sumVec(numberA) << endl;
    system("pause");
    return 0;
}