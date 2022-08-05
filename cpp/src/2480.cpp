/*
https://www.acmicpc.net/problem/2480
1에서부터 6까지의 눈을 가진 3개의 주사위를 던져서 다음과 같은 규칙에 따라 상금을 받는 게임이 있다. 

같은 눈이 3개가 나오면 10,000원+(같은 눈)×1,000원의 상금을 받게 된다. 
같은 눈이 2개만 나오는 경우에는 1,000원+(같은 눈)×100원의 상금을 받게 된다. 
모두 다른 눈이 나오는 경우에는 (그 중 가장 큰 눈)×100원의 상금을 받게 된다.  
예를 들어, 3개의 눈 3, 3, 6이 주어지면 상금은 1,000+3×100으로 계산되어 1,300원을 받게 된다. 또 3개의 눈이 2, 2, 2로 주어지면 10,000+2×1,000 으로 계산되어 12,000원을 받게 된다. 3개의 눈이 6, 2, 5로 주어지면 그중 가장 큰 값이 6이므로 6×100으로 계산되어 600원을 상금으로 받게 된다.

3개 주사위의 나온 눈이 주어질 때, 상금을 계산하는 프로그램을 작성 하시오.

첫째 줄에 3개의 눈이 빈칸을 사이에 두고 각각 주어진다. 

첫째 줄에 게임의 상금을 출력 한다.

3 3 6 >> 1300
*/

// TODO C++ Random number generation

#include <iostream>
#include <random>

using namespace std; 

void _swap (int * arr, int a, int b) {
    int temp;
    temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
    return;
}

int max(int * arr_ptr, int size) {
    int max_index;
    int copy_arr[3];
    for (int i = 0; i < 3; i++) {
        copy_arr[i] = arr_ptr[i];
    }

    for (int uh_i = 1; uh_i < size; uh_i++) {
        for (int c = 0; c < uh_i; c++) {
            if (copy_arr[c] > copy_arr[uh_i]) {
                for (int j = uh_i; j > c; j--) {
                    _swap(copy_arr, j, j - 1);
                }
                break;
            }
        }
    }
    return copy_arr[2];

    //TODO 3 operand
}

int calculatePrize (int * arr_ptr) {
    if (arr_ptr[0] == arr_ptr[1]) {
        // 0 == 1 , 0 ? 2, 1 ? 2
        if (arr_ptr[1] == arr_ptr[2]) {
            // 0 == 1 == 2
            return 10000 + arr_ptr[1] * 1000;
        } else {
            // 0 == 1 != 2
            return 1000 + arr_ptr[0] * 100;
        }
    } else {
        // 0 != 1, 0 ? 2, 1 ? 2
        if (arr_ptr[0] == arr_ptr[2]) {
            //  0 == 2 != 1
            return 1000 + arr_ptr[0] * 100;
        } else if (arr_ptr[1] == arr_ptr[2]) {
            // 0 != 1, 0 != 2, 1 == 2
            return 1000 + arr_ptr[1] * 100;
        } else {
            // 0 != 1, 0 != 2, 1 != 2
            return max(arr_ptr, 3) * 100;
        }
    }
}

int main (void) {
    int dice_number_array[3]; 
    cin >> dice_number_array[0] >> dice_number_array[1] >> dice_number_array[2];
    cout << calculatePrize(dice_number_array) << endl;
    return 0;
}