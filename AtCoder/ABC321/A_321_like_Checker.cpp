#include <iostream>

bool is321Like(int n) {
    int prevDigit = n % 10;
    n /= 10;
    
    while (n > 0) {
        int currentDigit = n % 10;
        if (currentDigit <= prevDigit) {
            return false;
        }
        prevDigit = currentDigit;
        n /= 10;
    }
    
    return true;
}

int main() {
    int N;
    std::cin >> N;
    
    if (is321Like(N)) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
    
    return 0;
}
