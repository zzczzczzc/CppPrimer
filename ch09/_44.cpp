#include<iostream>
using namespace std;

void changeS(string& s, const string& oldVal, const string& newVal) {
	for (size_t pos = 0; pos <= s.size() - oldVal.size(); ) {
		if (s[pos] == oldVal[0] && s.substr(pos, oldVal.size()) == oldVal) {
			s.replace(pos, oldVal.size(), newVal);
			pos += newVal.size();
		} else
			pos++;
	}
}

int main() {
    string s("To drive straight thru is a foolish, tho courageous act.");
    changeS(s, "tho", "though");
    changeS(s, "thou", "through");
    cout << s << endl;
    system("pause");
    return 0;
}