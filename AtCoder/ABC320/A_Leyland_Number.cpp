#include <iostream>
#include <cmath>

int main() {
    long long A, B;
    std::cin >> A >> B;
    
    long long result = pow(A, B) + pow(B, A);
    
    std::cout << result << std::endl;
    
    return 0;
}
