#include <iostream>
#include <vector>
struct Subject {
    int C;
    double G;
    Subject(int C, double G): C(C), G(G) {}
    Subject(void): C(0), G(0) {}
    Subject(const Subject& c): C(c.C), G(c.G) {}
};

int getTotalC (const std::vector<struct Subject> &s) {
    int t_c = 0;
    for (const auto& ss: s) {
        t_c += ss.C;
    }
    return t_c;
}
double getGPA (const std::vector<struct Subject> &s) {
    double gpa = 0;
    int t_c = getTotalC(s);
    for (const auto &ss: s) {
        gpa += ss.C * ss.G;
    }
    gpa /= t_c;
    return gpa;
}

int main(void) {
    int T;
    std::cin >> T;
    std::vector<std::vector<struct Subject>> sem(T);

    for (int i = 0; i < sem.size(); i++) {
        int N;
        std::cin >> N;
        sem[i].resize(N);
        for (int j = 0; j < N; j++) {
            int C; 
            double G;
            std::cin >> C >> G;
            sem[i][j] = Subject(C, G);
        }
    }

    std::vector<struct Subject> result(T);

    for (int i = 0; i < result.size(); i++) {
        result[i].C = getTotalC(sem[i]);
        result[i].G = getGPA(sem[i]);
    }
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i].C << " " << result[i].G << std::endl;
    }

    return 0;
}
