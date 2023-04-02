#include <fstream>
#include <iostream>
using namespace std;
#define ll long long
int main() {
    ofstream o("keys.txt");
    ifstream f1("rezultat1.txt");
    ll a, b, c, d, e, f, g, h, i;
    while(!f1.eof()){
        f1 >> a >> b >> c;
        ifstream f2("rezultat2.txt"); 
        while(!f2.eof()) {
            f2 >> d >> e >> f;
            ifstream f3("rezultat3.txt");
            while(!f3.eof()) {
                f3 >> g >> h >> i;
                ll nums[] {a, b, c, d, e, f, g, h, i};
                ll adder = 26;
                for(ll i = 0; i < 9; ++i) {
                    if(nums[i] > 'z' || nums[i] < 'a') {
                        if(nums[i] > 'z') adder = -26;
                        else adder = 26;
                        while(nums[i] > 'z' || nums[i] < 'a') {
                            nums[i] += adder;
                        }
                    }
                    cout << nums[i] % 26 << " ";
                    o << char(nums[i]);
                }
                o << '\n';
                cout << '\n';

            }
            f3.close();
        }
        f2.close();
    }
    f1.close();
    o.close();
    return 0;
}