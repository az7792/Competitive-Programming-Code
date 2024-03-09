#include <iostream>
#include <string>

using namespace std;

int expandAroundCenter(const string& s, int left, int right) {
    int L = left, R = right;
    while (L >= 0 && R < s.length() && s[L] == s[R]) {
        L--;
        R++;
    }
    return R - L - 1;
}

int longestPalindromeSubstring(const string& s) {
    int maxLength = 0;
    for (int i = 0; i < s.length(); i++) {
        int len1 = expandAroundCenter(s, i, i); // Odd-length palindrome
        int len2 = expandAroundCenter(s, i, i + 1); // Even-length palindrome
        int len = max(len1, len2);
        maxLength = max(maxLength, len);
    }
    return maxLength;
}

int main() {
    string S;
    cin >> S;

    int maxLength = longestPalindromeSubstring(S);
    cout << maxLength << endl;

    return 0;
}
