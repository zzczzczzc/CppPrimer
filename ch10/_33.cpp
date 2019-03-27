#include<iostream>
#include<fstream>
#include<vector>
#include<iterator>
#include<algorithm>

using namespace std;

void change(char* in, char* out1, char* out2) {
    ifstream ift(in);
    ofstream oftOdd(out1), oftEven(out2);
    istream_iterator<int> in1(ift), eof;
    ostream_iterator<int> oftOddOdd(oftOdd, " "), oftEvenEven(oftEven, " ");

    for_each(in1, eof, 
                [& oftOddOdd, & oftEvenEven](const int i)
                { *(i & 0x1 ? oftOddOdd : oftEvenEven)++ = i; });
}

int main() {
    change("d:/test002.txt", "d:/outOdd.txt", "d:/outEven.txt");
    return 0;
}