#include <iostream>
#include <fstream>
#include <vector>
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
    for(int i = 0; i < 51; ++i) {
        vector<char> chars = get_chars(i);
        cout << chars[0];
    }
    cout << endl;

    return 0;

}