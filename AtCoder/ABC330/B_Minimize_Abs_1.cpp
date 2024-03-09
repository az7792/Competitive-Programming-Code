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
    ll n, l, r;
    cin >> n >> l >> r;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    ll L;
    for (int i = 1; i <= n; ++i)
    {
        if (l <= a[i] && a[i] <= r)
        {
            L = 0;
        }
        else
        {
            L = min(abs(a[i] - l), abs(a[i] - r));
        }
        ll x1 = L + a[i];
        ll x2 = a[i] - L;
        if (l <= x1 && x1 <= r)
            cout << x1 << " ";
        else
            cout << x2 << " ";
    }
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
