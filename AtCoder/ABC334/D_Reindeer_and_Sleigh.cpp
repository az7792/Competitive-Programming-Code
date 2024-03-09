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
    ll n, q;
    cin >> n >> q;
    vector<ll> r(n + 1);
    vector<ll> sum(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> r[i];
    }
    sort(r.begin() + 1, r.end());
    for (int i = 1; i <= n; ++i)
        sum[i] = sum[i - 1] + r[i];
    while (q--)
    {
        ll x;
        cin >> x;
        int p = upper_bound(all(sum), x) - sum.begin();
        cout << p - 1 << endl;
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
