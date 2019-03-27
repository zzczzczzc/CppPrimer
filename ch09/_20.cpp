#include<iostream>
#include<list>
#include<deque>
using namespace std;

int main() {
    list<int> la{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    deque<int> d1;
    deque<int> d2;
    for (auto i : la) {
        if (i % 2 == 0) d1.push_back(i);
        else d2.push_back(i);
    }

    for (auto i : d1) cout << i << " ";
	cout << endl;
	for (auto i : d2) cout << i << " ";
	cout << endl;
    system("pause");
    return 0;
}