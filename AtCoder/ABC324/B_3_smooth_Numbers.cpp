#include <iostream>
using namespace std;

int main() {
    long long N;
    cin >> N;

    while (N % 2 == 0) {
        N /= 2;
    }

    while (N % 3 == 0) {
        N /= 3;
    }

    if (N == 1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
