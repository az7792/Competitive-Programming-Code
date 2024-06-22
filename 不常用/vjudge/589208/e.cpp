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
    ll n;
    cin >> n;
    ll ans = 1e18;
    vector<ll> t;
    t.push_back(0);
    for (int i = 1; i <= n; ++i)
        t.push_back(i);
    for (int i = 1; i <= n; ++i)
        t.push_back(i);
    for (int i = 1; i <= n; ++i)
        t.push_back(i);
    for (int i = 1; i <= n; ++i)
    {
        ll tmp = 0;
        for (int L = i + 1; L <= i + n - 2; ++L)
            tmp += i * t[L] * t[L + 1];
        ans = min(ans, tmp);
    }
    cout << ans;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}