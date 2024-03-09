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
    vector<ll> a(n), b(n);
    map<pll, ll> mp;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
        ll g = gcd(a[i], b[i]);
        a[i] /= g;
        b[i] /= g;
        mp[{a[i], b[i]}]++;
    }
    ll ans = 0, res = 0;
    for (auto &[x, y] : mp)
    {
        if (x == pll(1, 1))
            ans += (y - 1) * y / 2;
        else
            res += y * mp[pll(x.second, x.first)];
    }
    cout << ans + res / 2 << endl;
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