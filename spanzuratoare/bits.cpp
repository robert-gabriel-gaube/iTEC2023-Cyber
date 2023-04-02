#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#define POS 45
int main()
{
    vector<char> s;
    for (int tmp1 = ' '; tmp1 <= '~'; ++tmp1)
    {
if (((tmp1 >> 5) & 83) != 3){
		continue;
}
else if (((tmp1 >> 4) & 178) != 2){
		continue;
}
else if (((tmp1 >> 4) & 22) != 6){
		continue;
}
        s.push_back(tmp1);
    }
    ofstream f("char_compare.txt", ios_base::app);
    f << POS << ": ";
    for (char c : s)
    {
        f << c;
    }
    f << '\n';
    f.close();
    return 0;
}