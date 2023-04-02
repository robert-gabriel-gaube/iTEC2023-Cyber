#include <iostream>
using namespace std;
int main() {
    long long sum_v = 15;
    cout << "{";
    for(long y = 0; y < 1000; ++y) {
        if((sum_v + y * 26) % 19 == 0) {
            cout << (sum_v + y * 26) / 19 << ", ";
        }
    }
    cout << "};" << endl;
    return 0;
}