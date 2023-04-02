#include <iostream>
using namespace std;

int results[] {19, 16, 17, 25, 22, 8, 5, 15, 16};
int multiply[] {4, 15, 11, 0, 13, 4, 19, 19, 19};

bool is_solution(int values[]) {
    int a11 = values[0];
    int a12 = values[1];
    int a13 = values[2];
    int a21 = values[3];
    int a22 = values[4];
    int a23 = values[5];
    int a31 = values[6];
    int a32 = values[7];
    int a33 = values[8];

    for(int i = 0; i < 9; i = i + 3) {
        int p11 = multiply[i];
        int p21 = multiply[i + 1];
        int p31 = multiply[i + 2];
        
        int c11 = results[i];
        int c21 = results[i + 1];
        int c31 = results[i + 2];

        int ec1 = ((a11 * p11) + (a12 * p21) + (a13 * p31) ) % 26;
        int ec2 = ((a21 * p11) + (a22 * p21) + (a23 * p31) ) % 26;
        int ec3 = ((a31 * p11) + (a32 * p21) + (a33 * p31) ) % 26;

        if(ec1 != c11) return false;
        if(ec2 != c21) return false;
        if(ec3 != c31) return false;
    }
    return true;
}

void print_solution(int values[]) {
    for(int i = 0; i < 9; ++i) {
        cout << values[i] << " ";
    }
    cout << endl;
} 
void back(int values[], int k) {
    print_solution(values);
    if(k == 9){
         if(is_solution(values)) print_solution(values);
    } else {
        for(int i = 0; i < 31; ++i) {
            values[k] = i;
            back(values, k + 1);
        }
    }

}
int main() {
    int values[10] {0,0,0,0,0,0,0,0,0,0};
    back(values, 0);
    return 0;
}