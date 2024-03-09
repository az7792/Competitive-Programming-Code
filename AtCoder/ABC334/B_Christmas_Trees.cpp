#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    ll a, m, l, r, k1, k2;
    cin >> a >> m >> l >> r;
    if (r - a >= 0)
        k1 = (r - a) / m;
    else
        k1 = (r - a + (1 - m)) / m;
    if (l - a >= 0)
        k2 = (l - a + m - 1) / m;
    else
        k2 = (l - a) / m;
    cout << (k1 - k2 + 1);
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
