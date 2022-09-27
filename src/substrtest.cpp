#include <string>
#include <iostream>

int main (void) {
    std::string a = "012345";
    std::cout << a.substr(0, 5) << std::endl;
    std::cout << a.substr(0, 6) << std::endl;
    
}
