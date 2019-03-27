#include<iostream>
#include<fstream>
using namespace std;

void findV(const string& s, string& c) {
    string upDown{"bdfghijklpqty"};
    int vLength;
	if (s.find_first_of(upDown) == string::npos) {
		c = c.size() < s.size() ? s : c;
	}
}

int main() {
	ifstream ifs("D:/test001.txt");
	if (!ifs)
		return -1;
	string longest;
	for (string curr; ifs >> curr; ) {
		findV(curr, longest);
	}
	cout << longest << endl;
    system("pause");
    return 0;
}