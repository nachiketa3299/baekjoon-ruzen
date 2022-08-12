// https://www.acmicpc.net/problem/8958
// 2022-08-11

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
const char COR_MARK = 'O';

// TODO CPP Lambda Function

const int calContCorMark (const string str, const int i) {
	int cor_num = 0;
	for_each(str.begin(), str.end(), [](const char c){cor_num += (c == COR_MARK) ? 1 : 0});
	return cor_num;
}

const int calTotalScore (const string str) {
	int score = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == COR_MARK) {
			score += calContCorMark(str, i);
		}
	}
}

int main (void) {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		cout << calTotalScore(str) << endl;
	}

	return 0;
}