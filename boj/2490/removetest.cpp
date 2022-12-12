#include <string>
#include <iostream>
#include <algorithm>

int main(void) {
    std::string original = "Hello My Name Is Jaemin.\n";
    std::cout << original;
    original.erase(std::remove_if(original.begin(), original.end(), ::isspace), original.end());
    std::cout << original;
    return 0;
}
