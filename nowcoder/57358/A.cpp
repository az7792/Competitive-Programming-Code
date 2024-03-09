#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
std::vector<int> computeLPS(const std::string& t) {
    int n = t.length();
    std::vector<int> lps(n, 0);
    int len = 0; // Length of the previous longest prefix suffix

    for (int i = 1; i < n; ) {
        if (t[i] == t[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

int countOccurrences(const std::string& s, const std::string& t) {
    int m = s.length();
    int n = t.length();
    int count = 0;
    std::vector<int> lps = computeLPS(t); // Compute the Partial Match Table for the pattern t.

    int i = 0; // Index for the main string s
    int j = 0; // Index for the pattern t

    while (i < m) {
        if (s[i] == t[j]) {
            i++;
            j++;
        }

        if (j == n) {
            count++;
            j = lps[j - 1];
        } else if (i < m && s[i] != t[j]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    return count;
}
void solve()
{
    int n;
    string t, s;
    cin >> n >> t;
    for (int i = 1; i <= n;++i)
        s += "0";
    if(countOccurrences(t+s+t,t)==2)
        cout << s << endl;
    else{
        for (int i = 1; i <= n;++i)
            cout << "1";
        cout << endl;
    }
}
int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);
    srand(time(nullptr));
    int t = 1;
    //cin >> t;
    t = 100000;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*




*/