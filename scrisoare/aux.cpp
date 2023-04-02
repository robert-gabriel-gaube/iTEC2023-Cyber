#include <iostream>
#include <vector>
using namespace std;
#define MAX 30
#define A 12
#define B 24
#define C 19
#define D 23 
#define E 0
#define F 12
#define G 25
#define H 6
#define I 15

#define EC1 15
#define EC2 4
#define EC3 21

vector<int> valori {1, 9, 18, 21, 25, 0, 1, 19, 24, 25, 6, 11, 22, 24, 24, 19, 13, 12, 13, 1, 0, 22, 9, 3, 18, 15, 5, 17, 23, 0, 9, 18, 19, 0, 2, 10, 15, 11, 8, 7, 12, 3, 1, 23, 22, 5, 10, 9, 24, 3, 23, 9, 25, 18, 19, 12, 1, 11, 0, 19, 23, 16, 3};

int main() {   
    for(int index = 0; index < valori.size() ;index = index + 3) {
        for(int i = 0; i < MAX; ++i) {
            for(int j = 0; j < MAX; ++j) {
                for(int z = 0; z < MAX; ++z) {
                    if((A*i + B*j + C*z) % 26 != valori[index]) continue;
                    if((D*i + E*j + F*z) % 26 != valori[index+1]) continue;
                    if((G*i + H*j + I*z) % 26 != valori[index+2]) continue;
                    while(i < 'a') i+= 26;
                    while(i > 'z') i-= 26;

                    while(j < 'a') j+= 26;
                    while(j > 'z') j-= 26;

                    while(z < 'a') z+= 26;
                    while(z > 'z') z-= 26;
                    cout << char(i) << char(j) << char(z);
                }
            }
        }
    }
    return 0;
}