#include <bits/stdc++.h>//jI
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
const ll MAX = 1e6 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void solve()
{
    string s, t;
    cin >> s >> t;
    if (s == t)
    {
        cout << "YES\n";
        return;
    }
    if ((s.size() - t.size()) % 2 == 1 || s[0] != t[0] || s.back() != t.back())
    {
        cout << "NO\n";
        return;
    }
    int L = 1;
    int R = s.size() - 2;
    int i = 1, j = t.size() - 2;
    while (L <= R && i <= j)
    {

        if (s[L] != t[i])
            L += 2;
        else
            L++, i++;
        if (s[R] != t[j])
            R -= 2;
        else
            R--, j--;
    }
    if (i > j)
    {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
