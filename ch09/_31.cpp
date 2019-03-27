#include<iostream>
#include<forward_list>
using namespace std;

int main() {
    forward_list<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto beforeIter = vi.before_begin();
    auto iter = vi.begin();
    while (iter != vi.end()) {
        if (*iter % 2) {
            iter = vi.insert_after(beforeIter, *iter);
            iter++; iter++;
            beforeIter++; beforeIter++;
        } else
            iter = vi.erase_after(beforeIter);
    }
    return 0;
}