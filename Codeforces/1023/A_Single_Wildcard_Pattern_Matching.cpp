#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
#define fi first
#define se second
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void solve()
{
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    if (s.find('*') == string::npos)
    {
        if (s == t)
            cout << "YES\n";
        else
            cout << "NO\n";
        return;
    }
    if (s.size() - 1 > t.size())
    {
        cout << "NO\n";
        return;
    }
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '*')
            break;
        if (s[i] != t[i])
        {
            cout << "NO\n";
            return;
        }
    }
    for (int i = 1; i < n; ++i)
    {
        if (s[n - i] == '*')
            break;
        if (s[n - i] != t[m - i])
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*




*/