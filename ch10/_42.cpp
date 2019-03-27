#include<iostream>
#include<list>

using namespace std;

void elimDups(list<string>& lst) {
    lst.sort();
    lst.unique();
}

int main() {
    list<string> lst{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    elimDups(lst);
    for (const auto& i : lst) cout << i << " ";
    system("pause");
    return 0;
}