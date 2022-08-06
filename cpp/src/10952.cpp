/*
https://www.acmicpc.net/problem/10952

두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.
입력은 여러 개의 테스트 케이스로 이루어져 있다.
각 테스트 케이스는 한 줄로 이루어져 있으며, 각 줄에 A와 B가 주어진다. (0 < A, B < 10)
입력의 마지막에는 0 두 개가 들어온다.

각 테스트 케이스마다 A+B를 출력한다.
*/

// TODO Do-While 

#include <iostream>

using namespace std;

int main (void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int A, B;

    while (true) {
        cin >> A >> B;
        if ((A == 0 && B == 0)) {
            break;
        }
        else {
            cout << A + B << "\n";
        }
    }

    return 0;
}