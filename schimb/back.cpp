#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
#define MAX_TRIES 100000000000000

int main() {
    int solution[10]; 
    char monede[10];
    for(long long index = 0; index < MAX_TRIES; ++index){
        int negustor_stoc_nomisma = 10;
        int negustor_stoc_solidus = 10;

        int client_stoc_nomisma = 10;
        int client_stoc_solidus = 10;
        int x, y;

        int moneda;
        int schimb;
        int suma;

        for(int i = 0; i < 8; ++i) {
            moneda = rand() % 2;
            if(moneda == 0) {
                monede[i] = 'N';

                x = negustor_stoc_nomisma;
                y = negustor_stoc_solidus;


                suma = client_stoc_nomisma - rand() % 20;
                if(suma + x == 0) suma -= 1;

                solution[i] = suma;

                schimb = y - (x * y) / (x + suma);

                negustor_stoc_nomisma += suma;
                negustor_stoc_solidus -= schimb; 

                client_stoc_nomisma -= suma;
                client_stoc_solidus += schimb;
            } else {
                monede[i] = 'S';

                x = negustor_stoc_solidus;
                y = negustor_stoc_nomisma;

                suma = client_stoc_solidus - rand() % 20;
                if(suma + x == 0) suma -= 1;

                solution[i] = suma;

                schimb = y - (x * y) / (x + suma);

                negustor_stoc_solidus += suma;
                negustor_stoc_nomisma -= schimb;
                
                client_stoc_solidus -= suma; 
                client_stoc_nomisma += schimb;
            }
            //cout << monede[i] << " " << solution[i] << endl;
            if(client_stoc_nomisma + client_stoc_solidus == 39) {
                for(int j = 0; j <= i; ++j) {
                    cout << monede[j] << " " << solution[j] << '\n';
                }
                cout << '\n';
            }
        }

    }

    return 0;
}