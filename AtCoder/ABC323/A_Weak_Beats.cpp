#include <iostream>
#include <string>

using namespace std;

int main() {
    string S;
    cin >> S;

    bool isPossible = true;

    for (int i = 2; i <= 16; i += 2) {
        if (S[i - 1] != '0') {
            isPossible = false;
            break;
        }
    }

    if (isPossible) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
