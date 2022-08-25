#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool hasTwoConsOne (vector<int> arr) {
    for (int i = 0; i < arr.size() - 2;) {
        if (arr[i] == 1) {
            if (arr[i + 1] == 1) {
                if (arr[i + 2] == 1) {
                    return true;
                } else if (arr[i + 2] != 1) {
                    i += 2;
                }
            } else if (arr[i + 1] != 1) {
                i += 1;
            }
        } else {
            i += 1;
        }
    }
    return false;
}

vector<vector<int>> permutation (vector<int> arr, int n) {
    vector<vector<int>> perm_set;
    vector<bool> bs(arr.size() - n, false);

    bs.resize(arr.size(), true);
    sort(arr.begin(), arr.end());

    do {
        vector<int> sub_arr;
        for (int i = 0; i < bs.size(); i++) {
            if (bs[i]) {
                sub_arr.push_back(arr[i]);
            }
        }
        perm_set.push_back(sub_arr);
    } while (next_permutation(bs.begin(), bs.end()));


    return perm_set;
}

int main (void) {
    vector<int> arr1 = {1, 1, 1, 2};
    vector<int> arr2 = {1, 1, 3, 3};
    vector<int> arr3 = {1, 1, 2, 1, 1, 2, 1, 1};
    vector<int> arr4 = {1, 1, 2, 1, 1, 2, 1, 1, 1};

    cout << hasTwoConsOne(arr1) << endl;
    cout << hasTwoConsOne(arr2) << endl;
    cout << hasTwoConsOne(arr3) << endl;
    cout << hasTwoConsOne(arr4) << endl;
    return 0;
}