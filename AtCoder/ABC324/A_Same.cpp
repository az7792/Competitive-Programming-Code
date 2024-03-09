#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    int firstValue, currentValue;
    cin >> firstValue;
    
    bool allEqual = true;
    
    for (int i = 1; i < N; i++) {
        cin >> currentValue;
        if (currentValue != firstValue) {
            allEqual = false;
            break;
        }
    }
    
    if (allEqual) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}
