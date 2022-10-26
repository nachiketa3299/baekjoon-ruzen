#include <iostream>

struct test {
    int a;
    test(int a): a(a) {}
    test(void): a(0) {}
};

struct test returnTest(int n) {
    struct test t(n);
    return t;
}

int main(void) {
    std::cout << returnTest(3).a << std::endl;
    return 0;
}
