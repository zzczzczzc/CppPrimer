#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> a;
    for (int i = 0; i < 100; i++) {
		cout << "size: " << a.size() << "  capacity: " << a.capacity() << endl;
		a.push_back(i);
	}
    system("pause");
    return 0;
}