#include <iostream>
#include <vector>
#include <algorithm>

const std::size_t P_NUM = 9;
const std::size_t A_NUM = 7;
const std::size_t H_SIZE = 100;

std::size_t vecSum(const std::vector<int> &v) {
    std::size_t sum = 0; for (const auto &e: v) sum += e;
    return sum;
}
void printVec(const std::vector<int> &v) {
    for (const auto &e: v)
        std::cout << e << '\n';
    return;
}

int main(void) {
    // Input 9 heights
    std::vector<int> p_vec(P_NUM);
    for (std::size_t i = 0; i < P_NUM; ++i)
        std::cin >> p_vec[i];
    // p index is a, b, c 
    std::vector<int> ans_v(A_NUM);

    for (std::size_t a = 0; a < P_NUM - 6; ++a) {
        for (std::size_t b = a + 1; b < P_NUM - 5; ++b) {
            for (std::size_t c = b + 1; c < P_NUM - 4; ++c) {
                for (std::size_t d = c + 1; d < P_NUM - 3; ++d) {
                    for (std::size_t e = d + 1; e < P_NUM - 2; ++e) {
                        for (std::size_t f = e + 1; f < P_NUM - 1; ++f) {
                            for (std::size_t g = f + 1; g < P_NUM; ++g) {
                                std::vector<int> ans { p_vec[a], p_vec[b], p_vec[c], p_vec[d], p_vec[e], p_vec[f], p_vec[g] };
                                if (vecSum(ans) == H_SIZE) {
                                    std::sort(ans.begin(), ans.end());
                                    printVec(ans);
                                    return 0;
                                }
                            }
                        }
                    }
                }
                
            }
        }
    }
    return 0;
}
