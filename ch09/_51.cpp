#include<iostream>
#include<string>
using namespace std;

class date {
private:
    unsigned int day, month, year;
    
	void convert_month(const string& s) {
		if (s.find("Jan") < s.size())  month = 1;
		if (s.find("Feb") < s.size())  month = 2;
		if (s.find("Mar") < s.size())  month = 3;
		if (s.find("Apr") < s.size())  month = 4;
		if (s.find("May") < s.size())  month = 5;
		if (s.find("Jun") < s.size())  month = 6;
		if (s.find("Jul") < s.size())  month = 7;
		if (s.find("Aug") < s.size())  month = 8;
		if (s.find("Sep") < s.size())  month = 9;
		if (s.find("Oct") < s.size())  month = 10;
		if (s.find("Nov") < s.size())  month = 11;
		if (s.find("Dec") < s.size())  month = 12;
	}

    void convert1(const string& s) {
        convert_month(s);
        day = stoi(s.substr(s.find_first_of("1234567890"), s.find_first_of(",") - s.find_first_of("123456789")));
        year = stoi(s.substr(s.find_last_of(",") + 1, 4));
    }

    void convert2(const string& s) {
        day = stoi(s.substr(0, s.find_first_of("/")));
        month = stoi(s.substr(s.find_first_of("/") + 1,  s.find_last_of("/") - s.find_first_of("/")));
        year = stoi(s.substr(s.find_last_of("/") + 1, 4));
    }

    void convert3(const string& s) {
        convert_month(s);
        day = stoi(s.substr(s.find_first_of("1234567890"), s.find_first_of(" ") - s.find_first_of("1234567890")));
        year = stoi(s.substr(s.find_last_of(" ") + 1, 4));
    }
    
public:
    date(const string& s) {
        if (s.find_first_of(",") != string::npos)
            convert1(s);
        else if (s.find_first_of("/") != string::npos)
            convert2(s);
        else if (s.find_first_of(" ") != string::npos)
            convert3(s);
    }
    void print() {
		cout << "day:" << day << " " << "month: " << month << " " << "year: " << year << endl;
	}

};

int main() {
    date d1("1/1/1990");
	date d2("January 1,1900");
	date d3("Jan 1 1900");

	d1.print();
	d2.print();
	d3.print();

    system("pause");
    return 0;
}