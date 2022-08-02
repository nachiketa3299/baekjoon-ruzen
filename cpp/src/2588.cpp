//https://www.acmicpc.net/problem/2588

#include <iostream>
#include <cmath>

using namespace std;

int * intToArr(int);
const int MAX_SIZE = 3;

int main (void) {
    int A, B;
    // A, B length is 3 ex) 472, 385
    //cin >> A;
    //cin >> B;
    A = 472, B = 385;
    int * arr_B = intToArr(B);
    int result[MAX_SIZE + 1];

    for (int i = 0; i < MAX_SIZE; i++) {
        *(result + i) = A * arr_B[i];
    }
    *(result + MAX_SIZE + 1) = A * B;

    for (int i = 0; i < MAX_SIZE + 1; i++) {
        cout << *(result + i) << endl;
    }

    return 0;
}

int * intToArr(int input) {
    // a[] = 375, a[0] = 5, a[1] = 7, a[2] = 3

    // get size of input integer ex) 300's size is 3
    int input_size;
    int temp_input = input;
    for (input_size = 1; (temp_input / 10) != 0; input_size++) {
        temp_input /= 10;
    }
    // Allocate return array
    int * int_arr = new int [input_size];

    for (int i = 0; i < input_size; i++) {
        int t = input / pow(10, i);
        *(int_arr + i) = t - (t / pow(10, 1)) * pow(10, 1);
    }
    return int_arr;
}

// TODO int decimals 