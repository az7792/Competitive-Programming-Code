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
void solve()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    string a, b;
    a = str;
    b = str;
    for (auto &v : a)
        if (v == '?')
            v = '0';
    for (auto &v : b)
        if (v == '?')
            v = '1';
    int ct = 0, ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == '0')
            ct++;
        else
        {
            ans = max(ans, ct);
            ct = 0;
        }
    }
    ans = max(ans, ct);
    ct = 0;
    for (int i = 0; i < n; ++i)
    {
        if (b[i] == '1')
            ct++;
        else
        {
            ans = max(ans, ct);
            ct = 0;
        }
    }
    ans = max(ans, ct);
    cout << ans << endl;
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