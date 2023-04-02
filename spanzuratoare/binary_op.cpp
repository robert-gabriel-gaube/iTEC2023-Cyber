#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;
int char_to_int(char c) {
    return c - '0';
}
vector<char> get_chars(int index) {
    ifstream f("new_chars.txt");
    string line;
    vector<char>chars;
    getline(f, line);
    while(char_to_int(line[0]) != index / 10 || char_to_int(line[1]) != index % 10) {
        getline(f, line);
    }
    for(size_t i = 4 ; i < line.size(); ++i) {
        chars.push_back(line[i]);
    }
    f.close();
    return chars;
}
int main() {
int x = 49, y = 7;
vector<char>chars1 = get_chars(49);
vector<char>chars2 = get_chars(7);

set<char> stmp1;
set<char> stmp2;
	for(char tmp1c : chars1) {
		for(char tmp2c : chars2) {
			int tmp1 = static_cast<int>(tmp1c);
			int tmp2 = static_cast<int>(tmp2c);
			if((((tmp1 >> 1) * (tmp2 << 3))) != 10816 ){
				continue;
			}
			stmp1.insert(tmp1c); stmp2.insert(tmp2c);
		}
	}
    cout << stmp1.size() << " " << stmp2.size() << endl;
    ofstream o("remainder.txt");
    if(x < 10) {
        o << 0 << x << ": ";
    }
    else {
        o << x << ": ";
    }
    for(char c1 : stmp1) {
        o << c1;
    }
    o << '\n';

    if(y < 10) {
        o << 0 << y << ": ";
    }
    else {
        o << y << ": ";
    }
    for(char c2 : stmp2) {
        o << c2;
    }

    o << '\n';
    o.close();
    return 0;
}