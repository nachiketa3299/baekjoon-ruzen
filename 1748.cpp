#include <iostream>
#include <cmath>

int getDigit(int n) {
    int digit = 0;
    while (n != 0) { n /= 10; ++digit; }
    return digit;
}

int getDigitNum(int d) {
    // d >= 1
    // d 자릿수의 숫자의 총 갯수
    int digit_num = pow(10, d) - 1 - pow(10, d - 1) + 1;
    return digit_num;
}

int getTotalDigit(int n) {
    int i_n_d = getDigit(n); // number of digit   of input N
    int total_digit = 0;
    for (int cd = 1; cd < i_n_d; ++cd) {
        total_digit += cd * getDigitNum(cd);
    }
    for (int cn = pow(10, i_n_d - 1); cn <= n; ++cn) {
        total_digit += i_n_d;
    }
    return total_digit;
}

int main(void) {
    int N; std::cin >> N;
    std::cout << getTotalDigit(N) << '\n';
    return 0;
}
